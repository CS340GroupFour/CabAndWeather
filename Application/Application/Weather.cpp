#include "Weather.h"

const string &Weather::getLocation() const {
    return location;
}

void Weather::setLocation(const string &location) {
    Weather::location = location;
}

double Weather::getClouds() const {
    return clouds;
}

void Weather::setClouds(double clouds) {
    Weather::clouds = clouds;
}

double Weather::getPressure() const {
    return pressure;
}

void Weather::setPressure(double pressure) {
    Weather::pressure = pressure;
}

double Weather::getWind() const {
    return wind;
}

void Weather::setWind(double wind) {
    Weather::wind = wind;
}

double Weather::getTemperature() const {
    return temperature;
}

void Weather::setTemperature(double temperature) {
    Weather::temperature = temperature;
}

double Weather::getRain() const {
    return rain;
}

void Weather::setRain(double rain) {
    Weather::rain = rain;
}

double Weather::getWtime() const {
    return wtime;
}

void Weather::setWtime(double wtime) {
    Weather::wtime = wtime;
}

double Weather::getHumidity() const {
    return humidity;
}

void Weather::setHumidity(double humidity) {
    Weather::humidity = humidity;
}