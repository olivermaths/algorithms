#include "graph.h"

struct Node
{
    int vertex;
    struct Node *next;
};

struct Node *createNode(int vertex)
{
    struct Node *node = malloc(sizeof node);
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

typedef struct Graph
{
    int numVertices;
    struct Node **adjList;

} Graph;

Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof graph);
    graph->numVertices = vertices;
    graph->adjList = malloc(sizeof(struct Node *) * vertices);

    for (short i = 0; i < vertices; i++)
    {
        graph->adjList[i] = NULL;
    }

    return graph;
}

void addUndirectEdge(Graph *graph, int src, int dest)
{
    struct Node *src_node = createNode(src);
    struct Node *dest_node = createNode(dest);

    // dest to src
    src_node = graph->adjList[dest];
    graph->adjList[dest] = src_node;

    // src to dest
    dest_node = graph->adjList[src];
    graph->adjList[src] = src_node;
}
void addDirectEdge(Graph *graph, int src, int dest)
{
    struct Node *dest_node = createNode(dest);

    // src to dest
    dest_node = graph->adjList[src];
    graph->adjList[src] = dest_node;
}

void printGraphAdjList(Graph *graph)
{

    for (int i = 0; i < graph->numVertices; i++)
    {

        struct Node *temp = graph->adjList[i];
        printf("\n");
        while (temp)
        {
            printf("%d, ", temp->vertex);
            temp = temp->next;
        }
    }
}
