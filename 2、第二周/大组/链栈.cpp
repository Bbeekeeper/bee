#include<iostream>
using namespace std;

typedef struct LinkNode
{
	int data;//数据域 
	struct LinkNode*next;//指针域 
} 
stackNode,*LinkStack;

//链栈的初始化 
void initStack(LinkStack &s)/////////为什么void后面是&s，而int后面是只有s 
{
	s=NULL;//不需要头节点 
}

//判断链栈是否为空 
int stackEmpty(LinkStack s)
{
	if(s==NULL)
	return 1;
	return 0;
 } 
 
//求链栈的长度，结点个数 
int stackLength(LinkStack s)
{
	int sum=0;
	stackNode *temp=s;
	while(temp!=NULL)
	{
		sum++;
		temp=temp->next;
	}
	return sum;
 } 
 
//链栈的入栈
//p是新节点。关键处在于当：栈为空的时候，p就是第一个节点。 
//而当栈不为空时，则让p的next指针指向s，而s更新到p节点，相当于还是让p作为第一个节点
void push(LinkStack &s,int e)
{
	stackNode *p=new stackNode;
	p->data=e;
	p->next=NULL;
	if(s==NULL)
	s=p;
	else
	{
		p->next=s;
		s=p;
	}
}

//链栈的出栈
//当栈为空的时候，是无法弹出的，new一个p节点
//而当栈不空时，则让p指向s的第一个节点，更新s，使s指向下一个节点，再删掉p 
void pop(LinkStack &s,int &e)
{
	stackNode *p=new stackNode;
	if(s==NULL)
	{
		cout << "栈为空，无法弹出" << endl;
	}
	else
	{
		p=s;
		e=p->data;
		s=s->next;
		delete p;
		cout << "成功弹出栈顶元素" << endl;
	}
 } 

//求栈顶元素
int top(LinkStack s)
{
	if(s==NULL)
	return -1;/////////////////////这里又为什么是-1 
	return s->data;
 } 
 
//销毁栈
//所有节点 
void DestoryStack(LinkStack &s)
{
	stackNode *p;
	while(s)
	{
		p=s;
		s=s->next;
		delete p;
	}
//	s=NULL;/////////////////////////这句话没意义？ 
	cout << "成功销毁" << endl; 
 } 
 
 void menu()
{
	cout<<"**************************"<<endl;
	cout<<"1.初始化"<<endl;
	cout<<"2.判断栈是否为空"<<endl;
	cout<<"3.求栈的长度"<<endl;
	cout<<"4.销毁栈"<<endl;
	cout<<"5.入栈"<<endl;
	cout<<"6.出栈"<<endl;
	cout<<"7.求栈顶元素"<<endl;
	cout<<"8.退出"<<endl;
	cout<<"**************************"<<endl;
}
int main()
{
	char choice;
	LinkStack s;
	int e1,e2;
	while(1)
	{
		menu();
		cin>>choice;
		switch(choice)
		{
			case '1':
				initStack(s);
				cout<<"初始化成功"<<endl;
				break;
			case '2':
				if(stackEmpty(s))
					cout<<"栈为空"<<endl;
				else
					cout<<"栈不为空"<<endl; 
				break;
			case '3':
				cout<<"栈的长度为"<<stackLength(s)<<endl;
				break;
			case '4':
				DestoryStack(s);
				break;
			case '5':
				cout<<"请输入想要入栈的元素值："<<endl;
				cin>>e1;
				push(s,e1);
				cout<<"入栈成功"<<endl; 
				break;	
			case '6':
				pop(s,e2);
				cout<<"弹出的元素为"<<e2<<endl;
				break;
			case '7':
				if(top(s)!=-1)
					cout<<"栈顶元素为"<<top(s)<<endl;
				else
					cout<<"栈为空"<<endl;
				break;
			case '8':
				cout<<"成功退出"<<endl;
				exit(0);
			default:
				cout<<"输入有误，请重新输入"<<endl;
				break;			
		}	
	}
}
