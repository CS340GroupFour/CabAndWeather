#include<iostream>
#include<string>
#include"UserInterface.h"


int main()
{
    char userOption;

    UserInterface::WelcomeAndIntroduce();

    userOption = UserInterface::PrintMenu(UserInterface::menuOptions);
    UserInterface::CallMenuFunction(userOption);
    userOption = UserInterface::PrintMenu(UserInterface::mathOptions);
    UserInterface::CallMathFunction(userOption);
}
