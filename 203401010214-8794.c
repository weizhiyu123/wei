#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct{
	int num;   //编号
	char time[30]; //时间 
	char matter[50]; //内容
}datatype;

typedef struct node{
	datatype data;
	struct node *next ;
}listnode; 

typedef listnode *linklist;


listnode *listfind(linklist head);  //查找
void insertnode(linklist head,listnode *x);  //报警及出警保存记录
int  delnode(linklist head,listnode *x); //出警
void printlist(linklist head);  //输出所有未出警的和已出警的信息
void main(){
	listnode *A,*B;//A是未处理的报警记录的链表头结点，B是已经出警的记录链表
	A=new listnode; 
	B=new listnode;
	A->next =NULL;   
	B->next =NULL;
	while(1){
		cout<<"\t\t\t-----欢迎使用实时监控报警系统------"<<endl;
		cout<<"\t\t\t-----------报警请按1---------------"<<endl;
		cout<<"\t\t\t-----------出警请按2---------------"<<endl;
		cout<<"\t\t\t-----------输出请按3---------------"<<endl;
		cout<<"\t\t\t-----------退出请按0---------------"<<endl;
		int k;
		cin>>k;
		switch(k){
		case 0:
			cout<<"\t\t感谢您的使用!"<<endl;
			exit(0);//结束
		case 1:{
			int jj=0; //jj表示未处理的警务数量
			listnode *h;
			h=A->next ;
			while(h){ 
				jj++;           
				h=h->next ;
			}
			if(jj>9){    //此时已有10次警务未处理
				cout<<"由于太多警务未处理导致此次报警失败，建议立即处理警务!"<<endl;
				break;
			}   
			cout<<"请输入:"<<endl;
			cout<<"编号\t\t时间\t\t内容:"<<endl; 
			listnode *x;
			x=new listnode;
			cin>>x->data .num>>x->data .time >>x->data .matter ;
			insertnode(A,x);
			cout<<"已报警!"<<endl;
			break;
			   }  
		case 2:
			listnode *y;
			y=new listnode;
			if(delnode(A,y)){   //在删除成功执行下列语句，如果删除不成功，在函数delnode()里有提示并返回值0 。
				cout<<y->data .num <<"\t"<<y->data .time <<"\t"<<y->data .matter <<endl;
				cout<<"已出警!"<<endl;
				insertnode(B,y);  // 出警之后在把节点信息插入到B中保存记录
			}		
			break;
		case 3:
			cout<<"未处理的警务有:"<<endl;
			printlist(A);
			cout<<"已处理的警务有:"<<endl;
			printlist(B);
			break;
		}
	}
}


/*报警功能*/
void insertnode(linklist head,listnode *p){
	listnode *p1,*p2;
	p1=head;
	p2=p1->next ;
	while(p2!=NULL&& ( p2->data .num < p->data .num )){   //寻找插入位置  
		p1=p2;
		p2=p2->next ;
	}
	p1->next =p;   //按编号大小顺序插入
 	p->next =p2;
}

/*查找功能*/
listnode *listfind(linklist head){    //查找某节点
	listnode *p;
	int num;
	char time[30];
	int n;
	printf("\t\t1.按时间查询\n");
	printf("\t\t请选择:\n");
	p=head->next ;
	cin>>n;
		if(n==1)
		{
			printf("请输入要查找的时间:");
			cin>>time;
			while(p&&strcmp(p->data .time  ,time)!=0)  //判断两个字符串是否相等
				p=p->next ;
		}
		return p;
}


/*出警功能*/

int delnode(linklist head,listnode *g){
	listnode *p,*q;
	p=listfind(head);  //执行查找函数
	if(p==NULL){
		printf("没有查找到该事件\n");
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



/*输出功能*/
void printlist(linklist head){
	listnode *p;
	p=head->next ; 
	if(p==NULL){
		printf("没有信息!\n\n");
		return;   
	}
	printf("编号    时间   内容 \n");
	while(p!=NULL){
		printf("%d\t%s\t%s\n",p->data .num ,p->data .time  ,p->data .matter  );  
		p=p->next ;
	}
}