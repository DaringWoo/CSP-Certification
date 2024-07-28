#include <iostream>
using namespace std;
int main(){
	int n,m,L;
	cin>>n>>m>>L;
	int H[L]={0};
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>temp;
			H[temp]+=1;
		}
	}
	for(int i=0;i<L;i++)cout<<H[i]<<" ";
	return 0;
}
