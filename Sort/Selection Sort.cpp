#include <iostream>
#include <algorithm>
#define MAX_N 1000 + 1
using namespace std;

int N, a[MAX_N];
void Selection_Sort(){
	for(int i = 0; i < N; i++){
		int res = a[i], k = i;
		for(int j = i; j < N; j++){
			if(res > a[j]){
				res = a[j];
				k = j;
			}
		}
		swap(a[i], a[k]);
	}
	
	for(int s = 0; s < N; s++)
		cout << a[s] << " ";
	cout << endl;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	Selection_Sort();
	return 0;
}