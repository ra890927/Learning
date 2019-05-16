#include <iostream>
#include <cmath>
#define MAX_N 1024
#define MAX_T 2047
using namespace std;

int N, arr[MAX_N], seg[MAX_T];
void BuildTree(int left, int right, int index){
	if(left == right){
		seg[index] = arr[left];
		return;
	}
	
	int mid = (left + right) / 2;
	BuildTree(left, mid, index * 2 + 1);
	BuildTree(mid + 1, right, index * 2 + 2);
	seg[index] = seg[index * 2 + 1] + seg[index * 2 + 2];
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	
	BuildTree(0, N-1, 0);
	int M = pow(2, ceil(log(N) / log(2)) + 1) - 1;
	for(int i = 0; i < M; i++)
		cout << i << " " << seg[i] << endl;
	return 0;
}