#include<iostream>
using namespace std;
#include<cstdlib>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *create_link(struct Node *head)//创建链表 
{
	head = (struct Node *)malloc(sizeof(struct Node)); //在堆区为头节点申请内存，大小和结构体一样 
	
	head->next = NULL; //头节点是用不到的，不用赋值。只需要给头节点的 next节点赋值空即可 
	
	struct Node *tail = head;//创建一个尾指针 
	
	for(int i = 1;i <= 10;i++)//给链表赋值 
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));//创建临时指针并申请内存 
		temp->data = i;    //给temp指针指向的区域赋值
		temp->next = NULL; //temp的下一个节点赋值空 
		tail->next = temp; //建立连接 
		tail = temp;       //更新内存地址 
	}
	return head;
};

void print_link(struct Node *head)
{
	//不带头节点
	head = head->next;    //head不存在数值，所以从next节点开始 
	while(head != NULL)
	{
		cout << head->data << endl;
		head = head->next;
	} 
}
 
int main()
{
	struct Node *head;
	head = create_link(head);
	print_link(head);
	return 0;
} 
