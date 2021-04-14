#include "sortWeather.h"
#include "sortCab.h"
#include <string>
#include <vector>
#include <iostream>

ostream & operator<< (ostream& out, const Cabs& c) {
    out << c.getDistance() << " " << c.getCabBrand() << " " << c.getCityDest() << "" << c.getCitySource() <<
    " " << c.getPrice() << " " << c.getSurgeMultiplier() << " " << c.getIdentifier() << " " << c.getProdId() <<
    " " << c.getCabType() << endl;
    return out;
}
ostream & operator<< (ostream& out, const Weather& w) {
    out << w.getTemperature() << " " << w.getLocation() << " " << w.getClouds() << " " << w.getPressure() <<
    " " << w.getRain() << " " << w.getWtime() << " " << w.getHumidity() << " " << w.getWind() << endl;
    return out;
}
void cabIter(vector<Cabs> const &a ){
    cout << "Uber Price: " << endl;

    for(const auto & i : a){
        cout << i << endl;
    }
}
void weatherIter(vector<Weather> const &a ){
    cout << "Weather: " << endl;

    for(const auto & i : a){
        cout << i << endl;
    }
}

int main()
{
    std::vector<Cabs> cabRides;
    std::vector<Cabs> onlyUber;
    std::vector<Cabs> onlyLyft;
    std::vector<Weather> weather;
    std::vector<Weather> badWeather;
    std::vector<Weather> goodWeather;

    ifstream myfile1;
    myfile1.open("..\\cab_rides.csv", ios::in);
    if(!myfile1.is_open()){
        cout << "You're a failure";
    }
    string line;

    int lineCount = 0;
    getline(myfile1, line); // ignore header line

    while (getline(myfile1, line) && !line.empty()) {
        sortCabComputation::sortCab(cabRides, onlyUber, onlyLyft, line, lineCount);
    }

    ifstream myfile2;
    myfile2.open("..\\weather.csv", ios::in);
    if(!myfile2.is_open()){
        cout << "You're a failure";
    }
    string line1;

    int lineCount1 = 0;
    getline(myfile2, line1); // ignore header line

    while (getline(myfile2, line1) && !line1.empty()) {
        sortWeatherComputation::sortWeather(weather, badWeather, goodWeather, line1, lineCount1);
    }

    //cabIter(cabRides);
    //cabIter(onlyUber);
    //weatherIter(badWeather);
}
