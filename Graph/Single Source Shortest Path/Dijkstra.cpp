#include <bits/stdc++.h>
#define MAX_N 10000 + 1
#define INF 1E9
using namespace std;

struct Edge{
	int to, cost;
};

struct Node{
	int v, k;
	
	bool operator > (const Node &other) const{
		return k > other.k;
	}
};

int N;
int d[MAX_N];
vector<Edge> ed[MAX_N];

Node make_node(int v, int k){
	Node ret;
	ret.v = v, ret.k = k;
	return ret;
}

void Dijkstra(){
	priority_queue<Node, vector<Node>, greater<Node>> pri_q;
	fill(d, d + N, INF);
	
	d[1] = 0;
	pri_q.push(make_node(1, d[1]));
	
	while(!pri_q.empty()){
		Node p = pri_q.top();
		pri_q.pop();
		
		int u = p.v;
		if(d[u] < p.k) continue;
		for(int i = 0; i < ed[u].size(); i++){
			Edge e = ed[u][i];
			if(d[e.to] > d[u] + e.cost){
				d[e.to] = d[u] + e.cost;
				pri_q.push(make_node(e.to, d[e.to]));
			}
		}
	}
}