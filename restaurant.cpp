#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
int n;

//func to check if time is right
int check(vector<ll> &smell, ll t, ll q){
	ll croissant = 0;
	ll minmod = INT_MAX;
	for(auto s:smell){
		croissant += t/s; //count croissant that can be smell in time t
		minmod = (minmod>t%s)? t%s : minmod; //remember wasted time
	}
	cout << t << ' ' << croissant << '\n';
	if(croissant==q){
		cout << t - minmod << '\n';
		return 0; //print, done
	}
	if(croissant>q)
		return 1; //search lower
	else return -1; //search higher
}

int main(){
	int m;
	cin >> n >> m;
	vector<ll> T(n);
	for(int i=0;i<n;i++)
		cin >> T[i];
	for(int i=0;i<m;i++){
		ll q;
		cin >> q;
		//binary search
		ll lo = 0, hi = ULLONG_MAX;
		while(true){
			ll med = lo+(hi-lo)/2;
			int c = check(T, med, q);
			//cout << hi << ' ' << lo << ' ' << med << ' ' << c << '\n';
			if(c==0) break; //done
			//if(hi-lo==1) lo++;
			else if(c==1) hi = med; //search lower
			else lo = med;
		}
	}
}
