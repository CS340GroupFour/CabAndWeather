#include "Cabs.h"

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
