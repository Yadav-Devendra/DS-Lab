#include <iostream>
using namespace std;

// int stack[100], top, choice, val, n;

// void push(int val)
// {
//     if (top >= n - 1)
//     {
//         cout << "Stack Overflow"<<endl;
//     }
//     else
//     {
//         top++;
//         stack[top] = val;
//     }
// }

// void pop(){
//     if(top < 0){
//         cout<<"The Stack is empty"<<endl;
//     }
//     else{
//         cout<<"The popped element is :"<<stack[top]<<endl;
//         top--;
//     }
// }

// void display()
// {
//     if (top >= 0)
//     {
//         cout << "Elements in the stack are :" << endl;
//         for (int i = top; i >= 0; i--)
//         {
//             cout<<stack[i]<<endl;
//         }
//         cout<<"Press next choice"<<endl;
//     }
//     else{
//         cout<<"Stack is empty"<<endl;
//     }
// }

// void Top(){
//     if(top < 0){
//         cout<<"The Stack is empty"<<endl;
//     }
//     else{
//         cout<<"Top of the stack is "<<stack[top]<<endl;
//     }
// }

// void isEmpty(){
//     if(top < 0){
//         cout<<"Stack is empty"<<endl;
//     }
//     else{
//         cout<<"Stack is not empty"<<endl;
//     }
// }

// void numberOfElements(){
//     cout<<"Total number of elements are :"<<top + 1<<endl;
// }

struct Node{
    int data;
    struct Node *link;
};
Node *top = NULL;
int count = 0;

void push(int data){
    Node *temp = new Node();
    temp -> data = data;
    if(!top){
        top = temp;
        count++;
        return;
    }
    temp -> link = top;
    top = temp;
    count++;
}

void pop(){
    if(!top){
        cout<<"Stack is Empty!"<<endl;
        return;
    }
    cout<<"Popped element is: "<<top -> data<<endl;
    top = top -> link;
    count--;
}

void display(){
    if(!top){
        cout<<"Stack is Empty!"<<endl;
    }
    else{
        Node *temp = top;
        while(temp != NULL){
            cout<<temp -> data<<endl;
            temp = temp -> link;
        }
    }
}

void isEmpty(){
    if(!top){
        cout<<"Stack is Empty!"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}

void Top(){
    if(!top){
        cout<<"Stack is Empty!"<<endl;
    }
    else{
        cout<<"Top of the stack is :"<<top -> data<<endl;
    }
}

void numberOfElements(){
    cout<<"Number of elements in Stack are :"<<count<<endl;
}

int main()
{
    int choice, val;
    // top = -1;
    // cout << "Enter the size of stack :";
    // cin >> n;
    cout << "1.Push \n2.Pop \n3.Display \n4.Top \n5.IsEmpty \n6.Count \n0.Exit" << endl;
    do
    {
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter element to be pushed: ";
            cin >> val;
            push(val);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            Top();
            break;

        case 5:
            isEmpty();
            break;
        
        case 6:
            numberOfElements();
            break;

        default:
            break;
        }
    } while (choice != 0);
    // for (int i = 0; i < n; i++)
    //     {
    //         cout<<stack[i]<<endl;
    //     }
    return 0;
}