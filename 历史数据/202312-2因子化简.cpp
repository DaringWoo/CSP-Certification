#include <iostream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

vector<long long> primeFactors(long long n){
	vector<long long> factors;
	while(n % 2 == 0){
		factors.push_back(2);
		n /=2;
	} 
	for(int i=3;i*i<=n;i+=2){
		while(n % i == 0){
			factors.push_back(i);
			n /=i;
			
		}
	}
	if(n > 2){
		factors.push_back(n);
	}
	return factors;
}


int main(){
	long long n ;
	int q,k,i;
	cin >> q;
	for(i=0;i<q;i++){
		cin>>n>>k;
		vector<long long> factors=primeFactors(n);
		map<long long,int> countMap;
		for(auto factor:factors) {
        	countMap[factor]++;
    	}
    	long long total=1;
    	for(auto& pair:countMap){
    		if(pair.second >= k){
    			total*=pow(pair.first,pair.second);
			}
		}
    	cout << total << endl;
	}
	return 0;
}
