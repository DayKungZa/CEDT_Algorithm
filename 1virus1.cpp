#include <bits/stdc++.h>
using namespace std;

int main(){
	int m,k;
	cin >> m >> k;
	int n = (2<<(k-1));
	while(m--){
		vector<int> q;
		int check = true;
		for(int i=0;i<n/2;i++){
			int x,y;
			cin >> x >> y;
			q.push_back(x*2+y); 
			if(x==y||(i==(n-1)/2 &&(x||!y))) check = false;
		}
		if(check) cout << "yes\n";
		else cout << "no\n";
	}
}
