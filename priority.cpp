#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    struct Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = data;
        next = NULL;
    }
};

Node *front, *rear, *temp, *q = NULL;

void enqueue(int val, int priority)
{
    q = front;
    temp = new Node(val, priority);
    if (!front)
    {
        front = rear = temp;
    }
    else if(front -> priority > temp -> priority){
        temp -> next = front;
        front = temp;
    }
    else{
        while (q -> next != NULL && temp -> priority >= q -> next -> priority)
        {
            q = q -> next;
        }
        temp -> next = q -> next;
        q -> next = temp;
    }
}

void dequeue()
{
    if(!front){
        cout << "Queue is empty!" << endl;
    }
    else{
        cout << "Element removed from the queue is :" << front->data << endl;
        front = front -> next;
    }
}

void display()
{
    if(!front){
        cout << "Queue is empty!" << endl;
    }
    else{
        cout << "elements in queue are :" << endl;
        temp = front;
        while(temp != NULL){
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, val, priority;
    cout << "1.queue \n2.dequeue \n3.display \n0.Exit" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to be pushed: ";
            cin >> val;
            cout << "Enter priority of the element: ";
            cin >> priority;
            enqueue(val, priority);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    } while (choice != 0);
    return 0;
}