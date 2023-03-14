#include "MQ2.h"

static float r0;
const float k = -2.3;
const float x0 = -0.22;
const float y0 = 4;


MQ2::MQ2 (int _pin) {
    pin = _pin;
}

float MQ2::read_rs () {
    float val = analogRead(pin);
    return (1023.0 - val) / val;
}

float MQ2::get_rs_r0 () {
    float rs = read_rs();
    return rs / r0;
}

void MQ2::calibrate_r0 () {
    float r = 0.0;
    for (int i=0; i<100; i++) {
        r += read_rs(); 
        delay(500);
    }
    r /= 100;
    r0 = r / 9.8;
     
    Serial.print("r:\t");
    Serial.println(r);
    Serial.print("r0:\t");
    Serial.println(r0);
    
}


uint16_t MQ2::get_ppm () {
    float r = get_rs_r0();
    float log_ppm = k * (log(r) - x0) + y0;
    float ppm = powf(10, log_ppm);
   
/*    
    Serial.print("r:\t");
    Serial.println(r);
    Serial.print("log:\t");
    Serial.println(log_ppm);
    Serial.print("ppm:\t");
    Serial.println(ppm);
*/

    return (uint16_t) ppm;
}
