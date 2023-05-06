#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct{
	int num;   //���
	char time[30]; //ʱ�� 
	char matter[50]; //����
}datatype;

typedef struct node{
	datatype data;
	struct node *next ;
}listnode; 

typedef listnode *linklist;


listnode *listfind(linklist head);  //����
void insertnode(linklist head,listnode *x);  //���������������¼
int  delnode(linklist head,listnode *x); //����
void printlist(linklist head);  //�������δ�����ĺ��ѳ�������Ϣ
void main(){
	listnode *A,*B;//A��δ����ı�����¼������ͷ��㣬B���Ѿ������ļ�¼����
	A=new listnode; 
	B=new listnode;
	A->next =NULL;   
	B->next =NULL;
	while(1){
		cout<<"\t\t\t-----��ӭʹ��ʵʱ��ر���ϵͳ------"<<endl;
		cout<<"\t\t\t-----------�����밴1---------------"<<endl;
		cout<<"\t\t\t-----------�����밴2---------------"<<endl;
		cout<<"\t\t\t-----------����밴3---------------"<<endl;
		cout<<"\t\t\t-----------�˳��밴0---------------"<<endl;
		int k;
		cin>>k;
		switch(k){
		case 0:
			cout<<"\t\t��л����ʹ��!"<<endl;
			exit(0);//����
		case 1:{
			int jj=0; //jj��ʾδ����ľ�������
			listnode *h;
			h=A->next ;
			while(h){ 
				jj++;           
				h=h->next ;
			}
			if(jj>9){    //��ʱ����10�ξ���δ����
				cout<<"����̫�ྯ��δ�����´˴α���ʧ�ܣ���������������!"<<endl;
				break;
			}   
			cout<<"������:"<<endl;
			cout<<"���\t\tʱ��\t\t����:"<<endl; 
			listnode *x;
			x=new listnode;
			cin>>x->data .num>>x->data .time >>x->data .matter ;
			insertnode(A,x);
			cout<<"�ѱ���!"<<endl;
			break;
			   }  
		case 2:
			listnode *y;
			y=new listnode;
			if(delnode(A,y)){   //��ɾ���ɹ�ִ��������䣬���ɾ�����ɹ����ں���delnode()������ʾ������ֵ0 ��
				cout<<y->data .num <<"\t"<<y->data .time <<"\t"<<y->data .matter <<endl;
				cout<<"�ѳ���!"<<endl;
				insertnode(B,y);  // ����֮���ڰѽڵ���Ϣ���뵽B�б����¼
			}		
			break;
		case 3:
			cout<<"δ����ľ�����:"<<endl;
			printlist(A);
			cout<<"�Ѵ���ľ�����:"<<endl;
			printlist(B);
			break;
		}
	}
}


/*��������*/
void insertnode(linklist head,listnode *p){
	listnode *p1,*p2;
	p1=head;
	p2=p1->next ;
	while(p2!=NULL&& ( p2->data .num < p->data .num )){   //Ѱ�Ҳ���λ��  
		p1=p2;
		p2=p2->next ;
	}
	p1->next =p;   //����Ŵ�С˳�����
 	p->next =p2;
}

/*���ҹ���*/
listnode *listfind(linklist head){    //����ĳ�ڵ�
	listnode *p;
	int num;
	char time[30];
	int n;
	printf("\t\t1.��ʱ���ѯ\n");
	printf("\t\t��ѡ��:\n");
	p=head->next ;
	cin>>n;
		if(n==1)
		{
			printf("������Ҫ���ҵ�ʱ��:");
			cin>>time;
			while(p&&strcmp(p->data .time  ,time)!=0)  //�ж������ַ����Ƿ����
				p=p->next ;
		}
		return p;
}


/*��������*/

int delnode(linklist head,listnode *g){
	listnode *p,*q;
	p=listfind(head);  //ִ�в��Һ���
	if(p==NULL){
		printf("û�в��ҵ����¼�\n");
		return 0;
	}
		q=head;
		while(q!=NULL&&q->next !=p)
			q=q->next ;
		q->next =p->next ;
		*g=*p;
    	delete p;
		return 1;	
}



/*�������*/
void printlist(linklist head){
	listnode *p;
	p=head->next ; 
	if(p==NULL){
		printf("û����Ϣ!\n\n");
		return;   
	}
	printf("���    ʱ��   ���� \n");
	while(p!=NULL){
		printf("%d\t%s\t%s\n",p->data .num ,p->data .time  ,p->data .matter  );  
		p=p->next ;
	}
}