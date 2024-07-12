#include <stdio.h>
#include <limits.h>

#define V 5

void print_solution(int dist[], int n) {
   printf("Vertex Distance from Source\n");
   for (int i = 0; i < V; i++)
       printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
   int dist[V];
   
   for (int i = 0; i < V; i++)
       dist[i] = INT_MAX;

   dist[src] = 0;

   for (int i = 1; i < V; i++) {
      int u = -1;
      for (int j = 0; j < V; j++)
         if (dist[j] < INT_MAX && (u == -1 || dist[j] < dist[u]))
            u = j;

      for (int j = 0; j < V; j++)
         if (graph[u][j] && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j])
            dist[j] = dist[u] + graph[u][j];
   }

   print_solution(dist, V);
}

int main() {
   int graph[V][V] = {{0, 9, 75, 0, 0},
                      {9, 0, 95, 0, 0},
                      {75, 95, 0, 19, 42},
                      {0, 0, 19, 0, 57},
                      {0, 0, 42, 57, 0}};

   dijkstra(graph, 0);

   return 0;
}