#include "MicReader.h"

MicReader::MicReader(char pin)
{
    _pin = pin;
    adcAttachPin(_pin);
}
MicReader::MicReader(char pin, int resolution, int width, int cycles, int samples, int div, adc_attenuation_t attenuation)
{
    _pin = pin;
    _resolution = resolution;
    _width = width;
    _cycles = cycles;
    _samples = samples;
    _div = div;
    _attenuation = _attenuation;
}
float MicReader::readAnalog(void) const
{
    return analogRead(_pin);
}
float MicReader::readDB(void) const
{
    /* TODO: add correct conversion to obtain db */
    return (float)(analogRead(_pin) + 83.2073) / 14.003;
}
void MicReader::setReadResolution(int resolution)
{
    _resolution = resolution;
    analogReadResolution(_resolution);
}
void MicReader::setWidth(int width)
{
    _width = width;
    analogSetWidth(_width);
}
void MicReader::setCycles(int cycles)
{
    _cycles = cycles;
    analogSetCycles(_cycles);
}
void MicReader::setSamples(int samples)
{
    _samples = samples;
    analogSetSamples(_samples);
}
void MicReader::setClockDiv(int div)
{
    _div = div;
    analogSetClockDiv(_div);
}
void MicReader::setAttenuation(adc_attenuation_t attenuation)
{
    _attenuation = _attenuation;
    analogSetAttenuation(_attenuation);
}