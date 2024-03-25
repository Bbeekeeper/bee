#include<iostream>
using namespace std;

// ������������
typedef int DataType;

// ��ʽ���е��߼��ṹ
struct QueueNode
{
    DataType data;
    QueueNode *next;
};

struct LinkQueue
{
    QueueNode *front;
    QueueNode *rear;
};

LinkQueue Q;

// �ж϶����Ƿ�Ϊ��
bool QueueEmpty()
{
    return Q.front == NULL;
}

// ��ʽ�������
void EnQueue(DataType x)
{
    QueueNode* p = new QueueNode;
    p->data = x;
    p->next = NULL;
    if (Q.rear == NULL) {
        Q.front = p;
        Q.rear = p;
    } else {
        Q.rear->next = p;
        Q.rear = p;
    }
}

// ��ʽ���г���
DataType DeQueue()
{
    if (QueueEmpty())
    {
        cout << "����Ϊ��" << endl;
        exit(0);
    }
    else
    {
        QueueNode* p = Q.front;
        DataType data = p->data;
        Q.front = Q.front->next;
        if (Q.front == NULL) {
            Q.rear = NULL;
        }
        delete p;
        return data;
    }
}

void menu()
{
    cout << "**************************" << endl;
    cout << "1.��ʼ��" << endl;
    cout << "2.���" << endl;
    cout << "3.����" << endl;
    cout << "4.�˳�" << endl;
    cout << "**************************" << endl;
}

int main()
{
    char choice;
    int e1;
    while (true)
    {
        menu();
        cin >> choice;
        switch (choice)
        {
            case '1':
                Q.front = NULL;
                Q.rear = NULL;
                cout << "�����ѳ�ʼ��" << endl;
                break;
            case '2':
                cout << "��������Ҫ��ջ��Ԫ��ֵ��" << endl;
                cin >> e1;
                EnQueue(e1);
                cout << "��ӳɹ�" << endl;
                break;
            case '3':
                if (!QueueEmpty()) {
                    cout << "����Ԫ��Ϊ��" << DeQueue() << endl;
                } else {
                    cout << "����Ϊ�գ��޷�����" << endl;
                }
                break;
            case '4':
                cout << "�ɹ��˳�" << endl;
                exit(0);
            default:
                cout << "������������������" << endl;
                break;
        }
    }
    return 0;
}
