#include <stdio.h>

int main(){
	int n,i;
	int a,b;
	int x1,y1,x2,y2;
	int area,sum=0;
	scanf("%d %d %d",&n,&a,&b);
	int data[n][4];
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&data[i][0],&data[i][1],
		&data[i][2],&data[i][3]);
	} 
	for(i=0;i<n;i++){
		x1=data[i][0];
		y1=data[i][1];
		x2=data[i][2];
		y2=data[i][3];
		int flag[4]={0,0,0,0};
		if((x1>0&&x1<a)&&(y1>0&&y1<b)){flag[0]=1;}
		if((x2>0&&x2<a)&&(y1>0&&y1<b)){flag[1]=1;}
		if((x2>0&&x2<a)&&(y2>0&&y2<b)){flag[2]=1;}
		if((x1>0&&x1<a)&&(y2>0&&y2<b)){flag[3]=1;}
		if(flag[0]==1&&flag[1]==0&&flag[2]==0&&flag[3]==0){area=(a-x1)*(b-y1);}//左下 
		if(flag[0]==0&&flag[1]==1&&flag[2]==0&&flag[3]==0){area=(x2-0)*(b-y1);}//右下 
		if(flag[0]==0&&flag[1]==0&&flag[2]==1&&flag[3]==0){area=(x2-0)*(y2-0);}//右上 
		if(flag[0]==0&&flag[1]==0&&flag[2]==0&&flag[3]==1){area=(a-x1)*(y2-0);}//左上 
		if(flag[0]==1&&flag[1]==1&&flag[2]==0&&flag[3]==0){area=(x2-x1)*(b-y1);}//上中 
		if(flag[0]==0&&flag[1]==1&&flag[2]==1&&flag[3]==0){area=(x2-0)*(y2-y1);}//左中 
		if(flag[0]==0&&flag[1]==0&&flag[2]==1&&flag[3]==1){area=(x2-x1)*(y2-0);}//下中
		if(flag[0]==1&&flag[1]==0&&flag[2]==0&&flag[3]==1){area=(a-x1)*(y2-y1);}//右中 
		if(flag[0]==1&&flag[1]==1&&flag[2]==1&&flag[3]==1){area=(x2-x1)*(y2-y1);}//中内含
		if(flag[0]==0&&flag[1]==0&&flag[2]==0&&flag[3]==0){     
		if((x1<=0&&y1<=0)&&(x2>=a&&y2>=b)){area=a*b;}
		else{area=0;}
		}//中内含
		sum +=area;	
	}
	printf("%d",sum);
	return 0;
} 
