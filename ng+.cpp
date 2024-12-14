#include <bits/stdc++.h>
using namespace std;
#define MOD 100000007 

int main(){
	int r, c;
	cin >> r >> c;
	bool map[r+2][c+2];
	int firstline[r+2] = {};
	vector<vector<int>> x(r+2,vector<int>(c+2,0)); //right up
	vector<vector<int>> y(r+2,vector<int>(c+2,0)); //right
	vector<vector<int>> z(r+2,vector<int>(c+2,0)); //right down
	
	
	for(int i=0;i<r+1;i++) {map[i][0] = 1; map[i][c+1] = 1;}
	for(int j=0;j<c+2;j++) {map[0][j] = 1;}
	
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin >> map[i][j];
		}
	}
	
	//init first col
	for(int i=1;i<=c;i++){
		firstline[i] = map[i][1]? 0:1;
	}
	//init second col
	for(int i=1;i<=c;i++){
		if(map[i][2]) continue;
		x[i][2] = firstline[i+1];
		y[i][2] = firstline[i];
		z[i][2] = firstline[i-1];
	}
	
	for(int j=3;j<=c;j++){
		for(int i=1;i<=r;i++){
			if(map[i][j]) continue;
			x[i][j] = (y[i+1][j-1] + z[i+1][j-1])%MOD;
			y[i][j] = (x[i][j-1]   + z[i][j-1])  %MOD;
			z[i][j] = (x[i-1][j-1] + y[i-1][j-1])%MOD;
		}
	}
	/*
	//check
	for(int i=0;i<r+2;i++){
		for(int j=0;j<=c;j++)
			cout << x[i][j] << y[i][j] << z[i][j] << ' ';
		cout << '\n';
	}
	//*/
	//output
	int ans = 0;
	for(int i=1;i<=r;i++){
		ans = (ans+(x[i][c] + y[i][c] + z[i][c])%MOD)%MOD;
	}
	cout << ans%MOD;
}

/*
3 5
0 0 0 1 0
0 0 0 0 0
0 1 1 0 0

*/



