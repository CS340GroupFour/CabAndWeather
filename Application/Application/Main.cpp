#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdio>
//#include "cabStructx.h"

typedef struct{
    char citySource[25]{};
    char cityDest[25]{};
    char cabBrand[4]{};
    char cabType[12]{};
    char identifier[40]{};
    char prod_id[15]{};
    double surgeMultiplier = 0.0;
    int time = 0;
    double distance = 0.0;
    double price;
} Cab;

int j = 1;

int main()
{
    FILE *cabData;
    cabData = fopen("F:/SP2021/CSC 340/untitled/test.csv", "r");

    if (cabData == NULL)
    {
        printf("Not successful");
    }

    rewind(cabData);

    char rowLine[5000];
    fgets(rowLine, 1024, cabData);
    const char *split =",";

    int i = 0;

    for(char c = getc(cabData); c!= EOF; c=getc(cabData)){
        if(c=='\n'){
            j++;
        }
    }
    Cab cabs[j+1];
    rewind(cabData);

    while(fgets(rowLine, 1024, (FILE*)cabData) != NULL){
        cabs[i].distance = atoi(strtok(rowLine, split));
        strcpy(cabs[i].cabBrand, strtok(NULL, split));
        cabs[i].time = atoi(strtok(NULL, split));
        strcpy(cabs[i].cityDest, strtok(NULL, split));
        strcpy(cabs[i].citySource, strtok(NULL, split));
        cabs[i].price = atoi(strtok(NULL, split));
        cabs[i].surgeMultiplier = atoi(strtok(NULL, split));
        strcpy(cabs[i].identifier, strtok(NULL, split));
        strcpy(cabs[i].prod_id, strtok(NULL, split));
        strcpy(cabs[i].cabType, strtok(NULL, split));
        i++;
    }

    fclose(cabData);


    return 0;
}
