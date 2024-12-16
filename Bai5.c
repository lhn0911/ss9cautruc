#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 100

void dijkstra(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int start)
{
    int dist[MAX_VERTICES];
    int visited[MAX_VERTICES];

    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < vertices - 1; i++)
    {
        int minDist = INT_MAX;
        int u = -1;
        for (int v = 0; v < vertices; v++)
        {
            if (!visited[v] && dist[v] < minDist)
            {
                minDist = dist[v];
                u = v;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] != 0 && !visited[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Khoang cach ngan nhat tu dinh %d:\n", start);
    for (int i = 0; i < vertices; i++)
    {
        if (dist[i] == INT_MAX)
        {
            printf("Dinh %d: Khong the den\n", i);
        }
        else
        {
            printf("Dinh %d: %d\n", i, dist[i]);
        }
    }
}

int main()
{
    int vertices, edges;
    printf("Nhap so luong dinh: ");
    scanf("%d", &vertices);

    printf("Nhap so luong canh: ");
    scanf("%d", &edges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};

    printf("Nhap cac canh voi trong so (dinh1, dinh2, trongso):\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        graph[u][v] = weight;
    }

    int start;
    printf("Nhap dinh nguon: ");
    scanf("%d", &start);

    dijkstra(graph, vertices, start);

    return 0;
}
