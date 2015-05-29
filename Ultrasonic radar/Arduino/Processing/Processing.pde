import processing.serial.*;

Serial myPort;
int xPos = 1;

float[] left;
float[] right;
float leftOutput;
float rightOutput;
int i = 0;

boolean gotInput;

float[] coff;
float diff;

void setup() {
  size(1024, 960);  
  println(Serial.list()); 
  myPort = new Serial(this, Serial.list()[1], 9600);
  myPort.bufferUntil('\n');
  background(0);

  left = new float[4];
  right = new float[4];
  coff = new float[4];
  coff[0] = 0.25;
  coff[1] = 0.25;
  coff[2] = 0.25;
  coff[3] = 0.25;

  gotInput = false;
}

void draw() {
  if (gotInput) {
    gotInput = false;

    // Filtrera datt shitt
    leftOutput = coff[0]*left[0] + coff[1]*left[1] + coff[2]*left[2] + coff[3]*left[3];
    rightOutput = coff[0]*right[0] + coff[1]*right[1] + coff[2]*right[2] + coff[3]*right[3];
    
    // Calculate diff
    diff = rightOutput - leftOutput;

    // Rita datt shit
    stroke(255, 0, 0);
    line(xPos, height, xPos, height - leftOutput);
    stroke(255,255,0);
    line(xPos, 0, xPos, diff+200);
    xPos++;
    stroke(0, 0, 255);
    line(xPos, height, xPos, height - rightOutput);
    stroke(255,255,0);
    line(xPos, 0, xPos, diff+200);

    // Flytta arrayen änna
    left[3] = left[2];
    left[2] = left[1];
    left[1] = left[0];
    right[3] = right[2];
    right[2] = right[1];
    right[1] = right[0];

    if (xPos >= width) {
      xPos = 0;
      background(0);
    } else {
      xPos++;
    }
  }
}


void serialEvent (Serial myPort) {

  String inString = myPort.readStringUntil('\n');

  if (inString != null) {
    // Trimma och splitta input
    inString = trim(inString);   
    String[] split = splitTokens(inString);

    // Plocka ut värderna
    left[0] = float(split[0]);
    left[0] = map(left[0], 0, 200, 0, height);
    right[0] = float(split[1]);
    right[0] = map(right[0], 0, 200, 0, height);
    
    gotInput = true;
  }
}

