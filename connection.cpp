#include <bits/stdc++.h>
using namespace std;
int n, k;

void find(vector<vector<int>> &graph, int degree, int node, set<int> &s){
	s.insert(node);
	if(degree == k) return;
	for(int to:graph[node])
		find(graph, degree+1, to, s);
}

int main(){
	int m;
	cin >> n >> m >> k;
	vector<vector<int>> graph(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int mf = 0;
	for(int i=0;i<n;i++){
		set<int> s;
		find(graph, 0, i, s);
		int si = s.size();
		mf = max(mf, si);
	}
	cout << mf;
}
