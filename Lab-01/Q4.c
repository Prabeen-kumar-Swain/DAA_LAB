//Towers of Hanoi (ToH)
#include <stdio.h>

long long moves = 0;

void toh(int n,char from,char aux,char to)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",from,to);
        moves++;
        return;
    }

    toh(n-1,from,to,aux);

    printf("Move disk %d from %c to %c\n",n,from,to);
    moves++;

    toh(n-1,aux,from,to);
}

int main()
{
    int n;

    printf("Enter number of disks : ");
    scanf("%d",&n);

    toh(n,'L','M','R');

    printf("\nTotal Moves = %lld\n",moves);

    return 0;
}
