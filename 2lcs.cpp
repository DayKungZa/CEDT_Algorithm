#include <iostream>
#include <string>
using namespace std;

int main(){
  string a, b;
  cin >> a >> b;
  int as = a.size(), bs = b.size();
  int c[as+1][bs+1];
  for(int i=0;i<=as;i++) c[i][0] = 0;
  for(int i=0;i<=bs;i++) c[0][i] = 0;
  
  for(int i=1;i<=as;i++){
    for(int j=1;j<=bs;j++){
      c[i][j] = (a[i-1]==b[j-1])? c[i-1][j-1] + 1 : max(c[i-1][j],c[i][j-1]);
    //  cout << c[i][j] << ' '; 
    }
    //cout << '\n';
  }
  cout << c[as][bs];
}
