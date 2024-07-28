# include <iostream>
# include <unordered_map>
# include <vector>
# include <cmath>
# include <queue>
# include <numeric>
# include <algorithm>

using namespace std;

int  n,m,k;
long long r;
vector<vector<long long>> coords;
unordered_map<int,vector<int>> adj_map;
vector<vector<int>> combs;

void myInput(){
	cin >> n >> m >> k >> r;
	long long  num;
	vector<long long > tmp;
	for(auto i=0;i<n+m;++i){
		tmp.clear();
		for(auto j=0;j<2;++j){
			cin >> num;
			tmp.push_back(num);
		}
		if(i<n){
			tmp.push_back(0);
		}
		else{
			tmp.push_back(1);
		}
		coords.push_back(tmp);
	}
}	
void makeAdj(){
	for(size_t u=0;u<coords.size();++u){
		for(size_t v=0;v<coords.size();++v){
			if(u==v){
				continue;
			}
			long long  dis=(pow(coords[u][0]-coords[v][0],2)+pow(coords[u][1]-coords[v][1],2));
			if(dis<=r*r){
				adj_map[u].push_back(v);
			}
		}
	}
}	
int BFS(){
	queue<int> q;
	unordered_map<int,int> p;
	q.push(0);								
	vector<int> path;
	p[0]=-1;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		if(node==1){
			break;
		}			
		path.clear();
		int  current=node;
		while(current!=-1){
			path.push_back(current);
			current=p[current];
		} 
		int cnt=0;
		cout << "************"<<endl;
		cout <<"node£º" <<node << endl;
		cout << "path£º";
		for(auto it:path){
			cnt+=coords[it][2];
			cout << it << " ";
		}
		cout << endl;
		cout << "cnt:"<<cnt << endl;
		if(cnt>k){
			continue;
		}
		cout << "push:" ; 
		for(auto it: adj_map[node]){
			
			if(!binary_search(path.begin(),path.end(),it)){
				q.push(it);
				cout << it <<" ";
				p[it]=node;
				
			}				
		}
		cout << endl;	
	}
	
	return path.size() - 1;				
}						
			
int main(){
	myInput();
	makeAdj();
	
	for(auto ii:adj_map){
		cout << ii.first << ":";
		for(auto jj:ii.second){
			cout << jj <<" "; 
		}
		cout << endl;
	}
	
	int count=BFS();
	
	cout << count <<endl;
	return 0;
}	
