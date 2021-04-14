#include <string>

namespace UserInterface
{
    extern std::string introOptions;
    extern std::string sampleOptions;
    extern std::string mathOptions;
    void WelcomeAndIntroduce();
    char PrintMenu(std::string options);
    bool IsValidMenuOption(char c);
    void CallMainMenuFunction(char c);
    void CallSampleMenuFunction(char c);
    void CallMathFunction(char c);
};

// Example1 Code:
/*
int main()
{
    char userOption;

    UserInterface::WelcomeAndIntroduce();

    userOption = UserInterface::PrintMenu(UserInterface::introOptions);
    UserInterface::CallMainMenuFunction(userOption);
}
*/