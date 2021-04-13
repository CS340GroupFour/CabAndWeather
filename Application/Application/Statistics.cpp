#include "Statistics.h"
#include <math.h>
#include <vector>

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

    double ComputeMean(std::vector<int> data)
    {
        double result = 0.0;

        for (int i = 0; i < data.size(); i++)
        {
            result += data[i];
        }

        result = result / data.size();

        return result;
    }

    double ComputeMean(std::vector<double> data)
    {
        double result = 0.0;

        for (int i = 0; i < data.size(); i++)
        {
            result += data[i];
        }

        result = result / data.size();

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

    double ComputeSTD(std::vector<int> data)
    {
        // STD = sqrt( sum(xi - mean)^2  /  (n-1) )
        double result = 0.0;
        double sum = 0.0;
        double mean = ComputeMean(data);

        for (int i = 0; i < data.size(); i++)
        {
            sum += pow((data[i] - mean), 2);
        }

        result = sqrt(sum / (data.size() - 1.0));

        return result;
    }

    double ComputeSTD(std::vector<double> data)
    {
        // STD = sqrt( sum(xi - mean)^2  /  (n-1) )
        double result = 0.0;
        double sum = 0.0;
        double mean = ComputeMean(data);

        for (int i = 0; i < data.size(); i++)
        {
            sum += pow((data[i] - mean), 2);
        }

        result = sqrt(sum / (data.size() - 1.0));

        return result;
    }

    double ttest(std::vector<double> left, std::vector<double> right)
    {
        // t = ( mean(a) - mean(b) ) / sqrt( (std(a)^2/size(a)) + (std(b)^2/size(b)) )
        double result = 0.0;

        result = (ComputeMean(left) - ComputeMean(right)) / sqrt( (pow(ComputeSTD(left),2)/left.size()) + (pow(ComputeSTD(right), 2) / right.size()) );

        return result;
    }
}