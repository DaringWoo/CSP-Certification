#include <stdio.h>

int main(){
	long i,n,k,need,min,max;
	long long m,sum;
	scanf("%ld %lld %ld",&n,&m,&k);
	long data[n][2];
	max=0;
	min=k;
	for(i=0;i<n;i++){
		scanf("%ld %ld",&data[i][0],&data[i][1]);
		if(data[i][0]>max){
			max=data[i][0];
		}
	}
	while(min+1<max){
		need=(max+min)/2;
		sum=0;
		for(i=0;i<n;i++){
			if(data[i][0]>need){
				sum+=(data[i][0]-need)*data[i][1];
			}
		}
		if(sum>m){
			min=need;
		}
		else{
			max=need;
		}
	}
	printf("%ld",need);
	return 0;
}

