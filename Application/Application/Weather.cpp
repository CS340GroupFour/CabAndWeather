#include "sortWeather.h"

using namespace std;

namespace sortWeatherComputation {
    void sortWeather(vector<Weather>& weather, vector<Weather>& badWeather, vector<Weather>& goodWeather, string& line1, int& lineCount1) {
        Weather inv1;

        stringstream mystream1(line1);

        string temp1;

        getline(mystream1, temp1, ',');
        if (temp1.empty()) {
            inv1.setTemperature(0.00);
        } else {
            inv1.setTemperature(stod(temp1));
        }

        getline(mystream1, temp1, ',');
        inv1.setLocation(temp1);


        getline(mystream1, temp1, ',');
        if (temp1.empty()) {
            inv1.setClouds(0.000);
        } else {
            inv1.setClouds(stod(temp1));
        }

        getline(mystream1, temp1, ',');
        if (temp1.empty()) {
            inv1.setPressure(0.000);
        } else {
            inv1.setPressure(stod(temp1));
        }

        getline(mystream1, temp1, ',');
        if (temp1.empty()) {
            inv1.setRain(0.000);
        } else {
            inv1.setRain(stod(temp1));
        }

        getline(mystream1, temp1, ',');
        if (temp1.empty()) {
            inv1.setWtime(0);
        } else {
            inv1.setWtime(stod(temp1));
        }

        getline(mystream1, temp1, ',');
        if (temp1.empty()) {
            inv1.setHumidity(0.000);
        } else {
            inv1.setHumidity(stod(temp1));
        }

        getline(mystream1, temp1, ',');
        if (temp1.empty()) {
            inv1.setWind(0.000);
        } else {
            inv1.setWind(stod(temp1));
        }

        int j = 0;
        j = inv1.getWtime()/100;

        inv1.setWtime(j);

        weather.push_back(inv1);
        if (inv1.getRain() <= 0.20) {

            goodWeather.push_back(inv1);
        }
        if (inv1.getRain() > 0.20) {
            badWeather.push_back(inv1);
        }

        lineCount1++;
    }
}
