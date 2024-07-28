#include <iostream>
#include <vector>

using namespace std;

int R,C,cnt;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<bool>> visited_cp;

pair<int,int>findStr(char symbol){
	for(auto i=0;i<R;++i){
		for(auto j=0;j<C;++j){
			if(grid[i][j]==symbol){
				return {i,j};
			}
		}
	}
}

void DFS(int r,int c){
	if(r<0||c<0||r>=R||c>=C||grid[r][c]=='#'||visited[r][c]){
		return;
	}
	visited[r][c]=true;
	if(grid[r][c]=='+'){
		DFS(r-1,c);//上
		DFS(r+1,c);//下
		DFS(r,c-1);//左
		DFS(r,c+1);//右 
	}
	if(grid[r][c]=='-'){
		DFS(r,c-1);//左
		DFS(r,c+1);//右 
	}
	
	if(grid[r][c]=='|'){
		DFS(r-1,c);//上
		DFS(r+1,c);//下
	}
	if(grid[r][c]=='.'){
		DFS(r+1,c);//下
	}
	if(grid[r][c]=='S'){
		DFS(r-1,c);//上
		DFS(r+1,c);//下
		DFS(r,c-1);//左
		DFS(r,c+1);//右 
	}
	if(grid[r][c]=='T'){
		DFS(r-1,c);//上
		DFS(r+1,c);//下
		DFS(r,c-1);//左
		DFS(r,c+1);//右 
	}
}



int main(){
	cin >> R >> C;
	grid.resize(R,vector<char>(C));
	visited.resize(R,vector<bool>(C,false));
	visited_cp.resize(R,vector<bool>(C,false));
	for(auto i=0;i<R;++i){
		for(auto j=0;j<C;++j){
			cin >> grid[i][j];
		}
	}
	pair<int,int> start=findStr('S');
	pair<int,int> target=findStr('T');
	DFS(start.first,start.second);
	
	if(!visited[target.first][target.second]){
		cout << "I'm stuck!" << endl;
		return 0;
	}
	visited_cp=visited;
	cnt=0;
	for(auto i=0;i<R;++i){
		for(auto j=0;j<C;++j){
			if(visited_cp[i][j]){
				visited.assign(R,vector<bool>(C,false));
				DFS(i,j);
				if(!visited[target.first][target.second]){
					cnt++;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}

