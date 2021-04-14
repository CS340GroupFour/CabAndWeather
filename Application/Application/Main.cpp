#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

struct Cabs{
    string citySource;
    string cityDest;
    string cabBrand;
    string cabType;
    string identifier;
    string prod_id;
    double surgeMultiplier;
    double time;
    double distance;
    double price;
};

struct Weather{
    string location;
    double clouds;
    double pressure;
    double wind;
    double temperature;
    double rain;
    double time;
    double humidity;
};

int main()
{
    ifstream myfile1;
    myfile1.open("cab_rides.csv", ios::in);

    string line;

    std::vector<Cabs> cabRides;

    int lineCount = 0;
    getline(myfile1, line); // ignore header line

    Cabs inv;

    while (getline(myfile1, line) && !line.empty())
    {
        stringstream mystream(line);

        string temp;


        getline(mystream, temp, ',');
        if(temp.empty()){
            temp = 0.000;
        }
        else{
            inv.distance = stod(temp);
        }

        getline(mystream, inv.cabBrand, ',');

        getline(mystream, temp, ',');
        if(temp.empty()){
            inv.time = 0.000;
        }
        else {
            inv.time = stod(temp);
        }


        getline(mystream, inv.cityDest, ',');
        getline(mystream, inv.citySource, ',');

        getline(mystream, temp, ',');
        if(temp.empty()){
            inv.price = 0.000;
        }
        else {
            inv.price = stod(temp);
        }

        getline(mystream, temp, ',');
        if(temp.empty()){
            inv.surgeMultiplier = 0.000;
        }
        else {
            inv.surgeMultiplier = stod(temp);
        }

        getline(mystream, inv.identifier, ',');
        getline(mystream, inv.prod_id, ',');
        getline(mystream, inv.cabType, ',');


        if (!mystream)
            break;

        cabRides.push_back(inv);
        lineCount++;
    }

    std::vector<Cabs> onlyUber;

    for(int i = 0; i < cabRides.size(); i++){

    }

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
            inv1.time = 0.000;
        }
        else {
            inv1.time = stod(temp1);
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
