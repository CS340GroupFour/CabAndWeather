#include <string>
#include <vector>
#include <fstream>
#include <sstream>

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

int main()
{
    ifstream myfile;
    //path file might need to be fixed
    myfile.open("cab_rides.csv", ios::in);

    string line;

    std::vector<Cabs> cabRides;

    int lineCount = 0;
    getline(myfile, line); // ignore header line

    Cabs inv;

    while (getline(myfile, line) && !line.empty())
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


}
