# include <iostream>
# include <string>
# include <algorithm>

using namespace std; 

int main(){
	string str,str_cp;
	int i,sum=0,j=1;
	char code;
	cin >> str;
	str_cp=str;
	str_cp.erase(remove(str_cp.begin(),str_cp.end(),'-'),str_cp.end());
	str_cp.pop_back();
	for(auto& it:str_cp){
		sum+=(it-'0')*j;
		++j;
	}
	sum%=11;
	if(sum==10){
		code='X';
	}
	else{
		code='0'+sum;
	}
	if(str.back()==code){
		cout << "Right" <<endl;
	}
	else{
		str.back()=code;
		cout << str << endl;
	}
	return 0;
}
