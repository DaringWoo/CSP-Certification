#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};
Node *p,*r,*head;

//������뺯�� 
void insert(Node *head,int i,int x){//�ڵ�i��λ�ò���X �ĺ��� 
	Node *p,*s;
	int j;
	p=head;
	j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j+=1;
	}
	if(p==NULL){
		cout<<"û�����λ��"<<endl; 
	}
	else{
		s=new Node;
		s->data=x;
		s->next=p->next;
		p->next=s;
	}
}

//����ɾ������
void del(Node *head,int i){//ɾ����i��λ�õ����� 
	Node *p,*s;
	int j=0;
	p=head;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j+=1;
	}
	if(p==NULL){
		cout<<"û�����λ��"<<endl; 
	}
	else{
		s=p->next;
		p->next=p->next->next;
		free(s);
	}
}

int main(){
	//�������� 
	int x;
	cin>>x;
	head=new Node;
	r=head;
	while(x!=-1){
		p=new Node;//�����µĽڵ� 
		p->data=x;
		p->next=NULL;
		r->next=p;//���½ڵ����ӵ�ǰһ���ڵ� 
		r=p;
		cin>>x;
	}
	//������� 
	p=head->next; //ָ��ָ��ͷ 
	while(p->next!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
	//��ѯ
	p=head->next;
	int i=0;
	while(p->next!=NULL){
		if(p->data==3){
			i++;
		}
		p=p->next;
	}
	if(p->data==3){//�жϿ�ָ��λ�õ����� 
		i++;
	}
	cout<<"������"<<i<<"��3��"<<endl; 
	
	//����һ���ڵ�
	insert(head,2,99);
	p=head->next; //ָ��ָ��ͷ 
	while(p->next!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
	
	//ɾ��һ���ڵ�
	del(head,3);//ɾ������������ 
	p=head->next; //ָ��ָ��ͷ 
	while(p->next!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;	 
	
	cout<<"over"<<endl; 
	return 0;
}
