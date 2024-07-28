#include <iostream>
#include <cstring>

using namespace std;

int main(){
	int num;
	cin >> num;
	char str[num][100];
	memset(str, '0', sizeof(str));
	for(int i=0;i<num;i++){
		for(int j=0;j<8;j++){
			char s1[10];
			cin >> s1;
			strcat(str[i], s1);
		}
	}
	
	cout << num << endl;
	cout << str[3] << endl; 
	return 0;
} 
