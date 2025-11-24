#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjLists;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest, int weight) {
    struct Node* newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src, weight);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// ---------------- Priority Queue for Prim ----------------

struct HeapNode {
    int vertex;
    int key;            // Minimum weight edge to add this vertex to MST
};

struct MinHeap {
    int size;
    int capacity;
    int *pos;
    struct HeapNode **array;
};

struct HeapNode* createHeapNode(int v, int key) {
    struct HeapNode* node = (struct HeapNode*)malloc(sizeof(struct HeapNode));
    node->vertex = v;
    node->key = key;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->pos = (int*)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct HeapNode**)malloc(capacity * sizeof(struct HeapNode*));
    return heap;
}

void swapHeapNode(struct HeapNode** a, struct HeapNode** b) {
    struct HeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size &&
        heap->array[left]->key < heap->array[smallest]->key)
        smallest = left;

    if (right < heap->size &&
        heap->array[right]->key < heap->array[smallest]->key)
        smallest = right;

    if (smallest != idx) {
        struct HeapNode* smallestNode = heap->array[smallest];
        struct HeapNode* idxNode = heap->array[idx];

        heap->pos[smallestNode->vertex] = idx;
        heap->pos[idxNode->vertex] = smallest;

        swapHeapNode(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

int isEmpty(struct MinHeap* heap) {
    return heap->size == 0;
}

struct HeapNode* extractMin(struct MinHeap* heap) {
    if (isEmpty(heap))
        return NULL;

    struct HeapNode* root = heap->array[0];

    struct HeapNode* lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->vertex] = heap->size - 1;
    heap->pos[lastNode->vertex] = 0;

    heap->size--;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap* heap, int v, int key) {
    int i = heap->pos[v];
    heap->array[i]->key = key;

    while (i && heap->array[i]->key < heap->array[(i - 1) / 2]->key) {
        heap->pos[heap->array[i]->vertex] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->vertex] = i;

        swapHeapNode(&heap->array[i], &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

// ---------------- Prim's Algorithm ----------------

void primMST(struct Graph* graph) {
    int V = graph->numVertices;
    int parent[V];
    int key[V];

    struct MinHeap* heap = createMinHeap(V);

    for (int v = 0; v < V; v++) {
        parent[v] = -1;
        key[v] = INT_MAX;
        heap->array[v] = createHeapNode(v, key[v]);
        heap->pos[v] = v;
    }

    key[0] = 0;
    heap->array[0]->key = 0;

    heap->size = V;

    while (!isEmpty(heap)) {
        struct HeapNode* minNode = extractMin(heap);
        int u = minNode->vertex;

        struct Node* temp = graph->adjLists[u];
        while (temp != NULL) {
            int v = temp->vertex; 

            if (heap->pos[v] < heap->size && temp->weight < key[v]) {
                key[v] = temp->weight;
                parent[v] = u;
                decreaseKey(heap, v, key[v]);
            }

            temp = temp->next;
        }
    }

    printf("\nMinimum Spanning Tree (Prim's Algorithm):\n");
    for (int i = 1; i < V; i++)
        printf("%d -- %d\n", parent[i], i);
}

// ------------------- MAIN -------------------

int main() {
    int V = 7;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 2);
    addEdge(graph, 0, 3, 6);
    addEdge(graph, 1, 2, 3);
    addEdge(graph, 1, 3, 8);
    addEdge(graph, 1, 4, 5);
    addEdge(graph, 2, 4, 7);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 4, 5, 1);
    addEdge(graph, 5, 6, 2);

    primMST(graph);

    return 0;
}
