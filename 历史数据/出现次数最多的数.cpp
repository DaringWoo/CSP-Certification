#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int count[10001]={0};
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		count[temp]+=1;
	}
	int max=0;
	for(int i=0;i<10001;i++){
		if(count[i]>max) max=count[i];
	}
	int min=10001;
	for(int i=0;i<10001;i++){
		if(count[i]==max){
			cout<<i;
			break;
		}
	}
	return 0;
}
