#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int calculateCost(int graph[10][10], int perm[], int n) {
    int cost = 0;
    for (int i = 0; i < n - 1; i++)
        cost += graph[perm[i]][perm[i + 1]];
    cost += graph[perm[n - 1]][perm[0]];
    return cost;
}

void permute(int graph[10][10], int perm[], int l, int r, int n, int *minCost, int bestPath[]) {
    if (l == r) {
        int currCost = calculateCost(graph, perm, n);
        if (currCost < *minCost) {
            *minCost = currCost;
            for (int i = 0; i < n; i++)
                bestPath[i] = perm[i];
        }
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&perm[l], &perm[i]);
        permute(graph, perm, l + 1, r, n, minCost, bestPath);
        swap(&perm[l], &perm[i]);
    }
}

int main() {
    int n;
    printf("Enter number of cities: ");
    scanf("%d", &n);
    int graph[10][10];
    printf("Enter cost adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    int perm[10], bestPath[10];
    for (int i = 0; i < n; i++)
        perm[i] = i;
    int minCost = INT_MAX;
    permute(graph, perm, 1, n - 1, n, &minCost, bestPath);
    printf("Minimum cost = %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i < n; i++)
        printf("%d ", bestPath[i]);
    printf("%d\n", bestPath[0]);
    return 0;
}