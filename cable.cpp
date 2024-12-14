#include <bits/stdc++.h>
using namespace std;
#define pipii pair<int, pair<int,int>>

int find(vector<int> &parent, int x) {
    while (parent[x]!=-1)
        x = parent[x];
    return x;
}

bool checkToAdd(vector<int> &parent, int a, int b) {
	//find parent if a and b has the same root, then it will make a cycle
    int rootA = find(parent, a);
    int rootB = find(parent, b);
    if (rootA == rootB)
        return false;
    //connect to the root
    parent[rootA] = rootB;
    return true;
}

int main(){
	int n;
	cin >> n;
	vector<pipii> v;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int a;
			cin >> a;
			v.push_back({a,{i,j}});
		}
	}
	sort(v.begin(),v.end());
	//kruskal
	vector<int> parent(n, -1);
	int ans = 0, edgesUsed = 0;
	//iterate from shortest to longest edge
	for(auto edge : v){
		//if used all edge to make spanning tree then break
		if(edgesUsed==n-1) break;
		//if is not a cycle, connect, and update ans
		if(checkToAdd(parent, edge.second.first, edge.second.second)){
			ans += edge.first;
			edgesUsed++;
		}
	}
	cout << ans;
}
