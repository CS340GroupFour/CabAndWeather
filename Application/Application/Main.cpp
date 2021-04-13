#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <cstdio>
#include "cabStructx.h"


//struct for Cab, we can separate this later as a header file as you see on line 8
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

//Global variable j to determine cab size later on
int j = 1;

int main()
{	
    //Initializes cabData pointer and uses it to open the file
    FILE *cabData;
    // "r" means to read the file -- ALSO the file path has to absolute so :)
    cabData = fopen("F:/SP2021/CSC 340/untitled/test.csv", "r");

    //just file open validation
    if (cabData == NULL)
    {
        printf("Not successful");
    }
	
    //kind of resets the cabData	
    rewind(cabData);

    //Just a limiter, I'd have to fix this later or find a more efficient way
    char rowLine[5000];
    //sets cabData
    fgets(rowLine, 1024, cabData);
    const char *split 
	    
    //separates each row for every new line
    for(char c = getc(cabData); c!= EOF; c=getc(cabData)){
        if(c=='\n'){
            j++;
        }
    }
	
	//j+1 is a safety net for the cabs struct array parameter
    Cab cabs[j+1];
	
	//reads back to the start of the file
    rewind(cabData);

	//assigns each data onto its corresponding struct attributes or whatever it's called
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
	
	//closes the file
    fclose(cabData);


    return 0;
}
