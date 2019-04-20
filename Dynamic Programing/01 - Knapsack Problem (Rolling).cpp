#include <iostream>
#define MAX_N 10000 + 1
using namespace std;

int N, W;
int v[MAX_N], w[MAX_N], dp[101];

void solve(){
	for(int i = 0; i < N; i++)
		for(int j = W; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
	
	cout << dp[W] << endl;
}

int main(){
	cin >> N >> W;
	for(int i = 0; i < N; i++)
		cin >> w[i] >> v[i];
	solve();
	return 0;
}