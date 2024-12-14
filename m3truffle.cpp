#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int n, m;

//func to check if time is right
int check(vector<int> &smell, int t){
	int croissant = 0;
	int minmod = INT_MAX;
	for(auto s:smell){
		croissant += t/s; //count croissant that can be smell in time t
		minmod = min(minmod,t%s); //remember wasted time
	}
	//cout << t << ' ' << croissant << '\n';
	if(croissant==n){
		cout << t - minmod;
		return 0; //print, done
	}
	if(croissant>n)
		return 1; //search lower
	else return -1; //search higher
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	vector<int> smell(m);
	for(int i=0;i<m;i++) cin >> smell[i];
	
	//binary search
	int lo = 0, hi = INT_MAX;
	while(true){
		int med = (hi-lo)/2+lo; //beware of INT_MAX overflow
		int c = check(smell, med);
		if(c==0) return 0; //done
		if(c==1) hi = med; //search lower
		else lo = med;
	}
}
