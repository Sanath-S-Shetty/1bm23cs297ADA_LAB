#include <stdio.h>
#define INF 99999

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int cost[n][n];
    printf("Enter adjacency matrix (use %d for no edge):\n", INF);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);
    int selected[n];
    for (int i = 0; i < n; i++)
        selected[i] = 0;
    selected[0] = 1;
    int edge_count = 0, mincost = 0;
    printf("Edges in MST:\n");
    while (edge_count < n - 1) {
        int min = INF, x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", x, y, cost[x][y]);
        mincost += cost[x][y];
        selected[y] = 1;
        edge_count++;
    }
    printf("Minimum cost = %d\n", mincost);
    return 0;
}