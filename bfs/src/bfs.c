#include <stdlib.h>
#include <stdio.h>
#include "queue/queue.h"
#include "stack/stack.h"

struct node
{
    int vertex;
    struct node *next;
};

struct Graph
{
    int numVertices;
    struct node **adjLists;
    int *visited;
};

struct node *createNode(int vertex)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(struct node *));
    graph->visited = malloc(vertices * sizeof(int));

    for (short i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{

    struct node *src_node = createNode(src);
    struct node *dest_node = createNode(dest);

    dest_node->next = graph->adjLists[src];
    graph->adjLists[src] = dest_node;

    src_node->next = graph->adjLists[dest];
    graph->adjLists[dest] = src_node;
}

void addDirectEdge(struct Graph *graph, int src, int dest)
{
    struct node *dest_node = createNode(dest);

    // src to dest
    dest_node->next = graph->adjLists[src];
    graph->adjLists[src] = dest_node;
}

void printGraph(struct Graph *graph)
{

    for (int i = 0; i < graph->numVertices; i++)
    {

        struct node *temp = graph->adjLists[i];
        printf("\n");
        while (temp)
        {
            printf("%d, ", temp->vertex);
            temp = temp->next;
        }
    }
}

int bfs(struct Graph *graph, int startVertex, int *prev)
{

    Queue *queue = createQueue();
    enqueue(queue, startVertex);

    graph->visited[startVertex] = 1;

    while (!isEmpty(queue))
    {
        int element = dequeue(queue);
        struct node *temp = graph->adjLists[element];
        printf("\nvisiting %d: ", element);

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0)
            {

                printf("%d, ", adjVertex);
                enqueue(queue, adjVertex);
                graph->visited[adjVertex] = 1;
                prev[adjVertex] = element;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    return 0;
}

void DFS(struct Graph *graph, int vertex, int *prev)
{

    struct node *temp = graph->adjLists[vertex];
    graph->visited[vertex] = 1;
    printf("\nvisiting: %d\n", vertex);

    while (temp)
    {
        int neighbour = temp->vertex;
        if (graph->visited[neighbour] == 0)
        {
            prev[neighbour] = vertex;
            DFS(graph, neighbour, prev);
        }
        temp = temp->next;
    }
}

void reconstructPath(int *prev, int n, int s)
{
    Stack *stack = createStack();
    push_back(stack, s);
    int index = s;

    while (1)
    {
        if (prev[index] >= 0)
        {
            push_back(stack, prev[index]);
            index = prev[index];
        }
        else
        {
            break;
        }
    }

    printf("\npath: ");
    for (int i = 0; i < get_capacity(stack); i++)
    {
        printf("%d, ", s_getElement(stack, i));
    }
    printf("\n");
}

int main(void)
{
    struct Graph *graph = createGraph(7);
    int prev[7] = {-1, -1, -1, -1, -1, -1};
    addDirectEdge(graph, 0, 1);
    addDirectEdge(graph, 1, 2);
    addDirectEdge(graph, 2, 3);
    addDirectEdge(graph, 3, 4);
    addDirectEdge(graph, 4, 2);
    addDirectEdge(graph, 2, 0);
    addDirectEdge(graph, 5, 3);
    addDirectEdge(graph, 1, 6);
    addDirectEdge(graph, 2, 6);

    printGraph(graph);
    bfs(graph, 0, prev);
    printf("\nvisited: ");

    for (int i = 0; i < 7; i++)
    {
        printf("%d,  ", graph->visited[i]);
    }

    printf("\n");
    for (int i = 0; i < 7; i++)
    {
        printf("%d,  ", prev[i]);
    }
    printf("\n");
    reconstructPath(prev, 7, 6);
    printf("\n");

    return 0;
}

/*


Enqueue elements given a start vertex, without repeting the element in the queue



void enqueueGraph(struct Graph *graph, int startVertex)
{
    Queue *queue = createQueue();
    enqueue(queue, startVertex);

    for (int i = 0; i < queue->tail; i++)
    {

        int element = get_element(queue, i);

        struct node *temp = graph->adjLists[element];

        while (temp)
        {
            int currentVertex = temp->vertex;

            if (graph->visited[currentVertex] == 0)
            {
                enqueue(queue, currentVertex);
                graph->visited[currentVertex] = 1;
            }
            temp = temp->next;
        }
    }
    dequeue(queue);

    printQueue(queue);
} */