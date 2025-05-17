#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int calculateCost(int cost[10][10], int perm[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += cost[i][perm[i]];
    return total;
}

void permute(int cost[10][10], int perm[], int l, int r, int n, int *minCost) {
    if (l == r) {
        int currCost = calculateCost(cost, perm, n);
        *minCost = min(*minCost, currCost);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&perm[l], &perm[i]);
        permute(cost, perm, l + 1, r, n, minCost);
        swap(&perm[l], &perm[i]);
    }
}

int main() {
    int n;
    printf("Enter number of jobs (and persons): ");
    scanf("%d", &n);
    int cost[10][10];
    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    int perm[10];
    for (int i = 0; i < n; i++)
        perm[i] = i;
    int minCost = INT_MAX;
    permute(cost, perm, 0, n - 1, n, &minCost);
    printf("Minimum assignment cost = %d\n", minCost);
    return 0;
}