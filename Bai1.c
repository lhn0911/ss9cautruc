#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define V 4

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    int isDirected;
    int adjMatrix[V][V];
    Node *adjList[V];
} Graph;

Graph *createGraph(int vertices, int isDirected)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->isDirected = isDirected;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
        graph->adjList[i] = NULL;
    }
    return graph;
}

Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    if (!graph->isDirected)
    {
        graph->adjMatrix[dest][src] = 1;
    }

    Node *newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    if (!graph->isDirected)
    {
        newNode = createNode(src);
        newNode->next = graph->adjList[dest];
        graph->adjList[dest] = newNode;
    }
}

void printAdjMatrix(Graph *graph)
{
    printf("Ma tran ke:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printAdjList(Graph *graph)
{
    printf("Danh sach ke:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("%d: ", i);
        Node *temp = graph->adjList[i];
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    int numVertices, isDirected;
    printf("Nhap so dinh: ");
    scanf("%d", &numVertices);
    printf("Do thi co huong? (1: Co huong, 0: Vo huong): ");
    scanf("%d", &isDirected);

    Graph *graph = createGraph(numVertices, isDirected);

    int edges, src, dest;
    printf("Nhap so luong canh: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++)
    {
        printf("Nhap canh (dinh nguon va dinh dich): ");
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printAdjMatrix(graph);

    printAdjList(graph);

    return 0;
}
