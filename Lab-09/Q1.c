#include <stdio.h>

struct Item {
    double value, weight, lambda;
};

int main() {
    int n, i, j;
    double W, time = 0, total = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item a[n];

    for(i = 0; i < n; i++) {
        printf("Enter value, weight, decay rate: ");
        scanf("%lf %lf %lf", &a[i].value, &a[i].weight, &a[i].lambda);
    }

    printf("Enter capacity: ");
    scanf("%lf", &W);

    while(W > 0) {
        int best = -1;
        double bestDensity = -1e18;

        for(i = 0; i < n; i++) {
            if(a[i].weight > 0) {
                double density = a[i].value / a[i].weight - a[i].lambda * time;

                if(density > bestDensity) {
                    bestDensity = density;
                    best = i;
                }
            }
        }

        if(best == -1 || bestDensity <= 0)
            break;

        double take = W < a[best].weight ? W : a[best].weight;

        total += take * bestDensity;
        W -= take;
        a[best].weight -= take;
        time += take;
    }

    printf("Maximum effective value = %.2lf\n", total);

    return 0;
}

//Complexity: O(n²) in the worst case.
