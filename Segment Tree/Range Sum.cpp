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

int Range_Sum(int ss, int se, int qs, int qe, int index){
	if(ss > qe || se < qs) return 0;
	if(ss == qs && se == qe) return seg[index];
	if(ss == se) return seg[index];
	int mid = (ss + se) / 2;
	return Range_Sum(ss, mid, qs, qe, 2*index+1) + Range_Sum(mid+1, se, qs, qe, 2*index+2);
}

void Range_Sum(int qs, int qe){
	if(qs > qe){
		cout << "Fail" << endl;
		return;
	}
	
	cout << Range_Sum(0, N-1, qs, qe, 0) << endl;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
	
	BuildTree(0, N-1, 0);
	int M = pow(2, ceil(log(N) / log(2)) + 1) - 1;
	while(true){
		int qs, qe;
		cin >> qs >> qe;
		Range_Sum(qs, qe);
	}
	return 0;
}