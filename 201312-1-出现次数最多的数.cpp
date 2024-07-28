# include <iostream>
# include <map>

using namespace std;

int main(){
	int n,i,tmp,max=0,num;
	cin >> n;
	map<int,int> mymap;
	for(i=0;i<n;++i){
		cin >>tmp;
		mymap[tmp]++;
	}
	
	for(auto& pair:mymap){
		if(pair.second>max){
			max=pair.second;
			num=pair.first;
		}
	}
	cout << num << endl;
	return 0;
} 
