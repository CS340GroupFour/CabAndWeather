#include "cabAndWeather.h"

double cabAndWeather::getXtimes() const {
    return xtimes;
}

void cabAndWeather::setXtimes(double xtimes) {
    cabAndWeather::xtimes = xtimes;
}

double cabAndWeather::getXrain() const {
    return xrain;
}

void cabAndWeather::setXrain(double xrain) {
    cabAndWeather::xrain = xrain;
}

double cabAndWeather::getXprice() const {
    return xprice;
}

void cabAndWeather::setXprice(double xprice) {
    cabAndWeather::xprice = xprice;
}

const string &cabAndWeather::getXcabBrand() const {
    return xcabBrand;
}

void cabAndWeather::setXcabBrand(const string &xcabBrand) {
    cabAndWeather::xcabBrand = xcabBrand;
}

const string &cabAndWeather::getXcabType() const {
    return xcabType;
}

void cabAndWeather::setXcabType(const string &xcabType) {
    cabAndWeather::xcabType = xcabType;
}

const string &cabAndWeather::getSourceLocation() const {
    return sourceLocation;
}

void cabAndWeather::setSourceLocation(const string &sourceLocation) {
    cabAndWeather::sourceLocation = sourceLocation;
}
