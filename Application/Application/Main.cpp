#include "Cabs.h"
#include "Weather.h"
ostream & operator<<(ostream& out, const Cabs& c) {
    out << c.getDistance() << " " << c.getCabBrand() << "" << c.getCityDest() << "" << c.getCitySource() <<
    " " << c.getPrice() << " " << c.getSurgeMultiplier() << " " << c.getIdentifier() << " " << c.getProdId() <<
    " " << c.getCabType() << endl;
    //copy(c..begin(), p.phones.end(), ostream_iterator<string>(out, " "));
    return out;
}
void cabIter(vector<Cabs> const &a ){
    cout << "Uber Price: " << endl;

    for(const auto & i : a){
        cout << i << endl;
    }
}
int main()
{
    std::vector<Cabs> cabRides;
    std::vector<Cabs> onlyUber;
    std::vector<Cabs> onlyLyft;

    Cabs objCab;
    objCab.sortCab(cabRides, onlyUber, onlyLyft);

    cabIter(cabRides);

}
