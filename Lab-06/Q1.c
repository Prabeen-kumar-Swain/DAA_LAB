//nth fibonacci number using dynamic programming
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) return n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    printf("Enter the position of the Fibonacci number: ");
    scanf("%d", &n);
    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    return 0;
}

/*
Algorithm:
1. Create an array dp of size n+1 to store Fibonacci numbers.
2. Initialize dp[0] = 0 and dp[1] = 1.
3. For each i from 2 to n, calculate dp[i] = dp[i - 1] + dp[i - 2].
4. Return dp[n].
*/

//Time Complexity: O(n) - We compute each Fibonacci number from 2 to n once.
