#include <stdio.h>
#include <math.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int val[n], wt[n];
    printf("Enter values of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &val[i]);
    printf("Enter weights of items:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &wt[i]);
    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int maxValue = 0;
    int total = 1 << n;
    for (int mask = 0; mask < total; mask++) {
        int currWeight = 0, currValue = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                currWeight += wt[i];
                currValue += val[i];
            }
        }
        if (currWeight <= W)
            maxValue = max(maxValue, currValue);
    }
    printf("Maximum value in knapsack = %d\n", maxValue);
    return 0;
}