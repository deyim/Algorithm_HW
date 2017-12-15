#define GRAPHpfs GRAPHmst
static int fr[maxV];
static double *priority;

//Put the priority queue codes here.
#define P t->wt

//PQ
void Prim(Graph G, int st[], double wt[]){
	link t; int v,w;
	PQinit();
	priority = wt;
	for(v= 0 ; v < G->V; v++){
		st[v] = -1; fr[v] = -1;
	}
	fr[0] = 0; PQinsert(0);

	while(!PQempty()){
		v = PQdelmin();	st[v] = fr[v];
		for(t = G->adj[v]; t!= NULL; t = t->next)
			if(fr[w=t->v] == -1){
				wt[w] = P; PQinsert(w); fr[w] = v;
			}
			else if ((what3) && (P<wt[w])){
				wt[w] = P; PQdec(w); fr[w] = v;
			}
	}
}

//array
void Prim2(){
	int l, current, totalvisited, mincost;
	current = 1; d[current] = 0;
	totalvisited = 1; visited[current] = 1;

	while(totalvisited != v){
		for(i = 1; i <= v; i++){
			if((visited[i] == 0)&&(weight[current][i] != MAX_DIST))
				if(d[i]>weight[current][i]){
					what1
				}
		}
		mincost=MAX_DIST;
		for(i = 1; i<=v; i++){
			if((visitied[i]==0)&&(d[i]<mincost)){
				mincost= d[i]; current = i;
			}
		}
		visited[current] = 1;
		what2
	}
}





















