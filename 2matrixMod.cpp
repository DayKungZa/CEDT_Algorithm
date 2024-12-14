#include <iostream>
#include <vector>
using namespace std;
int k;

vector<int> multiply(const vector<int> &M,const vector<int> &N){
	vector<int> mat;
	mat.push_back((((M[0]%k)*(N[0]%k))%k+((M[1]%k)*(N[2]%k))%k)%k);
	mat.push_back((((M[0]%k)*(N[1]%k))%k+((M[1]%k)*(N[3]%k))%k)%k);
	mat.push_back((((M[2]%k)*(N[0]%k))%k+((M[3]%k)*(N[2]%k))%k)%k);
	mat.push_back((((M[2]%k)*(N[1]%k))%k+((M[3]%k)*(N[3]%k))%k)%k);
	return mat;
}

int main(){
	int n;
	vector<int> m(4);
	cin >> n >> k;
	cin >> m[0] >> m[1] >> m[2] >> m[3];
	
	vector<vector<int>> mat;
	mat.push_back(m);
	
    int i = 1;
    while ((1 << i) <= n) {
        mat.push_back(multiply(mat[i - 1], mat[i - 1]));
        i++;
    }
    
    vector<int> result = {1, 0, 0, 1};
    int p = 0;
    while (n > 0) {
        if (n & 1) 
            result = multiply(result, mat[p]);
        n >>= 1;
        p++;
    }
    
    cout << result[0] << ' ' << result[1] << ' ' << result[2] << ' ' << result[3];
}
