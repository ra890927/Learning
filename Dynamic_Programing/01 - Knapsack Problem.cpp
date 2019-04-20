#include <iostream>
#include <algorithm>
#define MAX_N 1000 + 1
using namespace std;

int N, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N][MAX_N];

void solve(){
	for(int i = 0; i < N; i++)
		for(int j = 0; j <= W; j++){
			dp[i+1][j] = dp[i][j];
			if(j >= w[i])
				dp[i+1][j] = max(dp[i+1][j], dp[i][j-w[i]] + v[i]);
		}
		
	cout << dp[N][W] << endl;
}

int main(){
	cin >> N >> W;
	for(int i = 0; i < N; i++)
		cin >> w[i] >> v[i];
	solve();
	return 0;
}