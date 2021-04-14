#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Cabs{
protected:
    string citySource;
    string cityDest;
    string cabBrand;
    string cabType;
    string identifier;
    string prod_id;
    double surgeMultiplier;
public:
    const string &getCitySource() const;

    void setCitySource(const string &citySource);

    const string &getCityDest() const;

    void setCityDest(const string &cityDest);

    const string &getCabBrand() const;

    void setCabBrand(const string &cabBrand);

    const string &getCabType() const;

    void setCabType(const string &cabType);

    const string &getIdentifier() const;

    void setIdentifier(const string &identifier);

    const string &getProdId() const;

    void setProdId(const string &prodId);

    double getSurgeMultiplier() const;

    void setSurgeMultiplier(double surgeMultiplier);

    double getTime() const;

    void setTime(double time);

    double getDistance() const;

    void setDistance(double distance);

    double getPrice() const;

    void setPrice(double price);

protected:
    double time;
    double distance;
    double price;

    void cabAtts();

public:
    void sortCab ();

};
void Cabs::cabAtts() {
    citySource = "";
    cityDest= "";
    cabBrand= "";
    cabType= "";
    identifier= "";
    prod_id= "";
    surgeMultiplier = 0.00;
    time = 0.00;
    distance = 0.00;
    price = 0.00;
}
void Cabs::sortCab() {

    cabAtts();
    ifstream myfile1;
    myfile1.open("cab_rides.csv", ios::in);

    string line;

    std::vector<Cabs> cabRides;
    std::vector<Cabs> onlyUber;
    std::vector<Cabs> onlyLyft;

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

const string &Cabs::getCitySource() const {
    return citySource;
}

void Cabs::setCitySource(const string &citySource) {
    Cabs::citySource = citySource;
}

const string &Cabs::getCityDest() const {
    return cityDest;
}

void Cabs::setCityDest(const string &cityDest) {
    Cabs::cityDest = cityDest;
}

const string &Cabs::getCabBrand() const {
    return cabBrand;
}

void Cabs::setCabBrand(const string &cabBrand) {
    Cabs::cabBrand = cabBrand;
}

const string &Cabs::getCabType() const {
    return cabType;
}

void Cabs::setCabType(const string &cabType) {
    Cabs::cabType = cabType;
}

const string &Cabs::getIdentifier() const {
    return identifier;
}

void Cabs::setIdentifier(const string &identifier) {
    Cabs::identifier = identifier;
}

const string &Cabs::getProdId() const {
    return prod_id;
}

void Cabs::setProdId(const string &prodId) {
    prod_id = prodId;
}

double Cabs::getSurgeMultiplier() const {
    return surgeMultiplier;
}

void Cabs::setSurgeMultiplier(double surgeMultiplier) {
    Cabs::surgeMultiplier = surgeMultiplier;
}

double Cabs::getTime() const {
    return time;
}

void Cabs::setTime(double time) {
    Cabs::time = time;
}

double Cabs::getDistance() const {
    return distance;
}

void Cabs::setDistance(double distance) {
    Cabs::distance = distance;
}

double Cabs::getPrice() const {
    return price;
}

void Cabs::setPrice(double price) {
    Cabs::price = price;
}
