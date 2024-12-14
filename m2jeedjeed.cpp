#include <bits/stdc++.h>
using namespace std;
#define pipii pair<int,pair<int,int>>

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r,c;
	cin >> r >> c;
	bool map[r][c] = {};
	bool itm[r][c] = {};
	int item = 0;
	//input
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
		  int a; cin >> a;
			if(a>0) map[i][j] = true;
			//count the total no. items
			if(a==2){
				item++;
			  itm[i][j] = true;
			}
		}
	}
	//init queue
	queue<pipii> q;
	q.push({0,{0,0}});
	
	//init item conditions
	int itemGet = 0;
	long long distance = 0;
	
	//bfs
	while(!q.empty()){
		int x = q.front().second.first;
		int y = q.front().second.second;
		int d = q.front().first;
		q.pop();
		
		//if on item tile, get item and add total distance
		if(itm[x][y]){
			itemGet++;
			distance += d;
			if(itemGet==item)
				break; //break when collected all items
		}
		//rewrite distance and block the walked tile
		map[x][y] = 0;
		
		//move to next tile
		int dx[4] = {-1,1,0,0};
		int dy[4] = {0,0,-1,1};
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			//check border & check if tile is blocked
			if(nx>=0 && nx<r && ny>=0 && ny<c && map[nx][ny])
                q.push({d+1, {nx, ny}});
		}
	}
	//output distance*2 bc go back and forth
	cout << distance*2;
}
