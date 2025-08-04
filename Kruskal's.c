
#include<stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    int parent, rank;
} Subset;
int compareEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
void unionSubsets(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank) {
        subsets[rootX].parent = rootY;
    } else if (subsets[rootX].rank > subsets[rootY].rank) {
        subsets[rootY].parent = rootX;
    } else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}


void kruskalMST(Edge edges[], int V, int E) {
    Edge result[V];  // Array to store the MST
    int e = 0;  // Count of edges in MST
    int i = 0;  // Initial index of sorted edges
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));

    qsort(edges, E, sizeof(Edge), compareEdges);
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < V - 1 && i < E) {
        Edge nextEdge = edges[i++];

        int x = find(subsets, nextEdge.u);
        int y = find(subsets, nextEdge.v);

        if (x != y) {
            result[e++] = nextEdge;
            unionSubsets(subsets, x, y);
        }
    }

    printf("The edges in the Minimum Spanning Tree are:\n");
    for (i = 0; i < e; ++i) {
        printf("%d - %d: %d\n", result[i].u, result[i].v, result[i].weight);
    }

    free(subsets);
}

// Driver code
int main() {
    int V, E;

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    // Input the edges
    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    // Run Kruskal's algorithm
    kruskalMST(edges, V, E);

    free(edges);
    return 0;
}


