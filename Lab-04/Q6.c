/*Algorithm: Maximum Overlapping Intervals

Input: Array of intervals.
Output: Maximum number of overlapping intervals and the corresponding point.

Steps:

1. Start.
2. Read n.
3. Create an event array of size 2n.
4. For every interval:
        Store their start time as a start event +1.
        Store their end time as an end event -1.
5. Sort all 2n events according to point using Merge Sort.
6. Set:
        current = 0
        maximum = 0
        bestPoint = 0
7. Traverse the sorted events.
8. For a start event:
        Increase current by 1.
9. For an end event:
        Decrease current by 1.
10. Whenever:
        current > maximum
    update:
        maximum = current
    and
    bestPoint = current event point

11. After processing all events, display maximum and bestPoint.
12. Stop.

Complexity:
There are 2n events.

Sorting:
O(2n log(2n)) = O(n log n)

Scanning:
O(n)

Therefore:
Time Complexity = O(n log n)

*/

#include <stdio.h>

struct Event {
    int point;
    int type;       // +1 = start, -1 = end
};

void sort(struct Event e[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (e[j].point > e[j + 1].point ||
               (e[j].point == e[j + 1].point &&
                e[j].type < e[j + 1].type)) {

                struct Event temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Event e[2 * n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++) {
        int l, r;

        scanf("%d %d", &l, &r);

        e[2 * i].point = l;
        e[2 * i].type = 1;

        e[2 * i + 1].point = r;
        e[2 * i + 1].type = -1;
    }

    sort(e, 2 * n);

    int current = 0;
    int maximum = 0;
    int bestPoint = 0;

    for (int i = 0; i < 2 * n; i++) {

        current += e[i].type;

        if (current > maximum) {
            maximum = current;
            bestPoint = e[i].point;
        }
    }

    printf("Point = %d\n", bestPoint);
    printf("Maximum number of intervals = %d\n", maximum);

    return 0;
}
