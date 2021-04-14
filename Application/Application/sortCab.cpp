#include "sortCab.h"

using namespace std;

namespace sortCabComputation{
    void sortCab(vector<Cabs>& cabRides, vector<Cabs>& onlyUber, vector<Cabs>& onlyLyft, string& line, int& lineCount) {
            Cabs inv;

            stringstream mystream(line);

            string temp;


            getline(mystream, temp, ',');
            if (temp.empty()) {
                inv.setDistance(0.00);
            } else {
                inv.setDistance(stod(temp));
            }

            getline(mystream, temp, ',');
            inv.setCabBrand(temp);

            getline(mystream, temp, ',');
            if (temp.empty()) {
                inv.setTime(0.00);
            } else {
                inv.setTime(stod(temp));
            }


            getline(mystream, temp, ',');
            inv.setCityDest(temp);
            getline(mystream, temp, ',');
            inv.setCitySource(temp);


            getline(mystream, temp, ',');
            if (temp.empty()) {
                inv.setPrice(0.00);
            } else {
                inv.setPrice(stod(temp));
            }

            getline(mystream, temp, ',');
            if (temp.empty()) {
                inv.setSurgeMultiplier(0.00);
            } else {
                inv.setSurgeMultiplier(stod(temp));
            }

            getline(mystream, temp, ',');
            inv.setIdentifier(temp);

            getline(mystream, temp, ',');
            inv.setProdId(temp);
            getline(mystream, temp, ',');
            inv.setCabType(temp);

            cabRides.push_back(inv);
            if (inv.getCabBrand() == "Lyft") {
                onlyLyft.push_back(inv);
            }
            if (inv.getCabBrand() == "Uber") {
                onlyUber.push_back(inv);
            }

            lineCount++;
        }
}

