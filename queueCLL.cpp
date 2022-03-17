#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};

Node *front, *rear, *temp = NULL;

void enqueue(int val){
    temp = new Node(val);
    if(!front){
        front = rear = temp;
    }
    else{
        rear -> next = temp;
        temp -> next = front;
        rear = temp;
    }
}

void dequeue(){
    if(!front){
        cout<<"Queue is empty"<<endl;
    }
    else if( front == rear){
        front = rear = NULL;
    }
    else{
        cout << "Element removed from the queue is :" << front->data << endl;
        front = front -> next;
    }
}

void display(){
    temp = front;
    if (!front)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        cout << "elements in queue are :" << endl;
        do
        {
            cout << temp->data << endl;
            temp = temp->next;
        }while(temp != rear -> next);
    }
}

int main(){
    int choice, val;
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
            enqueue(val);
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