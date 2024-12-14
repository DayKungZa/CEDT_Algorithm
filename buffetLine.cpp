#include <bits/stdc++.h>
using namespace std;

int main(){
	int f, w, n;
	cin >> f >> w >> n;
	vector<int> a(f);
	for(int i=0;i<f;i++) cin >> a[i];
	sort(a.begin(),a.end());
	int x = a[0]+w;
	int cnt = 1;
	for(auto pos:a){
		if(pos<x-w||pos>x+w){
			cnt++;
			x = pos+w;
		}
	}
	cout << cnt;
}
