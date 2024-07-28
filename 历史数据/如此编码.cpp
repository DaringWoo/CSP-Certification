#include <stdio.h>
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],b[n+1],c[n+1];
	int i,sum;
	int mc,temp;
	sum=1;
	c[0]=1;
	b[0]=1e05;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		sum*=a[i];
		c[i+1]=sum;
	}
	i=1;
	mc=m%c[1];
	temp=0;
	b[1]=mc/c[0];  //b1
	while(i<=n){
		mc=m%c[i]-temp;
		b[i]=mc/c[i-1];
		temp+=c[i-1]*b[i];
		i+=1;
	}
	for(i=1;i<=n;i++){
		printf("%d ",b[i]);
	}

	return 0;
} 
