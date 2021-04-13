#ifndef STATISTICS_H
#define STATISTICS_H

namespace Statistics
{
    double ComputeMean(int data[], int size);
    double ComputeMean(double data[], int size);
    double ComputeSTD(double data[], int size);
    double ComputeSTD(int data[], int size);
};

    // Below are the code example for testing:
    
	// double dataA[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
    // int dataB[] = { 1,2,3,4,5,6,7,8,9,10 };

    // std::cout << "-------------- This is a Unit test for Statistics --------------" << std::endl;
	// std::cout << "Your data A are: " << "1.0,2.0,3.0,...,10.0" << std::endl;
	// std::cout << "Your data B are: " << "1,2,3,...,10" << std::endl;
    // std::cout << "Mean of A: " << Statistics::ComputeMean(dataA, sizeof(dataA) / sizeof(dataA[0])) << std::endl;
    // std::cout << "Mean of B: " << Statistics::ComputeMean(dataB, sizeof(dataB) / sizeof(dataB[0])) << std::endl;
    // std::cout << "STD of A: " << Statistics::ComputeSTD(dataA, sizeof(dataA) / sizeof(dataA[0])) << std::endl;
    // std::cout << "STD of B: " << Statistics::ComputeSTD(dataB, sizeof(dataB) / sizeof(dataB[0])) << std::endl;

    // std::cout << "-------------- End of Unit test --------------" << std::endl;

#endif