#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>
int r, c;


int main(){
	cin >> r >> c;
	int map[r][c];
	int dis[r][c];
	queue<pipii> pq;
	//input
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> map[i][j];
			dis[i][j] = INT_MAX;
			if(map[i][j]==1){
				//start from tile 1
				pq.push({1,{i,j}});
			}
		}
	}
	//dijkstra flood-fill??
	int distance;
	while(!pq.empty()){
		int x = pq.front().second.first;
		int y = pq.front().second.second;
		int d = pq.front().first;
		pq.pop();
		
		//if reach town 2, print and end program
		if(map[x][y]==2){
			cout << d;
			return 0;
		}
		
		if(dis[x][y]<d) continue;
		map[x][y] = 3; //tile walked is a wall
		dis[x][y] = d; //new distance to that tile
		
		//next condition
		int dx[] = {-1,1,0,0};
		int dy[] = {0,0,-1,1};
		for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && map[nx][ny] != 3) {
                if (dis[nx][ny] > d + 1) {
                    dis[nx][ny] = d + 1;
                    pq.push({d + 1, {nx, ny}});
                }
            }
        }
	}
}
