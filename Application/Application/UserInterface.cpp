#include <string>
#include <iostream>
#include <vector>
#include "UserInterface.h"
#include "Statistics.h"


UserInterface::UserInterface()
{
    introOptions=
            "1 - Introduction\n"
            "2 - Learn about T test\n"
            "3 - Perform calculation on sample\n"
            "4 - About us\n"
            "q - Quit\n";

    sampleOptions=
            "1 - Full sample\n"
            "2 - Uber sample\n"
            "3 - Lyft sample\n"
            "4 - Good weather sample\n"
            "5 - Bad weather sample\n"
            "q - Quit\n";

    mathOptions =
            "1 - Single sample\n"
            "2 - 2 sample T-test\n"
            "q - Quit\n";

    mainMenuOrExit =
            "1 - Main Menu\n"
            "q - Quit\n";

    userOperation = MathOperation::None;
    firstOption = DataSample::Empty;
    secondOption = DataSample::Empty;
}

UserInterface::UserInterface(std::vector<Cabs>& fullData, std::vector<Cabs>& uber, std::vector<Cabs>& lyft, std::vector<cabAndWeather>& niceWeather, std::vector<cabAndWeather>& badWeather)
{
    introOptions=
            "1 - Introduction\n"
            "2 - Learn about T test\n"
            "3 - Perform calculation on sample\n"
            "4 - About us\n"
            "q - Quit\n";

    sampleOptions=
            "1 - Full sample\n"
            "2 - Uber sample\n"
            "3 - Lyft sample\n"
            "4 - Good weather sample\n"
            "5 - Bad weather sample\n"
            "q - Quit\n";

    mathOptions =
            "1 - Single sample\n"
            "2 - 2 sample T-test\n"
            "q - Quit\n";

    mainMenuOrExit =
            "1 - Main Menu\n"
            "q - Quit\n";

    userOperation = MathOperation::None;
    firstOption = DataSample::Empty;
    secondOption = DataSample::Empty;

    ConvertData(fullData, fullDataPrice, fullDataDistance);
    ConvertData(uber, uberDataPrice, uberDataDistance);
    ConvertData(lyft, lyftDataPrice, lyftDataDistance);
    ConvertData(niceWeather, niceWeatherDataPrice, niceWeatherDataDistance);
    ConvertData(badWeather, badWeatherDataPrice, badWeatherDataDistance);
}


void UserInterface::WelcomeAndIntroduce()
{
    std::cout << "----------------    Welcome    ----------------" << std::endl;
    std::cout << "Which data would you like to analyze?" << std::endl;
}

char UserInterface::PrintMenu(std::string options)
{
    char userInput;

    std::cout << "------- Menu option -------" << std::endl;
    std::cout << options;

    do
    {
        std::cin >> userInput;
    }
    while(!IsValidMenuOption(userInput));

    return tolower(userInput);
}

bool UserInterface::IsValidMenuOption(char c)
{
    char input = tolower(c);
    return input == '1' ||
           input == '2' ||
           input == '3' ||
           input == '4' ||
           input == '5' ||
           input == 'q';
}

void UserInterface::CallMainMenuFunction(char c)
{
    char userInput;
    switch(c)
    {
        case '1':
            std::cout << "FIXME: Calling Menu function 1" << std::endl;
            userInput = PrintMenu(mainMenuOrExit);
            CallMainMenuOrExitFunction(userInput);
            break;
        case '2':
            std::cout << "FIXME: Calling Menu function 2" << std::endl;
            userInput = PrintMenu(mainMenuOrExit);
            CallMainMenuOrExitFunction(userInput);
            break;
        case '3':
            userInput = PrintMenu(mathOptions);
            CallMathFunction(userInput);
            break;
        case '4':
            std::cout << "FIXME: Calling Menu function 4" << std::endl;
            userInput = PrintMenu(mainMenuOrExit);
            CallMainMenuOrExitFunction(userInput);
            break;
        case '5':
            std::cout << "FIXME: Calling Menu function 5" << std::endl;
            break;
        case 'q':
            std::cout << "Exiting the program" << std::endl;
            break;
    }
}

