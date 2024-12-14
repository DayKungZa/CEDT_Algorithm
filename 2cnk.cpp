#include <iostream>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  long long C[n+1][n+1] = {0};
  
  for(int i=1;i<=n;i++) {C[i][0] = 1;}
  for(int j=1;j<=n;j++) {C[j][j] = 1;}
  for(int i=2;i<=n;i++)
    for(int j=1;j<=i;j++)
      C[i][j] = C[i-1][j] + C[i-1][j-1];
  /*
  for(int i=1;i<=n;i++){
  	for(int j=0;j<=k;j++)
  		cout << C[i][j] << ' ';
  	cout << endl;
  }
  
  //*/
  cout << C[n][k];

}

//C(n,0) = 1
//C(n,k) = C(n-1,k) C(n-1,k-1)

