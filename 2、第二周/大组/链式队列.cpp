#include<iostream>
using namespace std;

// 定义数据类型
typedef int DataType;

// 链式队列的逻辑结构
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

// 判断队列是否为空
bool QueueEmpty()
{
    return Q.front == NULL;
}

// 链式队列入队
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

// 链式队列出队
DataType DeQueue()
{
    if (QueueEmpty())
    {
        cout << "队列为空" << endl;
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
    cout << "1.初始化" << endl;
    cout << "2.入队" << endl;
    cout << "3.出队" << endl;
    cout << "4.退出" << endl;
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
                cout << "队列已初始化" << endl;
                break;
            case '2':
                cout << "请输入想要入栈的元素值：" << endl;
                cin >> e1;
                EnQueue(e1);
                cout << "入队成功" << endl;
                break;
            case '3':
                if (!QueueEmpty()) {
                    cout << "出队元素为：" << DeQueue() << endl;
                } else {
                    cout << "队列为空，无法出队" << endl;
                }
                break;
            case '4':
                cout << "成功退出" << endl;
                exit(0);
            default:
                cout << "输入有误，请重新输入" << endl;
                break;
        }
    }
    return 0;
}
