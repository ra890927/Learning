#include <bits/stdc++.h>
#define MAX_V 1000 + 1
#define MAX_E 1000 + 1
#define INF 1E9
using namespace std;

struct Edge{
	int from, to, cost;
};

int V, E;
Edge ed[MAX_E];
int d[MAX_V], parent[MAX_V];

void negative_cycle(int s){
	int next = parent[s];
	cout << s;
	
	while(next != s){
		cout << "->" << next;
		next = parent[next];
	}
}

void bellman_ford(int start){
	fill(d, d + V + 1, INF);
	memset(parent, 0, sizeof(parent));
	
	d[start] = 0;
	parent[start] = start;
	
	for(int i = 1; i <= V - 1; i++){
		for(int j = 0; j < E; j++){
			Edge e = ed[j];
			if(d[e.to] > d[e.from] + e.cost){
				d[e.to] = d[e.from] + e.cost;
				parent[e.to] = e.from;
				if(i == V - 1) negative_cycle(e.to);
			}
		}
	}
}