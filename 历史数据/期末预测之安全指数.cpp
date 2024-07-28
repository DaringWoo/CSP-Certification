#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int w,score,sum=0;
	for(int i=0;i<n;i++){
		cin>>w>>score;
		sum+=w*score;
	}
	if(sum<0)sum=0; 
	cout<<sum<<endl;
	return 0;
}
