#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node *head = NULL;

void insertStart(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteFront()
{
    if (!head)
    {
        cout << "Underflow" << endl;
    }
    else
    {
        head = head->next;
    }
}

void deleteEnd()
{
    if (!head)
    {
        cout << "UnderFlow" << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
    }
    else
    {
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void reverseList()
{
    Node *prev, *curr, *next;
    prev = NULL;
    next = NULL;
    curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

void search(int val)
{
    Node *temp = head;
    if (!head)
    {
        cout << "UnderFlow" << endl;
        return;
    }
    while (temp != NULL)
    {
        if (temp->data == val)
        {
            cout << "Found in List\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found\n";
}

void insertInBetween(int val, int pos)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        cout << "UnderFlow" << endl;
        return;
    }
    else if (pos == 1)
    {
        newNode -> next = head;
        head = newNode;
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            if(!temp){
                break;
            }
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        temp -> next = newNode;
    }
}

void display()
{
    Node *temp = head;
    if (!head)
    {
        cout << "EMPTY LINKED LIST" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
}

int main()
{
    int choice, val, data, pos;
    cout << "SINGLY LINKED LIST" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1.InsertFront \n2.InsertEnd \n3.Display \n4.Search \n5.Reverse \n6.DeleteFront \n7.DeleteEnd \n8.Delete(by providing data) \n9.Count \n10.Insert in between \n11.Exit " << endl;
    do
    {
        cout << "Enter the Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to append (start): ";
            cin >> val;
            insertStart(val);
            cout << "\n----------------------------------------------" << endl;
            break;
        case 2:
            cout << "Enter data to append (end): ";
            cin >> val;
            insertEnd(val);
            break;
        case 3:
            display();
            cout << "\n----------------------------------------------" << endl;
            break;
        case 4:
            cout << "Enter data to Search : ";
            cin >> data;
            search(data);
            cout << "\n----------------------------------------------" << endl;
            break;
        case 5:
            reverseList();
            display();
            cout << "\n----------------------------------------------" << endl;
            break;
        case 6:
            deleteFront();
            cout << "\n----------------------------------------------" << endl;
            break;
        case 7:
            deleteEnd();
            cout << "\n----------------------------------------------" << endl;
            break;
        case 10:
            cout << "Enter data : ";
            cin >> data;
            cout << "Enter position : ";
            cin >> pos;
            insertInBetween(data, pos);
            cout << "\n----------------------------------------------" << endl;
            break;
        case 11:
            exit(0);
            break;
        default:
            cout << "\nSelect Proper Option (1/2/3/4/5/6/7/8/9/10/11)" << endl;
            break;
        }
    } while (choice != 11);
    return 0;
}