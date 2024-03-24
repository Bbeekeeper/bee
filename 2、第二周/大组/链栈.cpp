#include<iostream>
using namespace std;

typedef struct LinkNode
{
	int data;//������ 
	struct LinkNode*next;//ָ���� 
} 
stackNode,*LinkStack;

//��ջ�ĳ�ʼ�� 
void initStack(LinkStack &s)/////////Ϊʲôvoid������&s����int������ֻ��s 
{
	s=NULL;//����Ҫͷ�ڵ� 
}

//�ж���ջ�Ƿ�Ϊ�� 
int stackEmpty(LinkStack s)
{
	if(s==NULL)
	return 1;
	return 0;
 } 
 
//����ջ�ĳ��ȣ������� 
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
 
//��ջ����ջ
//p���½ڵ㡣�ؼ������ڵ���ջΪ�յ�ʱ��p���ǵ�һ���ڵ㡣 
//����ջ��Ϊ��ʱ������p��nextָ��ָ��s����s���µ�p�ڵ㣬�൱�ڻ�����p��Ϊ��һ���ڵ�
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

//��ջ�ĳ�ջ
//��ջΪ�յ�ʱ�����޷������ģ�newһ��p�ڵ�
//����ջ����ʱ������pָ��s�ĵ�һ���ڵ㣬����s��ʹsָ����һ���ڵ㣬��ɾ��p 
void pop(LinkStack &s,int &e)
{
	stackNode *p=new stackNode;
	if(s==NULL)
	{
		cout << "ջΪ�գ��޷�����" << endl;
	}
	else
	{
		p=s;
		e=p->data;
		s=s->next;
		delete p;
		cout << "�ɹ�����ջ��Ԫ��" << endl;
	}
 } 

//��ջ��Ԫ��
int top(LinkStack s)
{
	if(s==NULL)
	return -1;/////////////////////������Ϊʲô��-1 
	return s->data;
 } 
 
//����ջ
//���нڵ� 
void DestoryStack(LinkStack &s)
{
	stackNode *p;
	while(s)
	{
		p=s;
		s=s->next;
		delete p;
	}
//	s=NULL;/////////////////////////��仰û���壿 
	cout << "�ɹ�����" << endl; 
 } 
 
 void menu()
{
	cout<<"**************************"<<endl;
	cout<<"1.��ʼ��"<<endl;
	cout<<"2.�ж�ջ�Ƿ�Ϊ��"<<endl;
	cout<<"3.��ջ�ĳ���"<<endl;
	cout<<"4.����ջ"<<endl;
	cout<<"5.��ջ"<<endl;
	cout<<"6.��ջ"<<endl;
	cout<<"7.��ջ��Ԫ��"<<endl;
	cout<<"8.�˳�"<<endl;
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
				cout<<"��ʼ���ɹ�"<<endl;
				break;
			case '2':
				if(stackEmpty(s))
					cout<<"ջΪ��"<<endl;
				else
					cout<<"ջ��Ϊ��"<<endl; 
				break;
			case '3':
				cout<<"ջ�ĳ���Ϊ"<<stackLength(s)<<endl;
				break;
			case '4':
				DestoryStack(s);
				break;
			case '5':
				cout<<"��������Ҫ��ջ��Ԫ��ֵ��"<<endl;
				cin>>e1;
				push(s,e1);
				cout<<"��ջ�ɹ�"<<endl; 
				break;	
			case '6':
				pop(s,e2);
				cout<<"������Ԫ��Ϊ"<<e2<<endl;
				break;
			case '7':
				if(top(s)!=-1)
					cout<<"ջ��Ԫ��Ϊ"<<top(s)<<endl;
				else
					cout<<"ջΪ��"<<endl;
				break;
			case '8':
				cout<<"�ɹ��˳�"<<endl;
				exit(0);
			default:
				cout<<"������������������"<<endl;
				break;			
		}	
	}
}
