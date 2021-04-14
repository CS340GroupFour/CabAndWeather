#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Weather{
protected:
    string location;
    double clouds;
    double pressure;
    double wind;
    double temperature;
    double rain;
    long int wtime;
    double humidity;

public:
    const string &getLocation() const;
    void setLocation(const string &locatin);
    double getClouds() const;
    void setClouds(double clouds);
    double getPressure() const;
    void setPressure(double pressure);
    double getWind() const;
    void setWind(double wind);
    double getTemperature() const;
    void setTemperature(double temperature);
    double getRain() const;
    void setRain(double rain);
    long int getWtime() const;
    void setWtime(long int wtime);
    double getHumidity() const;
    void setHumidity(double humidity);
};

