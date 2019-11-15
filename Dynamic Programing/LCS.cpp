#include <bits/stdc++.h>
#define MAX_N 1000 + 1
using namespace std;

string a, b;
int dp[MAX_N][MAX_N];

void LCS(){
	int N = a.length();
	int M = b.length();
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(a[i] == b[j])
				dp[i+1][j+1] = dp[i][j] + 1;
			else
				dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
		}
	}

	cout << dp[N][M] << endl;
}

int main(){
	cin >> a >> b;
	LCS();
	return 0;
}