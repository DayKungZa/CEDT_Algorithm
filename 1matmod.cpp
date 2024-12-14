#include <iostream>
using namespace std;
int k;

//    a b
//    c d
//a b a*a+b*c, b*a+d*b
//c d 

int main(){
	int n;
	cin >> n >> k;
	long long a,b,c,d;
	long long A,B,C,D;
	cin >> a >> b >> c >> d;
	for(int i=1;i<n;i++){
		A = ((a%k)*(a%k)+(b%k)*(c%k))%k;
		B = ((a%k)*(b%k)+(b%k)*(d%k))%k;
		C = ((c%k)*(a%k)+(d%k)*(c%k))%k;
		D = ((c%k)*(b%k)+(d%k)*(d%k))%k;
		a = A; b = B; c = C; d = D;
	}
	cout << A << ' ' << B << ' ' << C << ' ' << D;
}
