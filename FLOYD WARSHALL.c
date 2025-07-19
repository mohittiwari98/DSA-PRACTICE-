//FL
#include <stdio.h>
#define MAX 100
#define INF 9999

Void floydWarshall(int graph[MAX][MAX], int n) {
    Int dist[MAX][MAX];
    For (int I = 0; I < n; i++)
        For (int j = 0; j < n; j++)
            Dist[i][j] = graph[i][j];

    For (int k = 0; k < n; k++)
        For (int I = 0; I < n; i++)
            For (int j = 0; j < n; j++)
                If (dist[i][k] + dist[k][j] < dist[i][j])
                    Dist[i][j] = dist[i][k] + dist[k][j];

    Printf(“Shortest distances between every pair of vertices:\n”);
    For (int I = 0; I < n; i++) {
        For (int j = 0; j < n; j++) {
            If (dist[i][j] == INF)
                Printf(“INF “);
            Else
                Printf(“%d “, dist[i][j]);
        }
        Printf(“\n”);
    }
}

Int main() {
    Int n;
    Printf(“Enter number of vertices: “);
    Scanf(“%d”, &n);
    Int graph[MAX][MAX];
    Printf(“Enter cost adjacency matrix (9999 for INF):\n”);
    For (int I = 0; I < n; i++)
        For (int j = 0; j < n; j++)
            Scanf(“%d”, &graph[i][j]);

    floydWarshall(graph, n);
    return 0;
}
