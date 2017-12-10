struct AdjListNode{
	int dest;
	int weight;
	struct AdjListNode *next;
};

struct AdjList{
	struct AdjListNode *head;
};

struct Graph{
	int V;
	struct AdjList* array;
}

struct MinHeapNode {int v; int dist;};

struct MinHeap {
	int size;
	int capacity;
	int *pos;
	struct MinHeapNode **array;
}

struct MinHeapNode* newMinHeapNode(int v, int dist){
	struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
	minHeapNode->v = v;
	minHeapNode -> dist = dist;
	return minHeapNode;
}

struct MinHeap* createMinHeap(int capacity){
	struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	minHeap->pos = (int *)malloc(capacity*sizeof(int));
	minHeap->size = 0;
	minHeap->capacity = capacity;
	minHeap->arrayt = (struct MinHeapNode**)malloc(capacity*sizeof(struct MinHeapNode*));

	return minHeap;
}


void dijkstra(struct Graph* graph, int src)
{
	int V = graph->V;
	int dist[N_MAX_VERTICES];

	struct MinHeap* minHeap = createMinHeap(V);
	for(int v = 0; v < V ; ++v){
		dist[v] = INT_MAX;
		minHeap->array[v] = newMinHeapNode(v, dist[v]);
		minHeap->pos[v] = v;
	}
	minHeap->size = V;

	dist[src] = 0;
	decreaseKey(minHeap, src, dist[src]); 

	while(!isEmpty(minHeap)){
		struct MinHeapNode * minHeapNode = extractMin(minHeap);
		int u = minHeapNode->v;
		struct AdjListNode* pCrawl = graph->array[u].head;
		while(pCral != NULL){
			int v = pCrawl->dest;
			if(isInMinHeap(minHeap, v) && dist[u] != INT_MAX && __(here)__ < dist[v]){
				dist[v] = __(here)__;
				decreaseKey(minHeap, v, dist[v]);
			}
			pCrawl = pCrawl->next;
		}
	}
	printArr(dist, V);
}
