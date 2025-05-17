#include <stdio.h>

#define MAX 100

int main() {
    int n, edges, u, v;
    int adj[MAX][MAX], indegree[MAX] = {0}, visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    printf("Topological Order: ");
    int count = 0;
    while (count < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                found = 1;
                count++;
                for (int j = 0; j < n; j++) {
                    if (adj[i][j])
                        indegree[j]--;
                }
                break;
            }
        }
        if (!found) {
            printf("\nCycle detected. Topological sort not possible.\n");
            return 1;
        }
    }
    printf("\n");
    return 0;
}