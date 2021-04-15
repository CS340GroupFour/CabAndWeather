#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <string>
#include <vector>
#include "Cabs.h"
#include "cabAndWeather.h"
// #include "Cabs.h"

class UserInterface
{
public:
    enum MathOperation { OneSample, TwoSample, None};
    enum DataSample {Full, Lyft, Uber, GoodWeather, BadWeather, Empty};

    std::string introOptions;
    std::string sampleOptions;
    std::string mathOptions;
    std::string mainMenuOrExit;
    void WelcomeAndIntroduce();
    char PrintMenu(std::string options);
    bool IsValidMenuOption(char c);
    void CallMainMenuFunction(char c);
    void CallSampleMenuFunction(char c);
    void CallMathFunction(char c);
    void CallMainMenuOrExitFunction(char c);
    void PerformOperation(MathOperation o, DataSample first, DataSample second);
    UserInterface(); // Don't recommend using this. Should only be used for testing

    // TODO: Uncomment this after cabs is implemented properly
    UserInterface(std::vector<Cabs>& fullData, std::vector<Cabs>& uber, std::vector<Cabs>& lyft, std::vector<cabAndWeather>& niceWeather, std::vector<cabAndWeather>& badWeather);

private:
    MathOperation userOperation;
    DataSample firstOption;
    DataSample secondOption;
    void ConvertData(vector<Cabs>& cabs, vector<double>& price, vector<double>& distance);
    void ConvertData(vector<cabAndWeather>& cnb, vector<double>& price, vector<double>& distance);

    // TODO:Uncomment this after Cabs is implemented properly
    std::vector<double> fullDataPrice;
    std::vector<double> fullDataDistance;

    std::vector<double> uberDataPrice;
    std::vector<double> uberDataDistance;

    std::vector<double> lyftDataPrice;
    std::vector<double> lyftDataDistance;

    std::vector<double> niceWeatherDataPrice;
    std::vector<double> niceWeatherDataDistance;

    std::vector<double> badWeatherDataPrice;
    std::vector<double> badWeatherDataDistance;
};

// Example1 Code:
/*
int main()
{
    char userOption;
    UserInterface ui;
    ui.WelcomeAndIntroduce();
    userOption = ui.PrintMenu(ui.introOptions);
    ui.CallMainMenuFunction(userOption);
}
*/
#endif