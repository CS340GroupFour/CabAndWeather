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
    double time;
    double distance;
    double price;

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
};

