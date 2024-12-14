#include <bits/stdc++.h>
using namespace std;
#define pipii pair<int, pair<int,int>>

int main(){
	int r, c, day;
	cin >> r >> c >> day;
	int map[r][c];
	int cnt = 0;
	queue<pipii> q;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> map[i][j];
			if(map[i][j]==1)
				q.push({0,{i,j}});
		}
	}
	while(!q.empty()){
		int d = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if(map[x][y]==2) continue;
		if(d>day) break;
		cnt++;
		map[x][y] = 2;
		//cout << cnt << ' ' << d << ' ' << x << y << endl;
		if(d<day){
			if(x+1<r && map[x+1][y]==0) q.push({d+1,{x+1,y}});
			if(x>0   && map[x-1][y]==0) q.push({d+1,{x-1,y}});
			if(y+1<c && map[x][y+1]==0) q.push({d+1,{x,y+1}});
			if(y>0   && map[x][y-1]==0) q.push({d+1,{x,y-1}});
		}
	}
	cout << cnt;
}
