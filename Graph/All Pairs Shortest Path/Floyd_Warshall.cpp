int V;
int d[MAX_N][MAX_N];
void Floyd_Warshall(){
	for(int k = 0; k < V; k++){
		for(int i = 0; i < V; i++){
			for(int j = 0; j < V; j++)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
		}
	}
}