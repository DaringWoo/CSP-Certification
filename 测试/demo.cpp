# include <iostream>
# include <unordered_map>
# include <vector>
# include <cmath>
# include <queue>
# include <numeric>

using namespace std;

int n,m,k,r;
int count;
vector<vector<int>> coords;
vector<vector<int>> coords_cp;
unordered_map<int,vector<int>> adj_map;
vector<vector<int>> combs;

void myInput(){
	cin >> n >> m >> k >> r;
	int num;
	vector<int> tmp;
	for(auto i=0;i<n+m;++i){
		tmp.clear();
		for(auto j=0;j<2;++j){
			cin >> num;
			tmp.push_back(num);
		}
		coords.push_back(tmp);
	}
}
void makeAdj(){
	for(auto u=0;u<coords.size();++u){
		for(auto v=0;v<coords.size();++v){
			if(u==v){
				continue;
			}
			int dis=sqrt(pow(coords[u][0]-coords[v][0],2)+pow(coords[u][1]-coords[v][1],2));
			if(dis<=r){
				adj_map[u].push_back(v);
			}
		}
	}
}
int BFS(){
	queue<int> q;
	unordered_map<int,int> p;
	unordered_map<int,bool> visited;
	q.push(0);
	visited[0]=true;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		if(node==1){
			break;
		}
		for(auto it: adj_map[node]){
			if(!visited[it]){
				q.push(it);
				visited[it]=true;
				p[it]=node;
			}
		}
	}
	vector<int> path;
	int current=1;
	while(current!=0){
		path.push_back(current);
		current=p[current];
	}
	return path.size()-1;
}

void myComb(vector<int>& nums, vector<int>& comb, int start, int m) {
    if(m == 0) {
    	combs.push_back(comb);
        return;
    }

    for(int i=start; i<nums.size(); ++i) {
        comb.push_back(nums[i]);
        myComb(nums, comb, i + 1, m - 1);
        comb.pop_back();
    }
}

int main(){
	myInput();
	vector<int> seq(m);
	iota(seq.begin(),seq.end(),n);
	vector<int> comb;
	myComb(seq,comb,0,m-k);
	coords_cp=coords;
	count=m+n;
	for(auto cb:combs){
		coords=coords_cp;
		for(auto it:cb){
			for(auto ic=coords.begin();ic!=coords.end();++ic){
				if(coords_cp[it]==*ic){
					coords.erase(ic);
					break;
				}
			}
		}
		adj_map.clear();
		makeAdj();
		int count_new=BFS();
		if(count_new<count){
			count=count_new;
		}
	}
	cout << count <<endl;
	
	return 0;
}

