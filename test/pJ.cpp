#include <bits/stdc++.h>
#define MAX_N 15 + 1
#define INF 1e9
using namespace std;

int T, N, L;
string s[MAX_N];

void OR(string &a, string &b){
	for(int i = 0; i < L; i++){
		if(a[i] == '1' || b[i] == '1')
			a[i] = '1';
	}
}

bool check(string s){
	bool check = true;
	for(int i = 0; i < L; i++){
		if(s[i] == '0'){
			check = false;
			break;
		}
	}

	return check;
}

void init(string &s){
	for(int i = 0; i < L; i++)
		s[i] = '0';
}

int main(){
	cin >> T;
	while(T--){
		string res;
		cin >> L >> N;
		init(res);
		cout << res << endl;

		for(int i = 0; i < N; i++)
			cin >> s[i];

		int ans = INF;
		for(int i = 1; i < (N << 1); i++){
			int cnt = 0;
			for(int j = 0; j < N; j++){
				if((i >> j) & 1){
					cnt++;
					OR(res, s[j]);
					cout << res << endl;
				}
			}

			if(check(res))
				ans = min(ans, cnt);

			init(res);
		}

		cout << ans << endl;
	}

	return 0;
}