#include <NewPing.h>

// Define sonar pins
#define TRIGGER_PIN1 7
#define ECHO_PIN1 6
#define TRIGGER_PIN2 4
#define ECHO_PIN2 3
#define MAX_DISTANCE 200

// Define led pins
#define LedL2 12
#define LedL1 11
#define LedC 10
#define LedR1 9
#define LedR2 8

// Init sonar objects
NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

// Hej jerry

int input;

void setup() {
  pinMode(LedL2, OUTPUT);
  pinMode(LedL1, OUTPUT);
  pinMode(LedC, OUTPUT);
  pinMode(LedR1, OUTPUT);
  pinMode(LedR2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Get serial ORDERS
  if (Serial.available()) {
    input = Serial.read();
    if (input == '1') {
      digitalWrite(LedR2, HIGH);
    } else {
      digitalWrite(LedR2, LOW);
    }
    if (input == '2') {
      digitalWrite(LedR1, HIGH);
    } else {
      digitalWrite(LedR1, LOW);
    }
    if (input == '3') {
      digitalWrite(LedC, HIGH);
    } else {
      digitalWrite(LedC, LOW);
    }
    if (input == '4') {
      digitalWrite(LedL1, HIGH);
    } else {
      digitalWrite(LedL1, LOW);
    }
    if (input == '5') {
      digitalWrite(LedL2, HIGH);
    } else {
      digitalWrite(LedL2, LOW);
    }
  }

  // Ping thoose sonars!!
  unsigned int uS1 = sonar1.ping() / US_ROUNDTRIP_CM;      // Ping sensor left
  delay(100);                                               // Delay for interference
  unsigned int uS2 = sonar2.ping() / US_ROUNDTRIP_CM;      // Ping sensor right
  delay(100);                                               // Funny delay


  // Serial stuff
  Serial.print(uS1);
  Serial.print(" ");
  Serial.println(uS2);


}
