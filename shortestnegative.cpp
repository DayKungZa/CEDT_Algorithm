#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){
	int n, e, s;
	cin >> n >> e >> s;
	vector<pii> path;
	int cost[n][n] = {};
	while(e--){
		int from, to, w;
		cin >> from >> to >> w;
		path.push_back({from,to});
		cost[from][to] = w;
	}
	vector<int> = dis(n,1e9);
	dis[s] = 0;
	//bellman-ford
	for(int i=0;i<n-1;i++){
		for(auto edge:path){
			if (dis[edge.second] > dis[edge.first]+cost[edge.first][edge.second]){
				dis[edge.second] = dis[edge.first]+cost[edge.first][edge.second];
			}
		}
	}
	//check negative
	bool check = 0;
	for(auto edge:path){
		if (dis[edge.second] > dis[edge.first]+cost[edge.first][edge.second]){
			check = true;
			break;
		}
	}
	if(check) cout << -1;
	else for(int x:dis) cout << x << ' ';
}
