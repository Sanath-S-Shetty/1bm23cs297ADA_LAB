#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 99999

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n, e;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    Edge edges[MAX];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    int mincost = 0, count = 0;
    printf("Edges in MST:\n");
    for (int i = 0; i < e && count < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        int set_u = find(u);
        int set_v = find(v);
        if (set_u != set_v) {
            printf("%d - %d : %d\n", u, v, w);
            mincost += w;
            union_set(set_u, set_v);
            count++;
        }
    }
    printf("Minimum cost = %d\n", mincost);
    return 0;
}