# include <iostream>
# include <list>
# include <vector>

using namespace std;

int N,M,num;
list<vector<int>> mylist;
vector<vector<int>> coords;
vector<int> tmp;

void myInput(){
	cin >> N >> M;
	for(auto i=0;i<N+M;++i){
		tmp.clear();
		if(i<N){
			for(auto j=0;j<4;++j){
				cin >> num;
				tmp.push_back(num);
			}
			tmp.push_back(i+1);
			mylist.push_front(tmp);
		}
		else{
			for(auto j=0;j<2;++j){
				cin >> num;
				tmp.push_back(num);
			}
			coords.push_back(tmp);
		}
	}
	return;
} 

bool isInner(vector<int> crd,vector<int> window){
	if(crd[0]>=window[0] && crd[0]<=window[2] &&\
	   crd[1]>=window[1] && crd[1]<=window[3]){
		return true;
	}
	else{
		return false;
	}
}


int main(){
	myInput();
	for(auto crd:coords){
		bool flag=false;
		for(auto it=mylist.begin();it!=mylist.end();++it){
			vector<int> window=*it;
			if(isInner(crd,window)){
				flag=true;
				cout << window[4] << endl;
				mylist.push_front(window);
				mylist.erase(it);
				break;
			}
		}
		if(!flag){
			cout << "IGNORED" << endl;
		}
	}
	return 0;
} 
