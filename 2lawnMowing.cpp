#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[n];
	cin >> a[0];
	b[0] = a[0]+k;
	for(int i=1;i<n;i++){
		cin >> a[i];
		b[i] = a[i] + b[i-1] + k;
	}
	for(int i=0;i<m;i++){
		int pos, mon;
		cin >> pos >> mon;
		int before = (pos>0)? b[pos-1] : 0;
		size_t it = upper_bound(b,b+n,mon+before) - b - 1;
		cout << (b[it] - before - (it-pos+1)*k) << '\n';
	}
}
