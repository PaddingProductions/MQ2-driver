#include "MQ2.h"

MQ2 mq2 (A7);

void setup() {
  Serial.begin(9600);

  Serial.println("Calibrating..");
  mq2.calibrate_r0();

  Serial.println("Starting..");
}

void loop() {
  // put your main code here, to run repeatedly:
  uint16_t val = mq2.get_ppm();
  Serial.println("Val:\t" + val);
  delay (1000);
}
