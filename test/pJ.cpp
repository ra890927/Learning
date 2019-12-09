#include <bits/stdc++.h>
#define MAX_N 500 + 1
using namespace std;

int T, L, N, ans;
struct Bin{
    bool arr[MAX_N];
    int cnt;
    bool f;
};

Bin used[MAX_N], res;

void OR(int k){
    for(int i = 0; i < L; i++)
        res.arr[i] |= used[k].arr[i];
}

bool cmp(Bin a, Bin b){
    if(a.cnt > b.cnt) return true;
    else if(a.cnt == b.cnt)
        for(int i = 0; i < L; i++){
            if(a.arr[i]) return true;
            if(b.arr[i]) return false;
        }
    else
        return false;
}

void Cnt(int j){
    int cnt = 0;
    for(int i = 0; i < L; i++){
        if(res.arr[i] != used[j].arr[i]) cnt++;
    }
    used[j].cnt = cnt;
}

void print(){
            for(int i = 0; i < N; i++){
            for(int j = 0; j < L; j++)
                printf("%d", used[i].arr[j]);
            puts("");
        }
}

void print_r(){
    for(int i = 0; i < L; i++)
        cout << res.arr[i];
    cout << endl;
}

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < L; j++)
            used[i].arr[j] = false;
        used[i].f = false;
    }
    for(int i = 0; i < L; i++)
        res.arr[i] = false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    bool flag;
    cin >> T;
    while(T--){
/*
        for(int i = 0; i < N; i++)
            memset(used[i].arr, 0, sizeof(used[i].arr));
        memset(res.arr, 0, sizeof(res.arr));
*/
        init();
        flag = true;
        ans = 0;
        cin >> L >> N;
        string s;

        for(int i = 0; i < N; i++){
            cin >> s;
            for(int j = 0; j < L; j++){
                used[i].arr[j] = (s[j] - '0');
            }
        }

        for(int i = 0; i < L; i++){
            int cnt = 0, label = 0;
            for(int j = 0; j < N; j++){
                if(used[j].arr[i]){
                    label = j;
                    cnt++;
                }
            }
            if(!cnt){
                cout << -1 << endl;
                flag = false;
                break;
            }
            else if(cnt == 1){
                OR(label);
                used[label].f = true;
                ans++;
            }
        }
        if(flag){
            bool ch = true;
            while(ch){
                //print_r();
                ch = false;
                for(int i = 0; i < N ;i++)
                    Cnt(i);
                sort(used, used + N, cmp);
                for(int i = 0; i < N; i++){
                    if(!used[i].f){
                        OR(i);
                        used[i].f = true;
                        ans++;
                        break;
                    }
                }
                for(int i = 0; i < L; i++)
                    if(!res.arr[i]) ch = true;
            }
            cout << ans << endl;
        }


    }
}
/*
5
3 3
100
011
111
5 6
10000
01001
01110
00111
10110
00101
6 7
000010
011000
100100
001000
000010
010000
110001
7 6
1001001
1001000
0001101
0010110
0110011
0100001
2 1
01
*/
