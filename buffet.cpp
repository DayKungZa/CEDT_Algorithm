#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

vector<int> arrive, depart, total;
priority_queue<pii, vector<pii>, greater<pii>> fq;

void fly(vector<vector<int>> &lines, int start){
	total[start] = 0;
	for(auto to : lines[start]){
		fq.push({depart[start]+arrive[to], to});
	}
	while(!fq.empty()){
		auto [cost, pos] = fq.top();
		fq.pop();
		if(pos==0) continue;
		if(total[pos] != -1) continue;
		total[pos] = cost;
		for(auto to : lines[pos]){
			fq.push({total[pos]+depart[pos]+arrive[to], to});
		}
	}
	
}

int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++){int a;cin>>a;arrive.push_back(a);total.push_back(-1);}
	for(int i=0;i<n;i++){int a;cin>>a;depart.push_back(a);}
	vector<vector<int>> lines(n);
	while(m--){
		int a, b;
		cin >> a >> b;
		lines[a].push_back(b);
	}
	fly(lines, 0);
	for(int i=0;i<n;i++) cout << total[i] << ' ';
}
