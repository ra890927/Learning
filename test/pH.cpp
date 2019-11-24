#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, n;
    int64_t a, b;
    cin >> T;
    while(T-- > 0){
        cin >> n;
        b = n + 1;
        a = b ^ (b * n);
        cout << a << endl;
    }
}
