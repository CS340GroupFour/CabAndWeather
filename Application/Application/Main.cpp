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


	return 0;
}