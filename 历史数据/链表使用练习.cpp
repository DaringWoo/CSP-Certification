#include<bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next;
};
Node *p,*r,*head;

//定义插入函数 
void insert(Node *head,int i,int x){//在第i个位置插入X 的函数 
	Node *p,*s;
	int j;
	p=head;
	j=0;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j+=1;
	}
	if(p==NULL){
		cout<<"没有这个位置"<<endl; 
	}
	else{
		s=new Node;
		s->data=x;
		s->next=p->next;
		p->next=s;
	}
}

//定义删除函数
void del(Node *head,int i){//删除第i个位置的数据 
	Node *p,*s;
	int j=0;
	p=head;
	while(p!=NULL&&j<i-1){
		p=p->next;
		j+=1;
	}
	if(p==NULL){
		cout<<"没有这个位置"<<endl; 
	}
	else{
		s=p->next;
		p->next=p->next->next;
		free(s);
	}
}

int main(){
	//构造链表 
	int x;
	cin>>x;
	head=new Node;
	r=head;
	while(x!=-1){
		p=new Node;//申请新的节点 
		p->data=x;
		p->next=NULL;
		r->next=p;//把新节点链接到前一个节点 
		r=p;
		cin>>x;
	}
	//输出链表 
	p=head->next; //指针指向开头 
	while(p->next!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
	//查询
	p=head->next;
	int i=0;
	while(p->next!=NULL){
		if(p->data==3){
			i++;
		}
		p=p->next;
	}
	if(p->data==3){//判断空指针位置的数据 
		i++;
	}
	cout<<"其中有"<<i<<"个3！"<<endl; 
	
	//插入一个节点
	insert(head,2,99);
	p=head->next; //指针指向开头 
	while(p->next!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;
	
	//删除一个节点
	del(head,3);//删除第三个数据 
	p=head->next; //指针指向开头 
	while(p->next!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<p->data<<endl;	 
	
	cout<<"over"<<endl; 
	return 0;
}
