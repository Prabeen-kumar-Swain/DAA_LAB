/*Algorithm: Maximum People Present

Input: Entry and exit times of n people.
Output: Maximum number of people present and the corresponding time.

Steps:

1. Start.
2. Read n.
3. Create an event array of size 2n.
4. For every person:
5. Store their entry time as an entry event +1.
6. Store their exit time as an exit event -1.
7. Sort all 2n events according to time using Merge Sort.
8. Set:
        current = 0
        maximum = 0
        maxTime = 0
9. Traverse the sorted events.
10. For an entry event:
        Increase current by 1.
11. For an exit event:
    Decrease current by 1.
    Whenever:
        current > maximum
    update:
        maximum = current
    and
    maxTime = current event time

12. After processing all events, display maximum and maxTime.
13. Stop.

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
    int time;
    int type;       // +1 = entry, -1 = exit
};

void sort(struct Event e[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (e[j].time > e[j + 1].time) {
                struct Event temp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of people: ");
    scanf("%d", &n);

    struct Event e[2 * n];

    printf("Enter entry and exit times:\n");

    for (int i = 0; i < n; i++) {
        int entry, exit;

        scanf("%d %d", &entry, &exit);

        e[2 * i].time = entry;
        e[2 * i].type = 1;

        e[2 * i + 1].time = exit;
        e[2 * i + 1].type = -1;
    }

    sort(e, 2 * n);

    int current = 0;
    int maximum = 0;
    int maxTime = 0;

    for (int i = 0; i < 2 * n; i++) {
        current += e[i].type;

        if (current > maximum) {
            maximum = current;
            maxTime = e[i].time;
        }
    }

    printf("Maximum people present = %d\n", maximum);
    printf("Time = %d\n", maxTime);

    return 0;
}
