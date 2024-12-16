#include <stdio.h>
#include <stdlib.h>

#define V 4

void initAdjMatrix(int adjMatrix[V][V], int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(int adjMatrix[V][V], int src, int dest)
{
    adjMatrix[src][dest] = 1;
    adjMatrix[dest][src] = 1;
}

void printAdjMatrix(int adjMatrix[V][V], int vertices)
{
    printf("Ma tran ke:\n");
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int vertices, edges, src, dest;

    printf("Nhap so luong dinh: ");
    scanf("%d", &vertices);

    int adjMatrix[V][V];
    initAdjMatrix(adjMatrix, vertices);

    printf("Nhap so luong canh: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Nhap canh %d (dinh 1 va dinh 2): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(adjMatrix, src, dest);
    }

    printAdjMatrix(adjMatrix, vertices);

    return 0;
}
