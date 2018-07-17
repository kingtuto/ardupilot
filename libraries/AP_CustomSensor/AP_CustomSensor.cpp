#include "AP_CustomSensor.h"

#include <utility>
#include <stdio.h>

extern const AP_HAL::HAL &hal;

AP_CustomSensor::AP_CustomSensor() :
    _concentration(0)
{}

void AP_CustomSensor::init()
{
    sensor_analog_source = hal.analogin->channel(15);
}

void AP_CustomSensor::update()
{
    float reading = sensor_analog_source->voltage_latest();
    float Rs = (5-reading)/reading; //Ignorando RL.
    _concentration = 483.07 * powf(Rs/R0, -2.26); //Ecuacion estimada por regresion.
}
