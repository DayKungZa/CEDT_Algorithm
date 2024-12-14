#include <bits/stdc++.h>
using namespace std;
#define pipii pair<int,pair<int,int>>

int main(){
	int n;
	cin >> n;
	int town[n];
	for(int i=0;i<n;i++) cin >> town[i];
	vector<pipii> path
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			path.push_back({town[i]^town[j],{i,j}});
		}
	}
	
}
