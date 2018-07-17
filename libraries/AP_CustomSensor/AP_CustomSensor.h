/*
 * custom gas sensor
 */

#pragma once

#include <AP_HAL/AP_HAL.h>

class AP_CustomSensor {
public:
    AP_CustomSensor(void);

    void init(void);
    float concentration(void) const { return _concentration; } // gas concentration
    void update(void); // get new value

private:
    float _concentration;
    float R0 = 0.88; //Valor obtenido en laboratorio, ignorando RL.
    AP_HAL::AnalogSource* sensor_analog_source;
};
