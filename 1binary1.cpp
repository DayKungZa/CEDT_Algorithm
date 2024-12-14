#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

int binary(const int &val, int hi, int low){
    int mid = (hi+low)/2;
    if(val < v[0]) return -1;
    if(val >= v[hi]) return hi;
    
	if(val == v[mid]){
		while(v[mid+1]==val) mid++;
		return mid;
	}
    if(mid == hi || mid == low)
		if(v[mid]>val) return mid-1;
		else return mid;
    if(val > v[mid]) return binary(val,hi,mid);
    else return binary(val,mid,low);
}

int main(){
    int n, q;
    cin >> n >> q;
    int a;
    while(n--) {cin >> a; v.push_back(a);}
    while(q--){
      cin >> a;
      int b = binary(a, v.size()-1, 0);
      if(b!=-1) cout << b << '\n';
      else cout << -1 << '\n';
    }
}
