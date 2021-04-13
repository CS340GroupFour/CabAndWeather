#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>

namespace Statistics
{
    double ComputeMean(int data[], int size);
    double ComputeMean(double data[], int size);
    double ComputeMean(std::vector<int> data);
    double ComputeMean(std::vector<double> data);
    double ComputeSTD(double data[], int size);
    double ComputeSTD(int data[], int size);
    double ComputeSTD(std::vector<int> data);
    double ComputeSTD(std::vector<double> data);
    double Ttest(std::vector<double> left, std::vector<double> right);
};

    // Below are the code example for testing:
    
	// double dataA[] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0 };
    // int dataB[] = { 1,2,3,4,5,6,7,8,9,10 };
	// std::vector<int> dataC;
	// std::vector<double> dataD;

	// for(int i = 0; i<10; i++)
	// {
	// 	dataC.push_back(i+1);
	// 	dataD.push_back(i+1.0);
	// }

    // std::cout << "-------------- This is a Unit test for Statistics --------------" << std::endl;
	// std::cout << "Your array A are: " << "1.0,2.0,3.0,...,10.0" << std::endl;
	// std::cout << "Your array B are: " << "1,2,3,...,10" << std::endl;
	// std::cout << "Your vector C are: " << "1,2,3,...,10" << std::endl;
	// std::cout << "Your vector D are: " << "1.0,2.0,3.0,...,10.0" << std::endl;
    // std::cout << "Mean of array A: " << Statistics::ComputeMean(dataA, sizeof(dataA) / sizeof(dataA[0])) << std::endl;
    // std::cout << "Mean of array B: " << Statistics::ComputeMean(dataB, sizeof(dataB) / sizeof(dataB[0])) << std::endl;
	// std::cout << "Mean of vector C: " << Statistics::ComputeMean(dataC) << std::endl;
	// std::cout << "Mean of vector D: " << Statistics::ComputeMean(dataD) << std::endl;

    // std::cout << "STD of array A: " << Statistics::ComputeSTD(dataA, sizeof(dataA) / sizeof(dataA[0])) << std::endl;
    // std::cout << "STD of array B: " << Statistics::ComputeSTD(dataB, sizeof(dataB) / sizeof(dataB[0])) << std::endl;
	// std::cout << "STD of vector C: " << Statistics::ComputeSTD(dataC) << std::endl;
	// std::cout << "STD of vector D: " << Statistics::ComputeSTD(dataD) << std::endl;

    // std::cout << "-------------- End of Unit test --------------" << std::endl;

#endif