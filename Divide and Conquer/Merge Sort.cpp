#include <iostream>
#define MAX_N 1000 + 1
using namespace std;

int N, a[MAX_N];
void merge(int a[], int L, int mid, int R){
	int temp[N];
	int left = L, right = mid + 1, i = L;
	while((left <= mid) && (right <= R)){
		if(a[left] < a[right]){
			temp[i] = a[left];
			i++, left++;
		}
		else{
			temp[i] = a[right];
			i++, right++;
		}
	}
	
	while(left <= mid){
		temp[i] = a[left];
		i++, left++;
	}
	
	while(right <= R){
		temp[i] = a[right];
		i++, right++;
	}
	
	for(i = L; i <= R; i++)
		a[i] = temp[i];
}

void Merge_Sort(int a[], int L, int R){
	if(L < R){
		int mid = (L + R) / 2;
		Merge_Sort(a, L, mid);
		Merge_Sort(a, mid + 1, R);
		merge(a, L, mid, R);
	}
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	Merge_Sort(a, 0, N - 1);
	for(int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}