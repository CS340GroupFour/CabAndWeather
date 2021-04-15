#include <string>
#include <vector>
// #include "Cabs.h"

class UserInterface
{
    public:
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
    UserInterface(); // Don't recommend using this. Should only be used for testing

    // TODO: Uncomment this after cabs is implemented properly
    // UserInterface(vector<Cabs>& fullData, vector<Cabs>& uber, vector<Cabs>& lyft, vector<Cabs>& niceWeather, vector<Cabs>& badWeather);

    private:
    enum MathOperation { OneSample, TwoSample, None};
    enum DataSample {Full, Lyft, Uber, GoodWeather, BadWeather, Empty};

    MathOperation userOperation;
    DataSample firstOption;
    DataSample secondOption;

    // TODO:Uncomment this after Cabs is implemented properly
    // std::vector<Cabs> fullData;
    // std::vector<Cabs> uber;
    // std::vector<Cabs> lyft;
    // std::vector<Cabs> niceWeather;
    // std::vector<Cabs> badWeather;
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