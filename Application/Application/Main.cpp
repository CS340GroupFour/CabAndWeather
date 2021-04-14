#include "sortWeather.h"
#include "sortCab.h"
#include "cabAndWeather.h"
#include <string>
#include <vector>
#include <iostream>

ostream & operator<< (ostream& out, const Cabs& c) {
    out << c.getDistance() << " " << c.getTime() << " " << c.getCabBrand() << " " << c.getCityDest() << "" << c.getCitySource() <<
    " " << c.getPrice() << " " << c.getSurgeMultiplier() << " " << c.getIdentifier() << " " << c.getProdId() <<
    " " << c.getCabType() << endl;
    return out;
}
ostream & operator<< (ostream& out, const Weather& w) {
    out << w.getTemperature() << " " << w.getLocation() << " " << w.getClouds() << " " << w.getPressure() <<
    " " << w.getRain() << " " << w.getWtime() << " " << w.getHumidity() << " " << w.getWind() << endl;
    return out;
}
ostream & operator<< (ostream& out, const cabAndWeather& x) {
    out << x.getXtimes() << " " << x.getSourceLocation() << " " << x.getXcabBrand() << " " << x.getXcabType() <<
        " " << x.getXrain() << " " << x.getXprice() << endl;
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
void xcabWeatherIter(vector<cabAndWeather> const &a ){
    cout << "Cabs And Weather " << endl;

    for(const auto & i : a){
        cout << i << endl;
    }
}

void getCab(vector<Cabs>& cabRides, vector<Cabs>& onlyUber, vector<Cabs>& onlyLyft){
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
}
void getWeather(vector<Weather>& weather, vector<Weather>& badWeather, vector<Weather>& goodWeather){
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
}
void fusionCabWeather(vector<Cabs>& cabV, vector<Weather>& weatherV, vector<cabAndWeather>& cabXweather){
    cabAndWeather collX;

    for(int i = 0; i < cabV.size(); i++){
        for(int j = 0; j < weatherV.size(); j++){
            if(cabV[i].getTime() == weatherV[j].getWtime()
               && cabV[i].getCitySource() == weatherV[j].getLocation()){
                collX.setXcabType(cabV[i].getCabType());
                collX.setXcabBrand(cabV[i].getCabBrand());
                collX.setXprice(cabV[i].getPrice());
                collX.setXrain(weatherV[j].getRain());
                collX.setXtimes(weatherV[j].getWtime());
                collX.setSourceLocation(weatherV[j].getLocation());

                cabXweather.push_back(collX);
            }
        }
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
    std::vector<cabAndWeather> xCabAndWeather;

    getCab(cabRides, onlyUber, onlyLyft);
    getWeather(weather, badWeather, goodWeather);
    //
    //FIXME: Depends on user input - must fix based on case
    // fusionCabWeather();


    //cabIter(cabRides);
    //weatherIter(weather);
    //xcabWeatherIter(xCabAndWeather);

}
