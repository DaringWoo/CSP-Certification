#include <stdio.h> 
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int data[k][2];
	int i,j,count=0,flag;
	for(i=0;i<k;i++){
		scanf("%d %d",&data[i][0],&data[i][1]);
	}
	if(data[0][1]!=0){
		count+=1;
	}
	for(i=1;i<k;i++){
		flag=0;
		if(data[i][1]!=0){
			for(j=i-1;j>=0;j--){
				if(data[j][0]==data[i][1]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				count+=1;
			}
		}
	}
	printf("%d",count);
	return 0;
}
