#include <Arduino.h>
#include <driver/adc.h>

class MicReader
{
public:
    MicReader(char pin);
    MicReader(char pin, int resolution, int width, int cycles, int samples, int div, adc_attenuation_t attenuation);

    float readAnalog(void) const;
    float readDB(void) const;

    void setReadResolution(int resolution);
    void setWidth(int width);
    void setCycles(int cycles);
    void setSamples(int samples);
    void setClockDiv(int div);
    void setAttenuation(adc_attenuation_t attenuation);

    int getReadResolution(void) const { return _resolution; }
    int getWidth(void) const { return _width; }
    int getCycles(void) const { return _cycles; }
    int getSamples(void) const { return _samples; }
    int getClockDiv(void) const { return _div; }
    adc_attenuation_t getAttenuation(void) const { return _attenuation; }

    bool busy(void) const { return adcBusy(_pin); }

private:
    char _pin;
    int _resolution;
    int _width;
    int _cycles;
    int _samples;
    int _div;
    adc_attenuation_t _attenuation;
};