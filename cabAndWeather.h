#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>


using namespace std;

class cabAndWeather {
protected:
    double xtimes;
    double xrain;
    double xprice;
    string xcabBrand;
    string xcabType;
    string sourceLocation;

public:
    double getXtimes() const;
    void setXtimes(double xtimes);
    double getXrain() const;
    void setXrain(double xrain);
    double getXprice() const;
    void setXprice(double xprice);
    const string &getXcabBrand() const;
    void setXcabBrand(const string &xcabBrand);
    const string &getXcabType() const;
    void setXcabType(const string &xcabType);
    const string &getSourceLocation() const;
    void setSourceLocation(const string &sourceLocation);
};
