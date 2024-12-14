#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int deg[n] = {};
	int maxdeg = -1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int a;
			cin >> a;
			deg[i] += a;
		}
		maxdeg = (maxdeg>deg[i])? maxdeg : deg[i];
	}
	int out[maxdeg+1] = {};
	for(int i=0;i<n;i++){
		out[deg[i]]++;
	}
	
	for(int i=0;i<=maxdeg;i++){
		cout << out[i] << ' ';
	}
}
