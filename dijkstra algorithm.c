//
#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

int minDistance(int dist[], int sptSet[], int V) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int src, int V) {
    int dist[MAX_VERTICES];
    int sptSet[MAX_VERTICES];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX) {
            printf("%d \t INF\n", i);
        } else {
            printf("%d \t %d\n", i, dist[i]);
        }
    }
}

int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    printf("Enter the edges in the format (u, v, weight) for each edge:\n");
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(graph, source, V);
    return 0;
}


