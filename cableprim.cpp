#include <bits/stdc++.h>
using namespace std;
#define piipi pair<int,pair<int,int>>
#define pii pair<int,int>
int main(){
	int n;
	cin >> n;
	vector<vector<pii>> graph(n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int a;
			cin >> a;
			graph[i].push_back({a,j});
			graph[j].push_back({a,i});
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	bool visited[n] = {};
	int distance = 0;
	int edgeCount = 0;
	
	//prim's init
	for(auto edge:graph[0])
		pq.push({edge.first, edge.second});
	visited[0] = 1;
		
	while(!pq.empty()){
		int d = pq.top().first;
		int pos = pq.top().second;
		pq.pop();
		
		if(edgeCount==n-1) break;
		if(visited[pos]) continue;
		
		visited[pos] = true;
		distance += d;
		edgeCount++;
		
		for(auto edge:graph[pos]){
			if(!visited[edge.second])
				pq.push({edge.first, edge.second});
		}
	}
	cout << distance;
}
