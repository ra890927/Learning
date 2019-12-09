#include <bits/stdc++.h>
#define MAX_N 50 + 1
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    bool check = true;
    int num[MAX_N];
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> num[i];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(i != j && j != k && k != i){
                    if((num[i] - num[j]) % num[k] != 0){
                        check = false;
                        break;
                    }
                }
            }
            if(!check)
                break;
        }
        if(!check)
            break;
    }

    if(check) cout << "yes" << endl;
    else cout << "no" << endl;

    return 0;
}
