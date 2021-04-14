#include<iostream>
#include<string>

std::string menuOptions = "1 - Full sample\n"
"2 - Uber sample\n"
"3 - Lyft sample\n"
"4 - Rainy weather sample\n"
"5 - Nice weather sample\n"
"q - Quit\n";
std::string mathOptions = "1 - Calculate sample mean\n"
"2 - Calculate sample standard deviation\n"
"3 - Calculate Student T test\n"
"q - Quit\n";

bool IsValidMenuOption(char c);
char PrintMenu(std::string options);
void CallMenuFunction(char c);
void CallMathFunction(char c);

int main()
{
    char userOption;

    std::cout << "----------------    Welcome    ----------------" << std::endl;
    std::cout << "Which data would you like to analyze?" << std::endl;

    userOption = PrintMenu(menuOptions);
    CallMenuFunction(userOption);
    userOption = PrintMenu(mathOptions);
    CallMathFunction(userOption);
}

char PrintMenu(std::string options)
{
   // FIXME: find the purpose if having a string param
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
bool IsValidMenuOption(char c)
{
   char input = tolower(c);
   return input == '1' || 
          input == '2' || 
          input == '3' ||
          input == '4' ||
          input == '5' ||
          input == 'q';
}

void CallMenuFunction(char c)
{   
    switch(c)
    {
        case '1':
            std::cout << "FIXME: Calling Menu function a" << std::endl;
            break;
        case '2':
            std::cout << "FIXME: Calling Menu function b" << std::endl;
            break;
        case '3':
            std::cout << "FIXME: Calling Menu function c" << std::endl;
            break;
        case '4':
            std::cout << "FIXME: Calling Menu function d" << std::endl;
            break;
        case '5':
            std::cout << "FIXME: Calling Menu function e" << std::endl;
            break;
        case 'q':
            std::cout << "Exiting the program" << std::endl;
            break;
    }
}
void CallMathFunction(char c)
{
    switch(c)
    {
        case '1':
            std::cout << "FIXME: Calling Math function 1" << std::endl;
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