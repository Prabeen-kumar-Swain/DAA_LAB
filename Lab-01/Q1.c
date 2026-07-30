//Put them in Order
#include <stdio.h>

int main() {
    char *order[] = {
        "1",
        "log2(n)",
        "sqrt(n)",
        "n",
        "n log2(n)",
        "100n",
        "32n log2(n)",
        "n^2",
        "n^3",
        "2^n"
    };

    int size = sizeof(order) / sizeof(order[0]);

    printf("Increasing Order of Growth:\n\n");

    for (int i = 0; i < size; i++){
        printf("%s", order[i]);

        if (i != size - 1)
            printf(" < ");
    }

printf("\n");
    return 0;
}
