#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	//input start nodes
	vector<int> start(k);
	for(int i=0;i<k;i++) cin >> start[i];
	
	//input node time
	vector<int> time(n);
	for(int i=0;i<n;i++) cin >> time[i];
	
	//input connecting edges
	vector<vector<int>> path(n);
	for(int i=0;i<m;i++){
		int from, to;
		cin >> from >> to;
		path[from].push_back(to);
		path[to].push_back(from);
	}
	
	//dijkstra setup
	vector<int> ans(n,-1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	
	//init pq starting node
	for(auto s:start){
		ans[s] = time[s];
		for(auto to:path[s])
			pq.push({ans[s]+time[to],to});
	}
	
	//walk through the pq
	while(!pq.empty()){
		auto top = pq.top();
		int d = top.first;
		int pos = top.second;
		pq.pop();
		if(ans[pos]!=-1) continue;
		ans[pos] = d;
		for(auto to:path[pos]){
			if (ans[to] == -1)
				pq.push({ans[pos]+time[to], to});
		}
	}
	
	//find the max node
	int mx = 0;
	for(int t:ans){
	//	cout << t << ' ';
		mx = max(mx, t);
	}
	//output
	cout << mx;
	
}
