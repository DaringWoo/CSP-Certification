# include <iostream>
# include <cstring>
using namespace  std;
const int maxn=40;
int dp[maxn+1];

 
//斐波那契数列
int solve1(int n){//递归 O(2^n) 
	if(n<=3)
		return n-1;
	return solve1(n-1)+solve1(n-2);
}

int solve2(int n){//记忆化递归 (备忘录)
	if(dp[n]!=0)
		return dp[n];
	if(n<=3)
		return dp[n]=n-1;
	else dp[n]=solve2(n-1)+solve2(n-2);
	return dp[n];
}
int solve3(int n){//动态规划 
	dp[1]=1;
	dp[2]=1;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	return dp[n];
}

int solve4(int n){//动态规划 (迭代：空间优化)
	int a=1;
	int b=1;
	for(int i=3;i<=n;i++){
		b=a+b;
		a=b-a;
	}
	return b;
}


int main(){
	int m,T;
	cin>>T;
	while(T--){
		scanf("%d",&m);
		cout<<solve1(m)<<endl;//递归 
		memset(dp,0,sizeof(dp));//要加头文件<cstring>
		cout<<solve2(m)<<endl;//记忆化递归 
		memset(dp,0,sizeof(dp));
		cout<<solve3(m)<<endl;//动态规划 
		memset(dp,0,sizeof(dp));
		cout<<solve4(m)<<endl;//动态规划 (空间优化)(时间空间复杂度最低)
	}
	return 0; 
}





