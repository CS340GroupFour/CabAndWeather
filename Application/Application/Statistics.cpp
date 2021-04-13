#include "Statistics.h"
#include <math.h>
namespace Statistics
{
    double ComputeMean(int data[], int size)
    {
        double result = 0.0;

        for (int i = 0; i < size; i++)
        {
            result += data[i];
        }

        result = result / size;

        return result;
    }
    double ComputeMean(double data[], int size)
    {
        double result = 0.0;

        for (int i = 0; i < size; i++)
        {
            result += data[i];
        }

        result = result / size;

        return result;
    }

    double ComputeSTD(double data[], int size)
    {
        // STD = sqrt( sum(xi - mean)^2  /  (n-1) )
        double result = 0.0;
        double sum = 0.0;
        double mean = ComputeMean(data, size);

        for (int i = 0; i < size; i++)
        {
            sum += pow((data[i] - mean), 2);
        }

        result = sqrt(sum / (size - 1.0));

        return result;
    }

    double ComputeSTD(int data[], int size)
    {
        // STD = sqrt( sum(xi - mean)^2  /  (n-1) )
        double result = 0.0;
        double sum = 0.0;
        double mean = ComputeMean(data, size);

        for (int i = 0; i < size; i++)
        {
            sum += pow((data[i] - mean), 2);
        }

        result = sqrt(sum / (size - 1.0));

        return result;
    }
}