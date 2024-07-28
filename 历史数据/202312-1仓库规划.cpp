#include <iostream>

using namespace std;

int main(){
	int n,m;
	int i,j,k;
	cin >> n >> m;
	int data[n][m];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin >> data[i][j];
		}
	}
	for(i=0;i<n;i++){
		int flag=1;
		for(j=0;j<n;j++){
			if(j==i){
				continue;
			}
			flag=1;
			for(k=0;k<m;k++){
				if(data[j][k]<=data[i][k]){
					flag=0;
					break;
				}
			}
			if(flag){
				int ans=j+1;
				cout << ans <<endl; 
				break;
			}
		}
		if(!flag){
			cout << 0 <<endl;
		}
	}
	return 0;
}
