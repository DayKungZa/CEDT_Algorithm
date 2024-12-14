#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<double>> &graph, int n){
	for(int k=0;k<n-1;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				  graph[i][j] = max(graph[i][k]*graph[k][j], graph[i][j]);
			}
		}
	}
	for(int k=0;k<n;k++){
	  if(graph[k][k]>1) return true;
	}
	return false;
}

int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		vector<vector<double>> graph(n, vector<double>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin >> graph[i][j];
		
		if(check(graph,n)) cout << "YES\n";
		else cout << "NO\n";
	}
}

