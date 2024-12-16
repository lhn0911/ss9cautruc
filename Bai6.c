#include <stdio.h>
#include <stdlib.h>
#define V 4

void findMaxDegree(int graph[V][V], int vertices, int directed)
{
    int degree[V] = {0};

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            if (graph[i][j] != 0)
            {
                degree[i]++;
                if (!directed)
                {
                    degree[j]++;
                }
            }
        }
    }

    int maxDegree = -1;
    int maxVertex = -1;
    for (int i = 0; i < vertices; i++)
    {
        if (degree[i] > maxDegree)
        {
            maxDegree = degree[i];
            maxVertex = i;
        }
    }

    printf("Dinh co bac cao nhat la: %d\n", maxVertex);
}

int main()
{
    int vertices, edges, directed;

    printf("Nhap so luong dinh: ");
    scanf("%d", &vertices);

    printf("Nhap 1 neu do thi co huong, 0 neu do thi vo huong: ");
    scanf("%d", &directed);

    int graph[V][V] = {0};

    printf("Nhap so luong canh: ");
    scanf("%d", &edges);

    printf("Nhap cac canh (dinh1, dinh2):\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        if (!directed)
        {
            graph[v][u] = 1;
        }
    }

    findMaxDegree(graph, vertices, directed);

    return 0;
}
