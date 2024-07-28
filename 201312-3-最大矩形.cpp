# include <iostream>
# include <vector>
# include <set>

using namespace std; 

int main(){
	int n,i,tmp,count,area,area_new;
	vector<int> my_vector;
	set<int> my_set;
	cin >> n;
	for(i=0;i<n;++i){
		cin >> tmp;
		my_vector.push_back(tmp);
		my_set.insert(tmp);
	}
	area = n * *my_set.begin();
	for(auto it:my_set){
		count=0;
		for(auto iv:my_vector){
			if(iv>=it){
				count++;
			}
			else{
				area_new=it*count;
				count=0;
				if(area<area_new){
					area=area_new;
				}
			}
		}
		
	}
	cout << area << endl;
	return 0;
}
