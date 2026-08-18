/*Algorithm: Merge Intervals

Input: Array of intervals.
Output: Merged intervals.

Steps:

1. Start.
2. Read n.
3. Create an array of intervals.
4. Read the intervals.
5. Sort the intervals based on start time.
6. Initialize start and end with the first interval.
7. For each subsequent interval:
        If the current interval overlaps with the previous one:
            Update end to the maximum of both ends.
        Otherwise:
            Print the previous interval.
        Update start and end to the current interval.
        Print the last interval.
8. Stop.

Complexity:
Sorting: O(n log n)
Merging: O(n)
Total: O(n log n)

*/
#include <stdio.h>

struct Interval {
    int start;
    int end;
};

void sort(struct Interval a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].start > a[j + 1].start) {
                struct Interval temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval a[n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++)
        scanf("%d %d", &a[i].start, &a[i].end);

    sort(a, n);

    printf("Merged intervals:\n");

    int start = a[0].start;
    int end = a[0].end;

    for (int i = 1; i < n; i++) {

        if (a[i].start <= end) {
            if (a[i].end > end)
                end = a[i].end;
        }
        else {
            printf("(%d, %d)\n", start, end);

            start = a[i].start;
            end = a[i].end;
        }
    }

    printf("(%d, %d)\n", start, end);

    return 0;
}
