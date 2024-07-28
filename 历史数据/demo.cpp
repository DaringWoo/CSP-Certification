#include <bits/stdc++.h>
using namespace std;

struct student{
	string name;
	int chinese,math;
	int total;
};

int n;

int main(){
	student stu[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>stu[i].name>>stu[i].chinese>>stu[i].math;
		stu[i].total=stu[i].chinese+stu[i].math;
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(stu[j].total>stu[j+1].total){
				swap(stu[j].total,stu[j+1].total);
			}
		}
	}
	
	for(int i=0;i<n;i++){
		cout<<stu[i].name<<stu[i].chinese<<stu[i].math<<endl;
	}
	
	
	
	
	return 0;
}
