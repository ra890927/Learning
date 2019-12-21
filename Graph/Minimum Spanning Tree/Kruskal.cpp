#include <bits/stdc++.h>
#define MAX_V 1000 + 1
#define MAX_E 10000 + 1
#define INF 1E9
using namespace std;

struct edge{
	int from, to, cost;
	bool operator < (const edge &other) const{
		return cost < other.cost;
	}
};

int V, E;
int parent[MAX_V];
edge G[MAX_E];

edge make_edge(int from, int to, int cost){
	edge e;
	e.from = from, e.to = to, e.cost = cost;
	return e;
}

void unite(int from, int to){
	parent[to] = from;
}

void init(){
	for(int i = 1; i <= V; i++)
		parent[i] = i;
}

int find(int x){
	if(x == parent[x]) return x;
	return find(parent[x]);
}

void Kruskal(){
	init();
	sort(G, G + E);
	
	for(int i = 0; i < E; i++){
		edge e = G[i];
		if(find(e.from) != find(e.to))
			unite(e.from, e.to);
	}
}