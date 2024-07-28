#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int B[n];
	int min,max;
	cin>>B[0];
	max=B[0];
	min=B[0];
	for(int i=1;i<n;i++){
		cin>>B[i];
		max+=B[i];
		if(B[i]==B[i-1]){
			min+=0;
		}
		else{
			min+=B[i];
		}
	}
	cout<<max<<endl;
	cout<<min<<endl;
	return 0;
}
