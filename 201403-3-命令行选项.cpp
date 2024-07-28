# include <iostream> 
# include <string>
# include <map>
# include <sstream>
# include <vector>

using namespace std;
int N;
map<string,bool> input_opt;
vector<vector<string>> input_CMD;
vector<map<string,string>> checked_CMD;

void inputOpt(){
	string str;
	getline(cin,str);
	string str_tmp;
	string pre_str_tmp;
	for(auto c=str.begin();c!=str.end();++c){
		string const_str = "-";
		str_tmp=const_str+*c;
		if(str_tmp=="-:"){
			input_opt[pre_str_tmp] = true;
		}
		else{
			input_opt[str_tmp] = false;
		}
		pre_str_tmp=str_tmp;
	}
}

void inputCMD(){
	string str;
	for(auto i=0;i<N;i++){
		getline(cin,str);
		stringstream ss(str);
		string word;
		vector<string> line;
		while(ss >> word){
			line.push_back(word);
		}
		input_CMD.push_back(line);
	}
}

int main(){
	inputOpt();
	cin >> N;
	cin.ignore();
	inputCMD();
	map<string,string> tmp_map;
	for(auto line:input_CMD){
		tmp_map.clear();
		for(auto it=line.begin()+1;it!=line.end();++it){
			string str=*it;
			if(input_opt.count(str)){ //合法选项 
				if(input_opt[str]){ //有参数选项 
					if((it+1)==line.end()){
						break;
					}
					else{
						tmp_map[str]=*(it+1);
						++it;
					} 
				}
				else{//无参数选项 
					tmp_map[str]="$$";
				}
			}
			else{ //参数 
				break;
			}
		}
		checked_CMD.push_back(tmp_map);
	}
	int k=1;
	for(auto ii:checked_CMD){
		printf("Case %d:",k);
		for(auto jj:ii){
			if(jj.second=="$$"){
				cout << " " << jj.first;
			}
			else{
				cout << " " << jj.first << " " << jj.second;
			}
		}
		cout << endl;
		++k;
	}
	return 0;
}
