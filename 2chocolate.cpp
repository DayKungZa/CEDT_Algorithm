#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000003

int main(){
	int n,k;
	cin >> n >> k;
	int s[k+1];
	int dp[n+1] = {};
	int a;
	for(int i=1;i<=k;i++)
		cin >> s[i];
	dp[0] = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(i>=s[j]) dp[i] = (dp[i] + dp[i-s[j]]%MOD)%MOD;
		}
	}
	cout << dp[n];
}
