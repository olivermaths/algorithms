#include <stdio.h>
#include "queue.h"

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

void DFS(struct Graph *graph, int startVertex)
{

    struct node *temp = graph->adjLists[startVertex];
    graph->visited[startVertex] = 1;

    while (temp)
    {
        int neighbour = temp->vertex;
        if (graph->visited[neighbour] == 0)
        {
            DFS(graph, neighbour);
        }
        temp = temp->next;
    }
}

int main() {}