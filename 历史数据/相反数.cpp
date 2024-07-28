#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[1000]={0};
	int count=0;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(temp<0){
			temp=-temp;
		}
		if(arr[temp]!=0){
			count++;
		}
		else{
			arr[temp]=1;
		} 
	}
	cout<<count<<endl;
	return 0;
} 
