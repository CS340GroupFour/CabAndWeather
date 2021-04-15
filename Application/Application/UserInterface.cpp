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
                    userInput = PrintMenu(mainMenuOrExit);
                    CallMainMenuOrExitFunction(userInput);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Full;
                PerformOperation(userOperation,firstOption,secondOption);
                userInput = PrintMenu(mainMenuOrExit);
                CallMainMenuOrExitFunction(userInput);
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
                    userInput = PrintMenu(mainMenuOrExit);
                    CallMainMenuOrExitFunction(userInput);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Uber;
                PerformOperation(userOperation,firstOption,secondOption);
                userInput = PrintMenu(mainMenuOrExit);
                CallMainMenuOrExitFunction(userInput);
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
                    userInput = PrintMenu(mainMenuOrExit);
                    CallMainMenuOrExitFunction(userInput);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Lyft;
                PerformOperation(userOperation,firstOption,secondOption);
                userInput = PrintMenu(mainMenuOrExit);
                CallMainMenuOrExitFunction(userInput);
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
                    userInput = PrintMenu(mainMenuOrExit);
                    CallMainMenuOrExitFunction(userInput);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::GoodWeather;
                PerformOperation(userOperation,firstOption,secondOption);
                userInput = PrintMenu(mainMenuOrExit);
                CallMainMenuOrExitFunction(userInput);
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
                    userInput = PrintMenu(mainMenuOrExit);
                    CallMainMenuOrExitFunction(userInput);
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::BadWeather;
                PerformOperation(userOperation,firstOption,secondOption);
                userInput = PrintMenu(mainMenuOrExit);
                CallMainMenuOrExitFunction(userInput);
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

    std::string fOption;
    std::string sOption;

    switch(first)
    {
        case DataSample::Full:
            fOption = "Full";
            optionOnePrice = fullDataPrice;
            optionOneDistance = fullDataDistance;
            break;
        case DataSample::Lyft:
            fOption = "Lyft";
            optionOnePrice = lyftDataPrice;
            optionOneDistance = lyftDataDistance;
            break;
        case DataSample::Uber:
            fOption = "Uber";
            optionOnePrice = uberDataPrice;
            optionOneDistance = uberDataDistance;
            break;
        case DataSample::GoodWeather:
            fOption = "Good Weather";
            optionOnePrice = niceWeatherDataPrice;
            optionOneDistance = niceWeatherDataDistance;
            break;
        case DataSample::BadWeather:
            fOption = "Bad Weather";
            optionOnePrice = badWeatherDataPrice;
            optionOneDistance = badWeatherDataDistance;
            break;
        default:
            std::cout << "Error: Option 1 is empty." << std::endl;
    }

    switch(second)
    {
        case DataSample::Full:
            sOption = "Full";
            optionTwoPrice = fullDataPrice;
            optionTwoDistance = fullDataDistance;
            break;
        case DataSample::Lyft:
            sOption = "Lyft";
            optionTwoPrice = lyftDataPrice;
            optionTwoDistance = lyftDataDistance;
            break;
        case DataSample::Uber:
            sOption = "Uber";
            optionTwoPrice = uberDataPrice;
            optionTwoDistance = uberDataDistance;
            break;
        case DataSample::GoodWeather:
            sOption = "Good Weather";
            optionTwoPrice = niceWeatherDataPrice;
            optionTwoDistance = niceWeatherDataDistance;
            break;
        case DataSample::BadWeather:
            sOption = "Bad Weather";
            optionTwoPrice = badWeatherDataPrice;
            optionTwoDistance = badWeatherDataDistance;
            break;
    }

    switch(o)
    {
        double firstMean;
        double secondMean;

        case MathOperation::OneSample:
            firstMean = Statistics::ComputeMean(optionOnePrice);
            secondMean = Statistics::ComputeMean(optionOneDistance);
            std::cout << "You're trying to perform a one sample test:" << std::endl;
            std::cout << fOption << std::endl;
            std::cout << "\thas the mean of the price: " << firstMean << std::endl;
            std::cout << "\thas the standard deviation of: " << Statistics::ComputeSTD(optionOnePrice) << std::endl;
            std::cout << "\thas the mean of the distance: " << secondMean << std::endl;
            std::cout << "\thas the standard deviation of: " << Statistics::ComputeSTD(optionOneDistance) << std::endl;
            std::cout << "\tThe average $/mile of: " << firstMean/secondMean << std::endl;

            break;
        case MathOperation::TwoSample:
            firstMean = Statistics::ComputeMean(optionOnePrice);
            secondMean = Statistics::ComputeMean(optionOneDistance);
            double fm = Statistics::ComputeMean(optionTwoPrice);
            double sm = Statistics::ComputeMean(optionTwoDistance);

            std::cout << "You're trying to perform a two sample test:" << std::endl;
            std::cout << fOption << std::endl;
            std::cout << "\thas the mean of the price: " << firstMean << std::endl;
            std::cout << "\thas the standard deviation of: " << Statistics::ComputeSTD(optionOnePrice) << std::endl;
            std::cout << "\thas the mean of the distance: " << secondMean << std::endl;
            std::cout << "\thas the standard deviation of: " << Statistics::ComputeSTD(optionOneDistance) << std::endl;
            std::cout << "\tThe average $/mile of: " << firstMean/secondMean << std::endl;

            std::cout << sOption << std::endl;
            std::cout << "\thas the mean of the price: " << fm << std::endl;
            std::cout << "\thas the standard deviation of: " << Statistics::ComputeSTD(optionTwoPrice) << std::endl;
            std::cout << "\thas the mean of the distance: " << sm << std::endl;
            std::cout << "\thas the standard deviation of: " << Statistics::ComputeSTD(optionTwoDistance) << std::endl;
            std::cout << "\tThe average $/mile of: " << fm/sm << std::endl;


            std::cout << "T test" << std::endl;
            //printf("( mean(%s) - mean(%s) )/sqrt( std(%s)^2/size(%s) + std(%s)^2/size(%s) ) = ", optionOne.c_str(), optionTwo.c_str(),
                   //optionOne.c_str(), optionOne.c_str(), optionTwo.c_str(), optionTwo.c_str());
            std::cout << "\tPrice: " << Statistics::Ttest(optionOnePrice, optionTwoPrice) << std::endl;
            std::cout << "\tDistance: " << Statistics::Ttest(optionOneDistance, optionTwoDistance) << std::endl;
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
