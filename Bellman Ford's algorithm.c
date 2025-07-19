
#include <stdio.h>
#define MAX 100
#define INF 9999

Struct Edge {
    Int src, dest, weight;
};

Int main() {
    Int V, E;
    Printf(“Enter number of vertices and edges: “);
    Scanf(“%d %d”, &V, &E);

    Struct Edge edge[E];
    Printf(“Enter src dest weight for each edge:\n”);
    For (int I = 0; I < E; i++)
        Scanf(“%d %d %d”, &edge[i].src, &edge[i].dest, &edge[i].weight);

    Int dist[V];
    For (int I = 0; I < V; i++) dist[i] = INF;
    Dist[0] = 0;

    For (int I = 1; I <= V – 1; i++) {
        For (int j = 0; j < E; j++) {
            Int u = edge[j].src;
            Int v = edge[j].dest;
            Int w = edge[j].weight;
            If (dist[u] != INF && dist[u] + w < dist[v])
                Dist[v] = dist[u] + w;
        }
    }

    Printf(“Vertex Distance from Source:\n”);
    For (int I = 0; I < V; i++)
        Printf(“%d\t%d\n”, I, dist[i]);

    Return 0;
}
