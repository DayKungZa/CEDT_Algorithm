#include <bits/stdc++.h>
using namespace std;
#define MOD 32717

int main(){
	int k, n;
	cin >> k >> n;
	int a[k], c[k+1], r[n+1] = {};
	for(int i=1;i<=k;i++) cin >> c[i];
	for(int i=0;i<k;i++) cin >> a[i];
	for(int i=0;i<k;i++) r[i] = a[i];
	for(int i=k;i<=n;i++){
		for(int j=1;j<=k;j++){
			r[i] += ((c[j]%MOD)*(r[i-j]%MOD))%MOD;
			r[i] = r[i]%MOD;
		}
	}
	cout << r[n];
}
