# include <iostream>
# include <map>

using namespace std;

int main(){
	int N,i,tmp,cnt=0;
	map<int,int> mymap;
	cin >> N;
	for(;i<N;++i){
		cin >> tmp;
		if(tmp<0){
			tmp= ~tmp +1;
		}
		mymap[tmp]++;
	}
	for(auto pair:mymap){
		if(pair.second==2){
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
