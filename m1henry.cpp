#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define pipii pair<int,pair<int,int>>

int find(vector<int> &parent, int a){
	while(parent[a]!=-1)
		a = parent[a];
	return a;
}

bool cycleToAdd(vector<int> &parent, int a, int b){
	int na = find(parent,a);
	int nb = find(parent,b);
	if(na==nb) return 0; //if it makes a cycle, no use
	
	parent[na] = nb; //connect node - redirect parent
	return 1;
}

int main(){
	int n, m; 
	cin >> n >> m;
	vector<pipii> path;
	while(m--){
		int c, a, b;
		cin >> c >> a >> b;
		a--; b--;
		path.push_back({c,{a,b}});
	}
	sort(path.begin(),path.end());
	
	//kruskal
	int edgeCount = 0;
	int sum = 0;
	vector<int> parent(n,-1);
	for(auto edge:path){
		if(edgeCount == n-1) break;
		if(cycleToAdd(parent, edge.second.first, edge.second.second)){
			edgeCount++;
			sum += edge.first;
		}
	}
	cout << sum;
}
