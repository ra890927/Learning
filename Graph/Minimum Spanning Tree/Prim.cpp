#include <bits/stdc++.h>
#define MAX_V 1000 + 1
#define INF 1E9
using namespace std;

struct edge{
	int to, cost;
};

struct node{
	int v, k;
	bool operator > (const node &other) const{
		return k > other.k;
	}
};

edge make_edge(int to, int cost){
	edge e;
	e.to = to, e.cost = cost;
	return e;
}

node make_node(int v, int k){
	node n;
	n.v = v, n.k = k;
	return n;
}

int V, E;
int parent[MAX_V];
vector<edge> G[MAX_V];

void Prim(){
	int d[MAX_V];
	bool used[MAX_V];
	priority_queue<node, vector<node>, greater<node>> pri_q;
	
	fill(d, d + V + 1, INF);
	memset(used, 0, sizeof(used));
	d[1] = 0;
	pri_q.push(make_node(1, d[1]));
	
	while(!pri_q.empty()){
		node p = pri_q.top();
		pri_q.pop();
		
		int u = p.v;
		if(d[u] < p.k) continue;
		used[u] = true;
		
		for(int i = 0; i < G[u].size(); i++){
			edge e = G[u][i];
			if(d[e.to] > d[u] + e.cost && !used[e.to]){
				d[e.to] = d[u] + e.cost;
				pri_q.push(make_node(e.to, d[e.to]));
			}
		}
	}
}