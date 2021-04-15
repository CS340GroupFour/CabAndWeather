#include <string>
#include <iostream>
#include "UserInterface.h"




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
    std::string optionOne;
    std::string optionTwo;

    switch(first)
    {
        case DataSample::Full:
        optionOne = "Full";
        break;
        case DataSample::Lyft:
        optionOne = "Lyft";
        break;
        case DataSample::Uber:
        optionOne = "Uber";
        break;
        case DataSample::GoodWeather:
        optionOne = "GoodWeather";
        break;
        case DataSample::BadWeather:
        optionOne = "BadWeather";
        break;
        default:
        std::cout << "Error: Option 1 is empty." << std::endl;
    }

    switch(second)
    {
        case DataSample::Full:
        optionTwo = "Full";
        break;
        case DataSample::Lyft:
        optionTwo = "Lyft";
        break;
        case DataSample::Uber:
        optionTwo = "Uber";
        break;
        case DataSample::GoodWeather:
        optionTwo = "GoodWeather";
        break;
        case DataSample::BadWeather:
        optionTwo = "BadWeather";
        break;
        default:
        std::cout << "Error: Option 1 is empty." << std::endl;
    }

    switch(o)
    {
        case MathOperation::OneSample:
        std::cout << "You're trying to perform a one sample test on " << optionOne << std::endl;
        break;
        case MathOperation::TwoSample:
        std::cout << "You're trying to perform a two sample test on " << optionOne << " and " << optionTwo << std::endl;
        break;
    }
}