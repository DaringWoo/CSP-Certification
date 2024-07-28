# include <iostream>

using namespace std;

int main(){
	int n,i,mod=1000000007,tmp;
	long long dp[1000][6]={0};
	cin >> n;
	for(i=1;i<=n;++i){
		dp[i][0] = dp[i-1][0];
		dp[i][1] = (dp[i-1][1]*2 + dp[i-1][0])%mod;
		dp[i][2] = (dp[i-1][2] + dp[i-1][0])%mod;
		dp[i][3] = (dp[i-1][3]*2 + dp[i-1][1])%mod;
		dp[i][4] = (dp[i-1][4]*2 + dp[i-1][1] + dp[i-1][2])%mod;
		dp[i][5] = (dp[i-1][5]*2 + dp[i-1][3] + dp[i-1][4])%mod;
		if(i==1){
			dp[i][0]=1;
		}
	}
	cout << dp[n][5] <<endl;
	return 0;
}
