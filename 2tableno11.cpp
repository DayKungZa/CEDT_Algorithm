#include <iostream>
#include <string>
using namespace std;
#define MOD 100000007

int main(){
	int n;
	cin >> n;
	if(n==0) {cout << 1; return 0;}
	if(n==1) {cout << 3; return 0;}
	unsigned long long a[n+1], b[n+1];
	a[0] = 1; b[0] = 1;
	a[1] = 3; b[1] = 2;
	a[2] = 7; b[2] = 5;
	for(int i=2;i<=n;i++){
		a[i] = (a[i-1] + (2 % MOD) * (b[i-1] % MOD)) % MOD;
		b[i] = (a[i] - b[i-1] + MOD) % MOD;
	}
	cout << a[n];
}