void UserInterface::CallSampleMenuFunction(char c)
{
    char userInput;
    switch(c)
    {
        case '1':
            if(userOperation == MathOperation::TwoSample)
            {
                if(firstOption == DataSample::Empty)
                {
                    firstOption = DataSample::Full;
                    userInput = PrintMenu(sampleOptions);
                    CallSampleMenuFunction(userInput);
                }
                else
                {
                    secondOption = DataSample::Full;
                    PerformOperation(userOperation,firstOption,secondOption);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Full;
                PerformOperation(userOperation,firstOption,secondOption);
            }
            else
            {
                std::cout << "Error:CallSampleMenuFunction" << std::endl;
            }
            break;
        case '2':
            if(userOperation == MathOperation::TwoSample)
            {
                if(firstOption == DataSample::Empty)
                {
                    firstOption = DataSample::Uber;
                    userInput = PrintMenu(sampleOptions);
                    CallSampleMenuFunction(userInput);
                }
                else
                {
                    secondOption = DataSample::Uber;
                    PerformOperation(userOperation,firstOption,secondOption);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Uber;
                PerformOperation(userOperation,firstOption,secondOption);
            }
            else
            {
                std::cout << "Error:CallSampleMenuFunction" << std::endl;
            }
            break;
        case '3':
            if(userOperation == MathOperation::TwoSample)
            {
                if(firstOption == DataSample::Empty)
                {
                    firstOption = DataSample::Lyft;
                    userInput = PrintMenu(sampleOptions);
                    CallSampleMenuFunction(userInput);
                }
                else
                {
                    secondOption = DataSample::Lyft;
                    PerformOperation(userOperation,firstOption,secondOption);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Lyft;
                PerformOperation(userOperation,firstOption,secondOption);
            }
            else
            {
                std::cout << "Error:CallSampleMenuFunction" << std::endl;
            }
            break;
        case '4':
            if(userOperation == MathOperation::TwoSample)
            {
                if(firstOption == DataSample::Empty)
                {
                    firstOption = DataSample::GoodWeather;
                    userInput = PrintMenu(sampleOptions);
                    CallSampleMenuFunction(userInput);
                }
                else
                {
                    secondOption = DataSample::GoodWeather;
                    PerformOperation(userOperation,firstOption,secondOption);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::GoodWeather;
                PerformOperation(userOperation,firstOption,secondOption);
            }
            else
            {
                std::cout << "Error:CallSampleMenuFunction" << std::endl;
            }
            break;
        case '5':
            if(userOperation == MathOperation::TwoSample)
            {
                if(firstOption == DataSample::Empty)
                {
                    firstOption = DataSample::BadWeather;
                    userInput = PrintMenu(sampleOptions);
                    CallSampleMenuFunction(userInput);
                }
                else
                {
                    secondOption = DataSample::BadWeather;
                    PerformOperation(userOperation,firstOption,secondOption);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::BadWeather;
                PerformOperation(userOperation,firstOption,secondOption);
            }
            else
            {
                std::cout << "Error:CallSampleMenuFunction" << std::endl;
            }
            break;
        case 'q':
            std::cout << "Exiting the program" << std::endl;
            break;
    }
}

void UserInterface::CallMathFunction(char c)
{
    char userInput;
    switch(c)
    {
        case '1':
            userOperation = MathOperation::OneSample;
            userInput = PrintMenu(sampleOptions);
            CallSampleMenuFunction(userInput);
            break;
        case '2':
            userOperation = MathOperation::TwoSample;
            userInput = PrintMenu(sampleOptions);
            CallSampleMenuFunction(userInput);
            break;
        case '3':
            std::cout << "FIXME: Calling Math function 3" << std::endl;
            break;
        case '4':
            std::cout << "FIXME: Calling Math function 4" << std::endl;
            break;
        case '5':
            std::cout << "FIXME: Calling Math function 5" << std::endl;
            break;
        case 'q':
            std::cout << "Exiting the program" << std::endl;
            break;
    }
}

void UserInterface::CallMainMenuOrExitFunction(char c)
{
    char userInput;
    switch(c)
    {
        case '1':
            userInput = PrintMenu(introOptions);
            CallMainMenuFunction(userInput);
            break;
        case '2':
            std::cout << "FIXME: Calling Math function 2" << std::endl;
            break;
        case '3':
            std::cout << "FIXME: Calling Math function 3" << std::endl;
            break;
        case '4':
            std::cout << "FIXME: Calling Math function 4" << std::endl;
            break;
        case '5':
            std::cout << "FIXME: Calling Math function 5" << std::endl;
            break;
        case 'q':
            std::cout << "Exiting the program" << std::endl;
            break;
    }
}

void UserInterface::PerformOperation(MathOperation o, DataSample first, DataSample second)
{
    //example usage
    std::vector<double> optionOnePrice;
    std::vector<double> optionOneDistance;
    std::vector<double> optionTwoPrice;
    std::vector<double> optionTwoDistance;

    switch(first)
    {
        case DataSample::Full:
            optionOnePrice = fullDataPrice;
            optionOnePrice = fullDataDistance;
            break;
        case DataSample::Lyft:
            optionOnePrice = lyftDataPrice;
            optionOnePrice = lyftDataDistance;
            break;
        case DataSample::Uber:
            optionOnePrice = uberDataPrice;
            optionOnePrice = uberDataDistance;
            break;
        case DataSample::GoodWeather:
            optionOnePrice = niceWeatherDataPrice;
            optionOnePrice = niceWeatherDataDistance;
            break;
        case DataSample::BadWeather:
            optionOnePrice = badWeatherDataPrice;
            optionOnePrice = badWeatherDataDistance;
            break;
        default:
            std::cout << "Error: Option 1 is empty." << std::endl;
    }

    switch(second)
    {
        case DataSample::Full:
            optionTwoPrice = fullDataPrice;
            optionTwoPrice = fullDataDistance;
            break;
        case DataSample::Lyft:
            optionTwoPrice = lyftDataPrice;
            optionTwoPrice = lyftDataDistance;
            break;
        case DataSample::Uber:
            optionTwoPrice = uberDataPrice;
            optionTwoPrice = uberDataDistance;
            break;
        case DataSample::GoodWeather:
            optionTwoPrice = niceWeatherDataPrice;
            optionTwoPrice = niceWeatherDataDistance;
            break;
        case DataSample::BadWeather:
            optionTwoPrice = badWeatherDataPrice;
            optionTwoPrice = badWeatherDataDistance;
            break;
    }

    switch(o)
    {
        case MathOperation::OneSample:
            std::cout << "You're trying to perform a one sample test on " << "optionOne" << std::endl;
            std::cout << "optionOne" << std::endl;
            std::cout << "\thas the mean of the price: " << Statistics::ComputeMean(optionOnePrice) << std::endl;
            std::cout << "has the standard deviation of: " << Statistics::ComputeSTD(optionOnePrice) << std::endl;
            std::cout << "\thas the mean of the distance: " << Statistics::ComputeMean(optionOneDistance) << std::endl;
            std::cout << "has the standard deviation of: " << Statistics::ComputeSTD(optionOneDistance) << std::endl;
            break;
        case MathOperation::TwoSample:
            std::cout << "You're trying to perform a two sample test on " << "optionOne" << " and " << "optionTwo" << std::endl;
            std::cout << "optionOne" << std::endl;
            std::cout << "\thas the mean of the price: " << Statistics::ComputeMean(optionOnePrice) << std::endl;
            std::cout << "has the standard deviation of: " << Statistics::ComputeSTD(optionOnePrice) << std::endl;
            std::cout << "\thas the mean of the distance: " << Statistics::ComputeMean(optionOneDistance) << std::endl;
            std::cout << "has the standard deviation of: " << Statistics::ComputeSTD(optionOneDistance) << std::endl;
            std::cout << "optionOne" << std::endl;
            std::cout << "\thas the mean of the price: " << Statistics::ComputeMean(optionOnePrice) << std::endl;
            std::cout << "has the standard deviation of: " << Statistics::ComputeSTD(optionOnePrice) << std::endl;
            std::cout << "\thas the mean of the distance: " << Statistics::ComputeMean(optionOneDistance) << std::endl;
            std::cout << "has the standard deviation of: " << Statistics::ComputeSTD(optionOneDistance) << std::endl;


            std::cout << "T test" << std::endl;
            //printf("( mean(%s) - mean(%s) )/sqrt( std(%s)^2/size(%s) + std(%s)^2/size(%s) ) = ", optionOne.c_str(), optionTwo.c_str(),
                   //optionOne.c_str(), optionOne.c_str(), optionTwo.c_str(), optionTwo.c_str());
            std::cout << "FIXME: Call the function" << std::endl;
            break;
    }
}
void UserInterface::ConvertData(vector<Cabs>& cabs, vector<double>& price, vector<double>& distance)
{
    price.clear();
    distance.clear();
    for(int i = 0; i < cabs.size(); i++)
    {
        price.push_back(cabs[i].getPrice());
        distance.push_back(cabs[i].getDistance());
    }
}

void UserInterface::ConvertData(vector<cabAndWeather>& cnb, vector<double>& price, vector<double>& distance)
{
    price.clear();
    distance.clear();
    for(int i = 0; i < cnb.size(); i++)
    {
        price.push_back(cnb[i].getXprice());
        distance.push_back(cnb[i].getDistance());
    }
}
