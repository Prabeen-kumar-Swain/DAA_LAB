//[The best time to be alive]
#include <stdio.h>
#include <stdlib.h>

struct Event
{
    int year;
    int type;
};

int compare(const void *a, const void *b)
{
    struct Event *x = (struct Event *)a;
    struct Event *y = (struct Event *)b;

    if (x->year != y->year)
        return x->year - y->year;

    /* Death (-1) comes before birth (+1) */
    return x->type - y->type;
}

int main()
{
    int n;

    printf("Enter number of scientists: ");
    scanf("%d", &n);

    struct Event events[2 * n];

    for (int i = 0; i < n; i++)
    {
        int birth, death;

        printf("Enter birth and death year for scientist %d: ",
               i + 1);

        scanf("%d %d", &birth, &death);

        events[2 * i].year = birth;
        events[2 * i].type = 1;

        events[2 * i + 1].year = death;
        events[2 * i + 1].type = -1;
    }

    qsort(events, 2 * n, sizeof(struct Event), compare);

    int count = 0;
    int maxCount = 0;
    int bestYear = 0;

    for (int i = 0; i < 2 * n; i++)
    {
        count += events[i].type;

        if (count > maxCount)
        {
            maxCount = count;
            bestYear = events[i].year;
        }
    }

    printf("\nBest year = %d\n", bestYear);
    printf("Maximum scientists alive = %d\n", maxCount);

    return 0;
}


/*
ALGORITHM: BEST TIME TO BE ALIVE

1. Read the number of scientists.
2. For every scientist, read:
       birth year
       death year
3. Create two events:
       birth -> +1
       death -> -1
4. Sort all events by year.
5. If two events have the same year:
       process death before birth.
6. Maintain a variable count.
7. For a birth event, increase count.
8. For a death event, decrease count.
9. Whenever count becomes greater than maxCount:
       update maxCount and bestYear.
10. Print the year having the largest number of scientists alive.

Complexity:
Sorting = O(N log N)
Scanning = O(N)
Total = O(N log N)
Space = O(N)
*/
