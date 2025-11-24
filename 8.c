#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[MAX];

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void BFS_list(int start, int n) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;

    printf("\nBFS (Adjacency List) starting from %d: ", start);

    visited[start] = 1;
    queue[++rear] = start;

    while (front <= rear) {
        int vertex = queue[front++];

        printf("%d ", vertex);

        Node* temp = adjList[vertex];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[++rear] = temp->vertex;
            }
            temp = temp->next;
        }
    }
}
void DFS_list_util(int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = adjList[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS_list_util(temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void DFS_list(int start, int n) {
    int visited[MAX] = {0};
    printf("\nDFS (Adjacency List) starting from %d: ", start);
    DFS_list_util(start, visited);
}
int main() {
    int n, edges;
    int adjMatrix[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 

        Node* newNode1 = createNode(v);
        newNode1->next = adjList[u];
        adjList[u] = newNode1;

        Node* newNode2 = createNode(u);
        newNode2->next = adjList[v];
        adjList[v] = newNode2;
    }
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adjMatrix[i][j]);
        printf("\n");
    }
    printf("\nAdjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    int start;
    printf("\nEnter starting node for BFS & DFS: ");
    scanf("%d", &start);

    BFS_list(start, n);
    DFS_list(start, n);

    return 0;
}