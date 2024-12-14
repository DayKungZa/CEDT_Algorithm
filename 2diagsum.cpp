#include <iostream>
using namespace std;

int main(){
	int n;
	int maxx = INT_MIN;
	cin >> n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> a[i][j];
			if(i>0&&j>0)
				a[i][j] = max(a[i][j], a[i][j]+a[i-1][j-1]);
			maxx = max(maxx, a[i][j]);
		}
	}
	cout << maxx;
}
