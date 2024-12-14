#include <bits/stdc++.h>
using namespace std;

//test bsearch
int main(){
	int n; cin >> n;
	int hi = INT_MAX;
	int lo = 0;
	while(lo<hi){
		int med = lo+(hi-lo)/2;
		cout << hi << ' ' << med << ' ' << lo << '\n';
		if(n>=med) lo = med+1;
		if(n<med)  hi = med;
	}
	cout << n;
}
