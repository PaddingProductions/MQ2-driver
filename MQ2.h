#ifndef MQ2_H
#define MQ2_H

#include <Arduino.h>

class MQ2 {
private:
    int pin;
    float read_rs();
    float get_rs_r0();
public:
    MQ2 (int _pin); 
    void calibrate_r0 ();
    uint16_t get_ppm ();
};
#endif
