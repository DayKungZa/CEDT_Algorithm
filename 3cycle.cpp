#include <iostream>
#include <vector>
using namespace std;

bool check(vector<vector<int>> &edges, bool visited[], int start, int parent){
	visited[start] = true;
	for(auto next : edges[start]){
		if(!visited[next]){
			if(check(edges, visited, next, start))
				return true;
		}
		else if(next != parent)
			return true;
	}
	return false;
}

bool bigcheck(vector<vector<int>> &edges, int nodes){
	bool visited[nodes] = {false};
	for(int i=0;i<nodes;i++){
	  if(!visited[i])
  		if(check(edges, visited, i, -1))
  			return true;
	}
	return false;
}


int main(){
	int t;
	cin >> t;
	while(t--){
		int n, e;
		int a, b;
		cin >> n >> e;
		vector<vector<int>> g(n);
		while(e--){
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		if(bigcheck(g, n)) cout << "YES\n";
		else cout << "NO\n";
	}
}
