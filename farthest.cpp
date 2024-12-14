#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
    int n;
    cin >> n;
    int dis[n][n];
    vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dis[i][j];
            if(dis[i][j]>0)
            	graph[i].push_back(j);
        }
    }
    //init ans as -1 each town except town 0
    vector<int> ans(n,-1);
    ans[0] = 0;
    
    //add new edges from town 0
    for(auto to:graph[0])
    	pq.push({dis[0][to], to});
    
    while(!pq.empty()){
    	//check the shortest current path
    	auto top = pq.top();
		int d = top.first;
		int pos = top.second;
    	pq.pop();
    	//if already go there, skip
    	if(ans[pos]!=-1 || pos==0) continue;
    	ans[pos] = d;
    	//add new edge from current path to pq
    	for(auto to:graph[pos])
    		pq.push({d+dis[pos][to], to});
	}
    
    int m = 0;
    for(auto x:ans){
    	//cout << x << ' ';
    	if(x==-1){
    		cout << -1;
    		return 0;
		}
		else m = max(m,x);
	}
    cout << m;
    return 0;
}
