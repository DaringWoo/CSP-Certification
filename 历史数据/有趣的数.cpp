#include <iostream>
using namespace std;
int mod=1000000007;
long long dp[10010][6]={0};
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){//6种状态的状态转移方程 
		dp[i][0]=1;
		dp[i][1]=(dp[i-1][0]+(dp[i-1][1]<<1))%mod;
		dp[i][2]=(dp[i-1][0]+(dp[i-1][2]))%mod;
		dp[i][3]=(dp[i-1][1]+(dp[i-1][3]<<1))%mod;
		dp[i][4]=(dp[i-1][1]+dp[i-1][2]+(dp[i-1][4]<<1))%mod;
		dp[i][5]=(dp[i-1][3]+dp[i-1][4]+(dp[i-1][5]<<1))%mod;
	}
	cout<<dp[n][5];
	return 0;
} 
