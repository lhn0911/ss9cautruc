#include <stdio.h>
#include <stdlib.h>

#define V 4

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    int items[V];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == V - 1)
    {
        printf("Hang doi day\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Hang doi rong\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

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

void BFS(Node *arr[], int start, int visited[], int vertices)
{
    Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    while (!isEmpty(&q))
    {
        int v = dequeue(&q);
        printf("%d ", v);

        Node *temp = arr[v];
        while (temp != NULL)
        {
            if (!visited[temp->data])
            {
                visited[temp->data] = 1;
                enqueue(&q, temp->data);
            }
            temp = temp->next;
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

    Node *adjList[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adjList[i] = NULL;
    }

    printf("Nhap cac canh (dinh1, dinh2):\n");
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adjList, u, v);
    }

    int start;
    printf("Nhap dinh bat dau de thuc hien duyet BFS: ");
    scanf("%d", &start);

    int visited[vertices];
    for (int i = 0; i < vertices; i++)
    {
        visited[i] = 0;
    }

    printf("Thu tu cac dinh duyet theo BFS tu dinh %d:\n", start);
    BFS(adjList, start, visited, vertices);

    return 0;
}
