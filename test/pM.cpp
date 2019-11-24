#include <bits/stdc++.h>
#define MAX_N 2000000000 + 1
using namespace std;

int m[100001], n[100001];
bool not_prime[MAX_N];
vector<int> prime;
void prime_(){
    for(int i = 2; i < MAX_N; i++){
        if(!not_prime[i]){
            prime.push_back(i);
            for(int j = 2; i * j < MAX_N; j++)
                not_prime[i * j] = true;
        }
    }
}

int64_t fast_power(int64_t a, int x, int mod){
    int64_t ret = 1, base = a;
    while(x){
        if(x & 1)
            ret = (ret * base) % mod;

        base = (base * base) % mod;
        x >>= 1;
    }

    return ret;
}

int main(){
    int64_t M, N, D, mod;

    cin >> M >> N >> D;

    prime_();
    mod = D;
    for(int i = M ; i > M - N; i--){
        int k = i;
        for(int j = 0; j < prime.size(); j++){
            while(k % prime[j] == 0){
                m[j]++;
                k /= prime[j];
            }
            if(!k) break;
        }
    }

    for(int i = 2; i <= N; i++){
        int k = i;
        for(int j = 0; j < prime.size(); j++){
            while(k % prime[j] == 0){
                n[j]++;
                k /= prime[j];
            }
            if(!k) break;
        }
    }

    int64_t ans = 1;
    for(int i = 0; i < prime.size(); i++){
        m[i] -= n[i];
        if(m[i] < 0) m[i] = 0;
        cout << prime[i] << " ";
        cout << m[i] << " " << n[i] << endl;
        ans = (ans * fast_power(prime[i], m[i], mod) % mod);
    }

    cout << ans << endl;
    return 0;
}
