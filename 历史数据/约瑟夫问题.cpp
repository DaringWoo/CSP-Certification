#include <bits/stdc++.h>
using namespace std;
/*n����վһȦ����1��ʼ����������m���˳����ٴ�1��ʼ������������˵ı�����С�*/

struct Node{
	int d;
	Node *next;
}; 
Node *head,*p,*r,*s;
int m,n;
int main(){
	cin>>m>>n;
	head=new Node;
	r=head;
	head->d=1;
	// ����ѭ������ 
	for(int i=2;i<=n;i++){
		p=new Node;
		p->d=i;
		p->next=NULL;
		r->next=p;
		r=p;
	}
	r->next=head;
	r=head;
	//�������� 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-2;j++)r=r->next;
		s=r->next;
		r->next=r->next->next;
		r=r->next;
		cout<<s->d<<" "; 
		free(s);
	} 
	return 0;
}
 
