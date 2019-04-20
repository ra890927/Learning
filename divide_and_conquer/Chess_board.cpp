#include <iostream>
#include <vector>
#define MAXN 349525
using namespace std;

struct Rep{
	int x[3][2];
};

vector<Rep> rep;

void chess_board(int tr, int tc, int dr, int dc, int size){
	if(size == 2){
		int k = 0;
		Rep t;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(tr + i != dr || tc + j != dc){
					t.x[k][0] = tr + i;
					t.x[k][1] = tc + j;
					k++;
				}
		rep.push_back(t);
		return;			
	}
	
	int sz = size / 2;
	
	if(dr < tr + sz && dc < tc + sz){
		int k = 0;
		Rep t;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(i != 0 || j != 0){
					t.x[k][0] = tr + sz + i - 1;
					t.x[k][1] = tc + sz + j - 1;
					k++;
				}
		rep.push_back(t);
        chess_board(tr, tc, dr, dc, sz);
	}
    else
		chess_board(tr, tc, tr+sz-1, tc+sz-1, sz);
        
    if(dr < tr + sz && dc >= tc + sz){
    	int k = 0;
		Rep t;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(i != 0 || j != 1){
					t.x[k][0] = tr + sz + i - 1;
					t.x[k][1] = tc + sz + j - 1;
					k++;
				}
		rep.push_back(t);
    	chess_board(tr, tc+sz, dr, dc, sz);
	}
    else
    	chess_board(tr, tc+sz, tr+sz-1, tc+sz, sz);
    	
    if(dr >= tr + sz && dc < tc + sz){
    	int k = 0;
		Rep t;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(i != 1 || j != 0){
					t.x[k][0] = tr + sz + i - 1;
					t.x[k][1] = tc + sz + j - 1;
					k++;
				}
		rep.push_back(t);
    	chess_board(tr+sz, tc, dr, dc, sz);
	}
	else
		chess_board(tr+sz, tc, tr+sz, tc+sz-1, sz);
	
	if(dr >= tr + sz && dc >= tc + sz){
		int k = 0;
		Rep t;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(i != 1 || j != 1){
					t.x[k][0] = tr + sz + i - 1;
					t.x[k][1] = tc + sz + j - 1;
					k++;
				}
		rep.push_back(t);
		chess_board(tr + sz, tc + sz, dr, dc, sz);
	}
	else
		chess_board(tr+sz, tc+sz, tr+sz, tc+sz, sz);
}

void Report(){
	for(int i = 0; i < rep.size(); i++){
		cout << "Report(" << 
		rep[i].x[0][0] <<","<<
		rep[i].x[0][1] <<","<<
		rep[i].x[1][0] <<","<<
		rep[i].x[1][1] <<","<<
		rep[i].x[2][0] <<","<<
		rep[i].x[2][1] <<");"<< endl;
	}
}

int main(){
	int N, X, Y;
	cin >> X >> Y >> N;
	chess_board(1, 1, X, Y, N);
	Report();
}
