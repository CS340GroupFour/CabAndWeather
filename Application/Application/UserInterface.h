#include <string>

namespace UserInterface
{
    extern std::string menuOptions;
    extern std::string mathOptions;
    void WelcomeAndIntroduce();
    char PrintMenu(std::string options);
    bool IsValidMenuOption(char c);
    void CallMenuFunction(char c);
    void CallMathFunction(char c);
};

// Example Code:
/*
int main()
{
    char userOption;

    WelcomeAndIntroduce();

    userOption = PrintMenu(menuOptions);
    CallMenuFunction(userOption);
    userOption = PrintMenu(mathOptions);
    CallMathFunction(userOption);
}
*/