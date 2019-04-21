#include <iostream>
#define MAX_N 1000 + 1
using namespace std;

int N, a[MAX_N];
void Insertion_Sort(){
	int j, insert;
	for(int i = 1; i < N; i++){
		insert = a[i];
		for(j = i-1; j >= 0; j--){
			if(insert < a[j])
				a[j+1] = a[j];
			else
				break;
		}
		a[j+1] = insert;
	}
	
	for(int i = 0; i < N; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> a[i];
	Insertion_Sort();
	return 0;
}