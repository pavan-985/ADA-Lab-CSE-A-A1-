#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAX 100

// ------------------- Utility -------------------
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// ------------------- Dijkstra using Array -------------------
void dijkstraArray(int graph[MAX][MAX], int src, int n) {
    int dist[MAX], visited[MAX] = {0};
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int count = 0; count < n-1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = 1;
        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("\nDijkstra (Array) shortest distances from node %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("Node %d -> %d\n", i, dist[i]);
}

// ------------------- Min-Heap Priority Queue -------------------
typedef struct {
    int vertex;
    int dist;
} HeapNode;

typedef struct {
    HeapNode* harr;
    int size;
} MinHeap;

MinHeap* createMinHeap(int n) {
    MinHeap* h = (MinHeap*)malloc(sizeof(MinHeap));
    h->harr = (HeapNode*)malloc(n * sizeof(HeapNode));
    h->size = 0;
    return h;
}

void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1, right = 2*i + 2;
    if (left < h->size && h->harr[left].dist < h->harr[smallest].dist)
        smallest = left;
    if (right < h->size && h->harr[right].dist < h->harr[smallest].dist)
        smallest = right;
    if (smallest != i) {
        swap(&h->harr[i], &h->harr[smallest]);
        heapify(h, smallest);
    }
}

HeapNode extractMin(MinHeap* h) {
    HeapNode root = h->harr[0];
    h->harr[0] = h->harr[h->size - 1];
    h->size--;
    heapify(h, 0);
    return root;
}

void decreaseKey(MinHeap* h, int v, int dist) {
    for (int i = 0; i < h->size; i++) {
        if (h->harr[i].vertex == v) {
            h->harr[i].dist = dist;
            while (i != 0 && h->harr[(i-1)/2].dist > h->harr[i].dist) {
                swap(&h->harr[i], &h->harr[(i-1)/2]);
                i = (i-1)/2;
            }
            break;
        }
    }
}

// Check if vertex is in heap
int isInMinHeap(MinHeap* h, int v) {
    for (int i = 0; i < h->size; i++)
        if (h->harr[i].vertex == v)
            return 1;
    return 0;
}

// Dijkstra using Min-Heap
void dijkstraHeap(int graph[MAX][MAX], int src, int n) {
    int dist[MAX];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    MinHeap* h = createMinHeap(n);
    for (int v = 0; v < n; v++)
        h->harr[h->size++] = (HeapNode){v, dist[v]};

    while (h->size > 0) {
        HeapNode minNode = extractMin(h);
        int u = minNode.vertex;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                decreaseKey(h, v, dist[v]);
            }
        }
    }

    printf("\nDijkstra (Min-Heap) shortest distances from node %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("Node %d -> %d\n", i, dist[i]);
}

// ------------------- Main -------------------
int main() {
    int n, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    int graph[MAX][MAX] = {0};

    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; // Comment for directed
    }

    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);

    clock_t t1 = clock();
    dijkstraArray(graph, start, n);
    t1 = clock() - t1;

    clock_t t2 = clock();
    dijkstraHeap(graph, start, n);
    t2 = clock() - t2;

    printf("\nPerformance Comparison:\nArray Time: %lf sec\nHeap Time: %lf sec\n",
           (double)t1/CLOCKS_PER_SEC, (double)t2/CLOCKS_PER_SEC);

    return 0;
}
