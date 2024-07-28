#include <iostream>
using namespace std;
int main(){
	int n,N;
	cin>>n>>N;
	int data[n+1];
	data[0]=0;
	int temp=0;
	for(int i=1;i<=n;i++){
		cin>>data[i];
		temp+=(data[i]-data[i-1])*(i-1);
	}
	temp+=(N-data[n])*n;
	cout<<temp<<endl;
	return 0;
}
