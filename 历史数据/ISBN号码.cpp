#include <iostream>
using namespace std;
int main(){
	char str[14];
	int num[9];
	cin.get(str,14);
	int count=0;
	for(int i=0;i<12;i++){
		if(str[i]!='-'){
			num[count]=str[i]-'0';
			count+=1;
		}
	}
	
	int sum=0;
	for(int i=1;i<=9;i++){
		sum+=i*num[i-1]; 
	}
	int nn=sum%11;
	if(nn==10){
		if(str[12]=='X'){
			cout<<"Right"<<endl;
		}
		else{
			str[12]='X';
			cout<<str<<endl;
		}
	}
	else{
		if(nn==(str[12]-'0')){
			cout<<"Right"<<endl;
		}
		else{
			str[12]=nn+'0';
			cout<<str<<endl;
		}
	}
	return 0;
} 
