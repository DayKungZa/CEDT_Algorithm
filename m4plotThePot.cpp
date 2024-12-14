#include <iostream>
using namespace std;
#define MOD 1000000007

int main(){
	int n;
	cin >> n;
	int a[n+1];
	//base cases
	a[0] = 1;
	a[1] = 1;
	a[2] = 3;
	a[3] = 5;
	//a[n] = a[n-1] + 2*a[n-2] recursive
	for(int i=4;i<=n;i++){
		a[i] = (a[i-1]%MOD + (2*a[i-2])%MOD)%MOD;
	}
	cout << a[n];
}
