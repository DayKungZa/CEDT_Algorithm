#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>
int main(){
	int r, c;
	cin >> r >> c;
	int cost[r][c];
	int ans[r][c];
	//input section
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			int a;
			cin >> a;
			cost[i][j] = a;
			ans[i][j] = -1;
		}
	//dijkstra
	ans[0][0] = 0;
	priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
	//initial condition
	int x=0, y=0;
	if(x+1<r  && ans[x+1][y]==-1) pq.push({ans[x][y]+cost[x+1][y], {x+1,y}});
	if(y+1<c  && ans[x][y+1]==-1) pq.push({ans[x][y]+cost[x][y+1], {x,y+1}});
	//go through all edges
	while(!pq.empty()){
		//get value
		auto top = pq.top();
		pq.pop();
		int d = top.first;
		int x = top.second.first;
		int y = top.second.second;
		if(ans[x][y]!=-1) continue;
		//insert value to ans
		ans[x][y] = d;
		//insert nearby tiles to pq
		if(x-1>=0 && ans[x-1][y]==-1) pq.push({ans[x][y]+cost[x-1][y], {x-1,y}});
		if(x+1<r  && ans[x+1][y]==-1) pq.push({ans[x][y]+cost[x+1][y], {x+1,y}});
		if(y-1>=0 && ans[x][y-1]==-1) pq.push({ans[x][y]+cost[x][y-1], {x,y-1}});
		if(y+1<c  && ans[x][y+1]==-1) pq.push({ans[x][y]+cost[x][y+1], {x,y+1}});
	}
	//output
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			cout << ans[i][j] << ' ';
		cout << '\n';
	}
}
