#include "Cabs.h"

void Cabs::sortCab(vector<Cabs> cabRides, vector<Cabs> onlyUber, vector<Cabs> onlyLyft) {

    cabAtts();
    ifstream myfile1;
    myfile1.open("cab_rides.csv", ios::in);

    string line;

    int lineCount = 0;
    getline(myfile1, line); // ignore header line

    Cabs inv;

    while (getline(myfile1, line) && !line.empty()) {
        stringstream mystream(line);

        string temp;


        getline(mystream, temp, ',');
        if (temp.empty()) {
            temp = 0.000;
        } else {
            inv.distance = stod(temp);
        }

        getline(mystream, inv.cabBrand, ',');

        getline(mystream, temp, ',');
        if (temp.empty()) {
            inv.time = 0.000;
        } else {
            inv.time = stod(temp);
        }


        getline(mystream, inv.cityDest, ',');
        getline(mystream, inv.citySource, ',');

        getline(mystream, temp, ',');
        if (temp.empty()) {
            inv.price = 0.000;
        } else {
            inv.price = stod(temp);
        }

        getline(mystream, temp, ',');
        if (temp.empty()) {
            inv.surgeMultiplier = 0.000;
        } else {
            inv.surgeMultiplier = stod(temp);
        }

        getline(mystream, inv.identifier, ',');
        getline(mystream, inv.prod_id, ',');
        getline(mystream, inv.cabType, ',');


        if (!mystream) {
            break;
        }

        cabRides.push_back(inv);
        if (inv.cabBrand == "Lyft") {
            onlyLyft.push_back(inv);
        }
        if (inv.cabBrand == "Uber") {
            onlyUber.push_back(inv);
        }


        lineCount++;
    }
}