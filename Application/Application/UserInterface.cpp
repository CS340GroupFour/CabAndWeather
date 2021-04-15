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
    "4 - Rainy weather sample\n"
    "5 - Nice weather sample\n"
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
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Full;
                // TODO: Perform Operation here
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
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Uber;
                // TODO: Perform Operation here
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
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::Lyft;
                // TODO: Perform Operation here
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
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::GoodWeather;
                // TODO: Perform Operation here
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
                }
            }
            else if(userOperation == MathOperation::OneSample)
            {
                firstOption = DataSample::BadWeather;
                // TODO: Perform Operation here
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
