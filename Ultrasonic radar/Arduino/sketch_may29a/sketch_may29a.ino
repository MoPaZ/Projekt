#include <NewPing.h>

#define TRIGGER_PIN1 7
#define ECHO_PIN1 6
#define TRIGGER_PIN2 4
#define ECHO_PIN2 3

#define MAX_DISTANCE 200

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int uS1 = sonar1.ping();
  delay(50);
  unsigned int uS2 = sonar2.ping();
//  Serial.print("Ping1: ");
//  Serial.print(uS1 / US_ROUNDTRIP_CM);
//  Serial.println("cm");
  delay(50);
  Serial.print(uS1 / US_ROUNDTRIP_CM);
  Serial.print(" ");
  Serial.println(uS2 / US_ROUNDTRIP_CM);
  
  
  //unsigned int uS2 = sonar2.ping();
//  Serial.print("Ping2: ");
//  Serial.print(uS2 / US_ROUNDTRIP_CM);
//  Serial.println("cm");
  
  }
