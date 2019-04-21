#include <iostream>
#include <algorithm>
#define MAX_N 1000 + 1
using namespace std;

int N, a[MAX_N];
void Bubble_Sort(){
	for(int i = N-1; i > 0; i--)
		for(int j = 0; j < i; j++)
			if(a[j] > a[j+1]) swap(a[j], a[j+1]);

	for(int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	Bubble_Sort();
	return 0;
}