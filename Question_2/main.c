#include "stdio.h"

//Assuming the function that transforms A into B is a change of numerical base
//from base 10 to base 62 with the digits in a random order.

//5387 is the sum of the ascii values for the alpha numeric symbols used for the digits
#define ALPHA_NUM_SUM 5387

//Size of the array for the required digits after base conversion (directly correspnds to the numerical base being converted to) 
#define ARRAY_SIZE 62

//Amount of digits present in all of the Base62 samples
#define ORDER_OF_MAG 3

//Fills in the digits array with correspnding alpha numeric symbols
void populateDigits(char digits[]);

//Quickly checks for duplication in the digits array
int dupCheck(char digits[]);

//Outputs the contents of the digits array to a csv file named output.csv
void outputToFile(char digits[]);


int main()
{
    char digits[ARRAY_SIZE];

    populateDigits(digits);

    if(dupCheck(digits))
        printf("duplicate digits found\n");


    outputToFile(digits);


    return 0;
}

//Fills in the digits array with correspnding alpha numeric symbols
void populateDigits(char digits[])
{
    //allocate an array to hold the Base62 digits and a null
    char str1[ORDER_OF_MAG + 1];
    int num = 0, modNum = 0, digitsSum = 0;

    FILE *testFile = fopen("quiz.csv", "r");

    if(testFile == NULL)
    {
        printf("Failed to open input file\n");
        return;
    }

    //loop through each line of the csv storing the deciaml in num and the base62 in str1
    while(fscanf(testFile, "%d,%s", &num, str1) != -1)
    {
        //loop through each digit of the base62 number
        //given the numerical base is 62 the value of the least significant digit can
        //found by preforming a modulo operation on the decimal number with the numerical
        //base(62).
        for(int i = 0; i < ORDER_OF_MAG; ++i)
        {
            modNum = num % 62;
            //ensure the deciaml value isn't already assigned to another number and if
            //it is ensure that the current value of the digit is the same as previously
            //found
            if(digits[modNum] && (digits[modNum] != str1[ORDER_OF_MAG - 1 - i])){
                printf("failed to allocate num %d to %c\n", num, str1[ORDER_OF_MAG - 1 - i]);
                fclose(testFile);
                return;
            }
            //assign the base62 digit to the corresponding decimal value
            digits[modNum] = str1[ORDER_OF_MAG - 1 - i];
            //diving the decimal value by 62 shifts the corresponding base62 digit of interest 
            //left one
            num /= 62;

        }

    }

    if(testFile) fclose(testFile);

    //was missing the digit with a value fo 21
    //loop though all known digits and sum their ascii values
    for(int i = 0; i < 62; ++i)
    {
        digitsSum += (int)digits[i];
    }

    //subtract the ascii values of all known digits from the total
    //ascii value sum of all avalible digits to fill in the gap at 21(which is null currently)
    for(int i = 0; i < 62; ++i){
        if(digits[i] == '\0')
        {
            digits[i] = (char)(ALPHA_NUM_SUM - digitsSum);
        }
    }


    return;
}    

//Quickly checks for duplication in the digits array
int dupCheck(char digits[])
{
    //Brute force a duplicate check
    for(int i = 0; i < 62; ++i)
    {
        for(int j = i+1; j < 62; ++j)
        {
            if(digits[i] == digits[j])
                return 1;
        }
    }

    return 0;
}

//Outputs the contents of the digits array to a csv file named output.csv
void outputToFile(char digits[])
{
    FILE *outputFile = fopen("output.csv", "w");

    if(!outputFile)
    {
        printf("failed to open output file\n");
        return;
    }

    for(int i = 0; i < 62; ++i)
    {
        fprintf(outputFile, "%d,%c\n", i, digits[i]);
    }

    fclose(outputFile);

    return;
}