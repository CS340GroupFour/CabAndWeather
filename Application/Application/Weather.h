#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Weather{
protected:
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

protected:
    string location;
    double clouds;
    double pressure;
    double wind;
    double temperature;
    double rain;
    double wtime;
    double humidity;

    void weatherAtts();

public:
    void sortWeather();
};
void Weather::weatherAtts() {
    location = "";
    clouds = 0.00;
    pressure = 0.00;
    wind = 0.00;
    temperature = 0.00;
    rain = 0.00;
    wtime = 0.00;
    humidity = 0.00;
}
void Weather::sortWeather() {
    weatherAtts();
    ifstream myfile2;
    myfile2.open("weather.csv", ios::in);

    string line1;

    std::vector<Weather> weather;

    int lineCount1 = 0;
    getline(myfile2, line1); // ignore header line

    Weather inv1;

    while (getline(myfile2, line1) && !line1.empty())
    {
        stringstream mystream1(line1);

        string temp1;

        getline(mystream1, temp1, ',');
        if(temp1.empty()){
            inv1.temperature = 0.000;
        }
        else{
            inv1.temperature = stod(temp1);
        }

        getline(mystream1, inv1.location, ',');

        getline(mystream1, temp1, ',');
        if(temp1.empty()){
            inv1.clouds = 0.000;
        }
        else {
            inv1.clouds = stod(temp1);
        }

        getline(mystream1, temp1, ',');
        if(temp1.empty()){
            inv1.pressure = 0.000;
        }
        else {
            inv1.pressure = stod(temp1);
        }

        getline(mystream1, temp1, ',');
        if(temp1.empty()){
            inv1.rain = 0.000;
        }
        else {
            inv1.rain = stod(temp1);
        }

        getline(mystream1, temp1, ',');
        if(temp1.empty()){
            inv1.wtime = 0.000;
        }
        else {
            inv1.wtime = stod(temp1);
        }

        getline(mystream1, temp1, ',');
        if(temp1.empty()){
            inv1.humidity = 0.000;
        }
        else {
            inv1.humidity = stod(temp1);
        }

        getline(mystream1, temp1, ',');
        if(temp1.empty()){
            inv1.wind = 0.000;
        }
        else {
            inv1.wind = stod(temp1);
        }

        if (!mystream1)
            break;

        weather.push_back(inv1);
        lineCount1++;
    }

}

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
