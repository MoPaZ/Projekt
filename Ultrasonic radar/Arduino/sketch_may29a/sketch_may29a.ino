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

// Variableeessssss
int diff;

void setup() {
  pinMode(LedL2, OUTPUT);
  pinMode(LedL1, OUTPUT);
  pinMode(LedC, OUTPUT);
  pinMode(LedR1, OUTPUT);
  pinMode(LedR2, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  // Ping thoose sonars!!
  unsigned int uS1 = sonar1.ping() / US_ROUNDTRIP_CM;      // Ping sensor left
  delay(50);                                               // Delay for interference
  unsigned int uS2 = sonar2.ping() / US_ROUNDTRIP_CM;      // Ping sensor right
  delay(50);                                               // Funny delay
  
  // Calculating stuff
  diff = uS1-uS2;

  // Serial stuff
  Serial.print(uS1);
  Serial.print(" ");
  Serial.print(uS2);
  Serial.print(" ");
  Serial.println(diff);

}
