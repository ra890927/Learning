#include <iostream>
#include <algorithm>
#define MAX_N 1000 + 1
using namespace std;

int N, a[MAX_N];
void Quick_Sort(int a[], int L, int R){
	if(L < R){
		int i = L, j = R + 1;
		while(true){
			while((i < R) && (a[++i] < a[L]));
			while((j > L) && (a[--j] > a[L]));
			if(i >= j) break;
			swap(a[i], a[j]);
		}
		swap(a[L], a[j]);
		Quick_Sort(a, L, j - 1);
		Quick_Sort(a, j + 1, R);
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	Quick_Sort(a, 0, N - 1);
	for(int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}