#include <iostream>
#include <fstream> //read and save to file
#include <string>


int main()
{
	std::string cabRidePath = "./Data/cab_rides.txt";
	std::string weatherPath = "./Data/weather.txt";

	std::fstream cabRideStream;
	std::fstream weatherStream;

	std::string linestr; // Used to temporary store data from stream.

	weatherStream.open(weatherPath);
	cabRideStream.open(cabRidePath);
	
	if (weatherStream.fail())  
	{
		std::cerr << "Failed to open the file: " << weatherPath << std::endl;
		return(-1);
	}

	std::cout << "Success on opening the file: " << weatherPath << std::endl;

	if (cabRideStream.fail())
	{
		std::cerr << "Failed to open the file: " << cabRideStream.fail() << std::endl;
		return(-1);
	}
	std::cout << "Success on opening the file: " << cabRidePath << std::endl;
	
	/*
	string cabPath;
	string weatherPath;	

	fstream cabStream;
	fstream weatherStream;

	cabStream.open(cabPath);
	weatherStream.open(weatherPath);

	if(cabStream.fail()) { // print fail message }
	if(weatherStream.fail()) { // print fail message }

	// parse to object. Question: sequential or random access?
	CabRide[] cabRideArray;
	Weather[] weatherArray;
	
	while(cabStream) { line => cabRideArray.pushback( CabRide() ) }
	while(weatherStream) { line => cabRideArray.pushback( Weather() ) }
	
	// Preparation
	// Maybe sort weatherArray by time_stamp
	
	// Connect data sets (Cab and Weather)
	foreach(Cab) {
		weatherArray.findClosestTimeStamp(cabStream.time_stamp AND Location/Destination); // TODO: find the
	}

	// Application interface
	cout << "Welcome to Cab and Weather" << endl;
	cout << "Menu:" << endl;
	cout << "a - Data result" << endl;
	cout << "b - Average sample for ___" << endl;
	cout << "c - Sample STD for ___" << endl;
	cout << "exit - Terminate program" << endl;
	
	string userInput
	do
	{
		cin >> input;
		perform(input);
	}while(input != "exit")
}

void perform(string input)
{
	if(input == "a")
	{
		// Do operation here
	}
	.
	.
	.
	else
	{
		cout << "Command not found." << endl;
	}
}



class SampleCollection
{
	public:
		Add(Sample);
		GetAvg();
		GetAvg(...);
		GetSTD();
		GetSTD(...);
		.
		.
		.
	private:
		Sample sample;
}

struct Sample
{
	Weather weather;
	CabRide cabRide;
}

struct Weather
{
	unsigned int time_stamp;
	Location location;
	.
	.
	.
}

struct CabRide
{
	unsigned int time_stamp;
	Location source;
	Location destination;
	.
	.
	.
}

enum Location
{
}
	*/


	return 0;
}
