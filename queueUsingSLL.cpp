#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node *front, *rear, *temp = NULL;

void enqueueFront(int data)
{
    temp = new Node(data);
    if (!front)
    {
        front = rear = temp;
    }
    else
    {
        temp->next = front;
        front->prev = temp;
        front = temp;
    }
}

void enqueueRear(int data)
{
    temp = new Node(data);
    if (!rear)
    {
        front = rear = temp;
    }
    else
    {
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }
}

void dequeueFront()
{
    if (!front)
    {
        cout << "Queue is empty" << endl;
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        cout << "Element removed from the queue is :" << front->data << endl;
        front = front->next;
        front -> prev = NULL;
    }
}

void dequeueRear()
{
    if (!rear)
    {
        cout << "Queue is empty" << endl;
    }
    else if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        cout << "Element removed from the queue is :" << rear->data << endl;
        rear = rear -> prev;
        rear -> next = NULL;
    }
}

void display()
{
    temp = front;
    if (!front)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "elements in queue are :" << endl;
        while (temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, val;
    cout << "1.insertfront \n2.insertrear \n3.dequeueFront \n4.dequeueRear \n5.display \n6. \n0.Exit" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to be pushed at front: ";
            cin >> val;
            enqueueFront(val);
            break;

        case 2:
            cout << "Enter element to be pushed at rear: ";
            cin >> val;
            enqueueRear(val);
            break;

        case 3:
            dequeueFront();
            break;

        case 4:
            dequeueRear();
            break;

        case 5:
            display();
            break;

        default:
            break;
        }
    } while (choice != 0);
    return 0;
}