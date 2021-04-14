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
    double wtime;
    double humidity;

public:
    const string &getLocation() const;
    void setLocation(const string &location);
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
    double getWtime() const;
    void setWtime(double wtime);
    double getHumidity() const;
    void setHumidity(double humidity);
};


