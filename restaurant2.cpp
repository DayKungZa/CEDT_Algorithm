#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
	int n, q;
	cin >> n >> q;
	vector<ll> chefs(n);
	ll minn = INT_MAX;
	for(int i=0;i<n;i++){
		cin >> chefs[i];
		minn = (minn<chefs[i])? minn:chefs[i];
	}
	
	//binary
	while(q--){
		ll c;
		cin >> c;
		ll lo = 0, hi = minn*c;
		if(c<=n){ //in case of instant food
			cout << "0\n";
			continue;
		}
		c -= n; //minus instant
		
		while(lo<hi){
			
			ll t = (hi+lo)/2; //binary search time and count customers served
			
			//find amout of customer served with time t
			for(auto chef:chefs){
				customer += t/chef;
				if(customer > c) break;
			}
			
			if(customer >= c) hi = t;
			if(customer < c) lo = t+1;
		}
		
		cout << lo << '\n'; //answer
		lo = hi;
	}
}
