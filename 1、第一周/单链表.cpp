#include<iostream>
using namespace std;
#include<cstdlib>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *create_link(struct Node *head)//�������� 
{
	head = (struct Node *)malloc(sizeof(struct Node)); //�ڶ���Ϊͷ�ڵ������ڴ棬��С�ͽṹ��һ�� 
	
	head->next = NULL; //ͷ�ڵ����ò����ģ����ø�ֵ��ֻ��Ҫ��ͷ�ڵ�� next�ڵ㸳ֵ�ռ��� 
	
	struct Node *tail = head;//����һ��βָ�� 
	
	for(int i = 1;i <= 10;i++)//������ֵ 
	{
		struct Node *temp = (struct Node *)malloc(sizeof(struct Node));//������ʱָ�벢�����ڴ� 
		temp->data = i;    //��tempָ��ָ�������ֵ
		temp->next = NULL; //temp����һ���ڵ㸳ֵ�� 
		tail->next = temp; //�������� 
		tail = temp;       //�����ڴ��ַ 
	}
	return head;
};

void print_link(struct Node *head)
{
	//����ͷ�ڵ�
	head = head->next;    //head��������ֵ�����Դ�next�ڵ㿪ʼ 
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
