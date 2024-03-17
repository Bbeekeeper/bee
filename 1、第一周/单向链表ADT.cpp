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
		cout << "1�������ʼ��" << endl;
		cout << "2����������" << endl;
		cout << "3����λ����" << endl;
		cout << "4����ֵ����" << endl;
		cout << "5��ɾ�����" << endl;
		cout << "6����ӡ����" << endl;
		cout << "7����������" << endl;
		cout << "0���˳�" << endl;
		int n;
		cin >> n;
		if (n == 1)
		{
			cout << "1�������ʼ��\n" << endl;
			struct node* tail = initialization(head);
			cout << "�����ʼ���ɹ�\n" << endl;
		}
		if (n == 2)
		{
			cout << "2����������\n" << endl;
			insert(tail);
			cout << "��������ɹ�\n" << endl;
		}
		if (n == 3)
		{
			cout << "3����λ����\n" << endl;
			int sum;
			cin >> sum;
			by_point(head, sum);
			cout << "��λ���ҳɹ�\n" << endl;
		}
		if (n == 4)
		{
			cout << "4����ֵ����\n" << endl;
			int num;
			cin >> num;
			by_value(head, num);
			cout << "��ֵ���ҳɹ�\n" << endl;
		}
		if (n == 5)
		{
			cout << "5��ɾ�����\n" << endl;
			int sum;
			cin >> sum;
			del(head, sum);
			cout << "ɾ�����ɹ�\n" << endl;
		}
		if (n == 6)
		{
			cout << "6����ӡ����\n" << endl;
			print(head);
			cout << "��ӡ����ɹ�\n" << endl;
		}
		if (n == 7)
		{
			cout << "7����������\n" << endl;
			des(head);
			cout << "��������ɹ�\n" << endl;
		}
		if (n == 0)
		{
			cout << "0���˳�\n" << endl;
			break;
		}
	}
}
