#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	int min=10010,max=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]>max)max=arr[i];
		if(arr[i]<min)min=arr[i];
	}
	int area=min*n;
	int temp;
	for(int i=min;i<=max;i++){
		int left=-1;
		int right=0;
		int count=0;
		for(int j=0;j<n;j++){
			if(arr[j]>=i){
				count+=1;
			}
			else{
				temp=count*i;
				count=0;
			}
			if(area<temp){
				area=temp;
			}			
		}
		temp=count*i;
		if(area<temp){
			area=temp;
		}		
	}
	cout<<area<<endl;
	return 0;
}
