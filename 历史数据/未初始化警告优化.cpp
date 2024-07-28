#include <iostream> 
using namespace std;
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	int dt[1000000]={0};
	dt[0]=1; //³£Á¿ 
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		if(!dt[b]) ans++;
		dt[a]=true;
	}
	cout<<ans<<endl;
	return 0;
}
