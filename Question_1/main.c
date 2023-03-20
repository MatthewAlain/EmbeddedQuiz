#include "stdio.h"

int main()
{
    int N = 0, M = 0;

    //grab the inputs from terminal
    printf("Supply Value N: ");
    scanf("%d", &N);
    printf("Supply Value M: ");
    scanf("%d", &M);

    //loop while rectangle is not already a square
    while(N != M)
    {
        //the smallest side of the rectanle determines the maximum square size possible
        //the smaller side is then subtracted form the larger side to form a new rectangle
        if(N < M)
        {
            printf("%dx%d, ", N, N);
            M -= N;
        }
        else
        {
            printf("%dx%d, ", M, M);
            N -= M;
        }
        
    }
    //once the rectangle becomes a square output the final square
    printf("%dx%d\n", N, M);

    return 0;
}