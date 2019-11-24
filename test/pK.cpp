#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, N;
    cin >> T;
    while(T--){
        cin >> N;
        int res, ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < N; i++){
            cin >> res;
            pq.push(res);
        }

        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }

        cout << ans << endl;
    }

    return 0;
}
