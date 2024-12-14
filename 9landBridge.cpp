#include <iostream>
int map[5000][5000] = {};
int walk[5000][5000] = {};
int r, c;

void ff(int y, int x, int pos, int &path){
	
}


int main(){
	cin >> r >> c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> map[i][j];
			if(map[i][j]==3) walk[i][j] = -1;
			else if(!map[i][j]==1){
				walk[i][j] = 1;
				
			}
		}
	}
}
