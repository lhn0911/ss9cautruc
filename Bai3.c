#include <stdio.h>
#include <stdlib.h>
#define V 4

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node *arr[], int i, int j)
{
    Node *newNode = createNode(j);
    newNode->next = arr[i];
    arr[i] = newNode;

    newNode = createNode(i);
    newNode->next = arr[j];
    arr[j] = newNode;
}

int isCyclicUtil(Node *arr[], int v, int visited[], int parent)
{
    visited[v] = 1;
    Node *temp = arr[v];

    while (temp != NULL)
    {
        if (!visited[temp->data])
        {
            if (isCyclicUtil(arr, temp->data, visited, v))
            {
                return 1;
            }
        }
        else if (temp->data != parent)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int isCyclic(Node *arr[])
{
    int visited[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (isCyclicUtil(arr, i, visited, -1))
            {
                return 1;
            }
        }
    }
    return 0;
}

void printList(Node *arr[])
{
    for (int i = 0; i < V; i++)
    {
        Node *temp = arr[i];
        printf("%d: ", i);
        while (temp)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    Node *adjList[V];
    for (int i = 0; i < V; i++)
    {
        adjList[i] = NULL;
    }

    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 3, 0);

    printList(adjList);

    if (isCyclic(adjList))
    {
        printf("do thi co chu ky\n");
    }
    else
    {
        printf("do thi khong co chu ky\n");
    }

    return 0;
}
