//Fair vs Biased coin
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int tosses = 100000;

    int fairHeads = 0;
    int biasedHeads = 0;

    srand(time(NULL));

    for(int i=0;i<tosses;i++)
    {
        if(rand()%2==0)
            fairHeads++;

        if(rand()%100 < 70)
            biasedHeads++;
    }

    printf("Total Tosses : %d\n\n",tosses);

    printf("Fair Coin\n");
    printf("Heads = %d\n",fairHeads);
    printf("Probability = %.4f\n\n",(float)fairHeads/tosses);

    printf("Biased Coin (70%% Heads)\n");
    printf("Heads = %d\n",biasedHeads);
    printf("Probability = %.4f\n",(float)biasedHeads/tosses);

    return 0;
}
