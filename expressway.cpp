#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,int>

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, c;
	cin >> n >> c;
	vector<vector<pll>> graph(n);
	vector<ll> ans(n,1e9);
	
	//init first highway 0 to 1
	graph[0].push_back({1,c});
	graph[1].push_back({0,c});
	ans[0] = 0; ans[1] = c;
	
	for(int i=2;i<n;i++){
		int m;
		cin >> m;
		ll minDis = INT_MAX;
		while(m--){
			//input edges connect to i
			ll a, d;
			cin >> a >> d;
			a--;
			graph[i].push_back({a,d});
			graph[a].push_back({i,d});
			//if connects to 0, save distance
			minDis = min(minDis, ans[a]+d);
		}
		ans[i] = minDis;
		
		//push shortest distance to pq
		priority_queue<pll, vector<pll>, greater<pll>> pq;
		pq.push({minDis,i});
		
		//dijkstra
		while(!pq.empty()){
			auto d = pq.top().first;
			auto pos = pq.top().second;
			pq.pop();
			
			if(ans[pos]<d) continue;
			for(auto to:graph[pos]){
				if (ans[to.first] > ans[pos]+to.second){
					ans[to.first] = ans[pos]+to.second;
					pq.push({to.second, to.first});
				}
			}
		}
		//answer shortest from 0 to 1
		cout << ans[1] << ' ';
	}
}
