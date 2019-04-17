#include <iostream>
#define MAX_N 1000
using namespace std;

int N, a[MAX_N], t[MAX_N];

int merge(int arr[], int temp[], int l, int m, int r){
	int count = 0, i, j, k = l;
	for(i = l; i <= r; i++)
		temp[i] = arr[i];
	
	for(i = l, j = m + 1; i <= m && j <= r; k++){
		if(temp[i] > temp[j]){
			count += m - i + 1;
			arr[k] = temp[j];
			j++;
		}
		else{
			arr[k] = temp[i];
			i++;
		}
	}
	
	if(i > m){
		while(j <= r){
			arr[k] = temp[j];
			j++;
			k++;
		}
	}
	else{
		while(i <= m){
			arr[k] = temp[i];
			i++;
			k++;
		}
	}
	
	return count;
}

int reversepair(int arr[], int temp[], int l, int r){
	if(l == r) return 0;
	int m = (l + r) / 2;
	int ln = reversepair(arr, temp, l, m);
	int rn = reversepair(arr, temp, m + 1, r);
	int mn = merge(arr, temp, l, m, r);
	return ln + rn + mn;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	cout << reversepair(a, t, 0, N - 1) << endl;
	return 0;
}