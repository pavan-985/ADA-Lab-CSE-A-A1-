#include <stdio.h>
#include <stdlib.h>

#define MAX 30

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

void kruskal(int n, int e, Edge edges[]) {
    int i, j, u1, v1, total = 0;
    Edge temp;

    // Sort edges by weight
    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in Minimum Spanning Tree using Kruskal’s Algorithm:\n");
    for (i = 0, j = 0; j < n - 1 && i < e; i++) {
        u1 = find(edges[i].u);
        v1 = find(edges[i].v);

        if (u1 != v1) {
            printf("Edge (%d - %d) : Weight = %d\n", edges[i].u, edges[i].v, edges[i].w);
            total += edges[i].w;
            union_set(u1, v1);
            j++;
        }
    }

    printf("Total cost of MST = %d\n", total);
}

int main() {
    int n, e, i;
    Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++)
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].w);

    kruskal(n, e, edges);
    return 0;
}
