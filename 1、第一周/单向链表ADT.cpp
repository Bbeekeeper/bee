#include<iostream>
using namespace std; 
#include<cstdlib>

struct node
{
	int data;
	struct node* next;
};

struct node* initialization(struct node* head)
{
	struct node* tail = head;
	while (tail)
	{
		cin >> tail->data;
		tail->next = (struct node*)malloc(sizeof(struct node));
		if (tail->data == 0)
		{
			tail->next = NULL;
			break;
		}
		else 
		{
			tail = tail->next;
		}
	}
	return head;
}

void insert(struct node* tail)
{
	while (tail)
	{
		cin >> tail->data;
		tail->next = (struct node*)malloc(sizeof(struct node));
		if (tail->data == 0)
		{
			tail->next = NULL;
			break;
		}
		else
		{
			tail = tail->next;
		}
	}
}
void print(struct node* head)
{
	while (head)
	{
		cout << head->data << endl;
		head = head->next;
	}
}
void by_value(struct node* head,int num)
{
	while (head)
	{
		if (head->data == num)
		{
			cout << head->data << endl;
		}
		head = head->next;
	}
}
void by_point(struct node* head, int sum)
{
	int s = 1;
	while (head)
	{
		if (s==sum)
		{
			cout << head->data << endl;
			break;
		}
		head = head->next;
		s++;
	}
}
void del(struct node* head,int sum)
{
	int s = 1;
	while (head)
	{
		if (s == sum-1)
		{
			head->next = head->next->next;
			
			break;
		}
		head = head->next;
		s++;
	}
}
void des(struct node* head)
{
	while (head)
	{
		struct node* L = head;
		head = head->next;
		free(L);
			L->next = NULL;
	}
}
int main()
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	struct node* tail = head;
	while (1)
	{
		cout << "1、链表初始化" << endl;
		cout << "2、插入链表" << endl;
		cout << "3、按位查找" << endl;
		cout << "4、按值查找" << endl;
		cout << "5、删除结点" << endl;
		cout << "6、打印链表" << endl;
		cout << "7、销毁链表" << endl;
		cout << "0、退出" << endl;
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << "1、链表初始化\n" << endl;
			struct node* tail = initialization(head);
			cout << "链表初始化成功\n" << endl;
		}
		if (n == 2)
		{
			cout << "2、插入链表\n" << endl;
			insert(tail);
			cout << "插入链表成功\n" << endl;
		}
		if (n == 3)
		{
			cout << "3、按位查找\n" << endl;
			int sum;
			cin >> sum;
			by_point(head, sum);
			cout << "按位查找成功\n" << endl;
		}
		if (n == 4)
		{
			cout << "4、按值查找\n" << endl;
			int num;
			cin >> num;
			by_value(head, num);
			cout << "按值查找成功\n" << endl;
		}
		if (n == 5)
		{
			cout << "5、删除结点\n" << endl;
			int sum;
			cin >> sum;
			del(head, sum);
			cout << "删除结点成功\n" << endl;
		}
		if (n == 6)
		{
			cout << "6、打印链表\n" << endl;
			print(head);
			cout << "打印链表成功\n" << endl;
		}
		if (n == 7)
		{
			cout << "7、销毁链表\n" << endl;
			des(head);
			cout << "销毁链表成功\n" << endl;
		}
		if (n == 0)
		{
			cout << "0、退出\n" << endl;
			break;
		}
	}
}
