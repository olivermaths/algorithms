#include <stdlib.h>

typedef struct Graph Graph;

extern Graph *createGraph(void);
extern void addUndirectEdge(Graph *graph, int src, int dest);
extern void addDirectEdge(Graph *graph, int src, int dest);
extern void printGraphAdjList(Graph *graph);
extern void bsf(Graph *graph, int startVext);