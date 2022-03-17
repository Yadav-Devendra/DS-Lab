#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};
Node *head = NULL, *tail = NULL;

void insertFirst(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertLast(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
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
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }
    else
    {
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            if (!temp)
            {
                break;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next->prev = newNode;
    }
}

// void insertAfter(int old, int element)
// {
//     Node newNode = new Node();
//     Node *temp = head;

//     if (!head)
//     {
//         cout << "Empty LIST!";
//     }
//     else if (head == tail)
//     {
//         if (head->value != old)
//         {
//             return;
//         }
//         newItem->value = element;
//         head->next = newItem;
//         newItem->next = NULL;
//         head->prev = NULL;
//         newItem->prev = head;
//         tail = newItem;
//         return;
//     }
//     if (tail->value == element)
//     {
//         newItem->next = NULL;
//         newItem->prev = tail;
//         tail->next = newItem;
//         tail = newItem;
//         return;
//     }
//     while (temp->value != old)
//     {
//         temp = temp->next;
//         if (temp == NULL)
//         {
//             cout << "Could not insert" << endl;
//             cout << "Element not found" << endl;
//             return;
//         }
//     }
//     newItem->next = temp->next;
//     newItem->prev = temp;
//     newItem->value = element;
//     temp->next->prev = newItem;
//     temp->next = newItem;
// }

void deleteFirst()
{
    if (!head)
    {
        cout << "Empty LIST!";
    }
    else if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
    }
}
void deleteLast()
{
    if (!head)
    {
        cout << "Empty LIST!";
    }
    else if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        temp->prev = NULL;
    }
}

void searchItem(int element)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            cout << "Found in List!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found!" << endl;
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

void printList()
{
    Node *temp = head;
    if (!head)
    {
        cout << "Empty LIST!";
    }
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
}

int main()
{
    int choice, old, newitem, item, elementStart, elementEnd, pos, data;
    cout << "DOUBLY LINKED LIST" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1.InsertFirst\n2.InsertLast\n3.InsertAfter\n4.DeleteFirst\n5.DeleteLast\n6.SearchItem\n7.PrintList\n8.ReversePrint\n9.DeleteItem\n10.Count\n11.Makereverse\n12.Exit\n ";
    do
    {
        cout << "\nEnter the Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter data to append :- (start)";
            cin >> elementStart;
            insertFirst(elementStart);
            printList();
            cout << "\n----------------------------------------------" << endl;
            break;

        case 2:
            cout << "Enter data to append :- (end)";
            cin >> elementEnd;
            insertLast(elementEnd);
            printList();
            cout << "\n----------------------------------------------" << endl;
            break;

        case 3:
            cout << "Enter data : ";
            cin >> data;
            cout << "Enter position : ";
            cin >> pos;
            insertInBetween(data, pos);
            printList();
            cout << "\n----------------------------------------------" << endl;
            break;
        case 4:
            deleteFirst();
            printList();
            cout << "\n----------------------------------------------" << endl;
            break;

        case 5:
            deleteLast();
            printList();
            cout << "\n----------------------------------------------" << endl;
            break;

        case 6:
            cout << "Enter Item to Search :";
            cin >> item;
            searchItem(item);
            break;

        case 7:
            printList();
            cout << "\n----------------------------------------------" << endl;
            break;

        case 8:
            reverseList();
            printList();
            cout << "\n----------------------------------------------" << endl;
            break;
        // case 11:
        // {
        //     makereverse();
        //     printList();
        //     cout << "\n----------------------------------------------" << endl;
        //     break;
        // }
        // case 12:
        // {
        //     exit(1);
        //     break;
        // }
        default:
            cout << "\nSelect Proper Option (1/2/3/4/5/6/7/8/9/10/11/12)" << endl;
        }
    } while (choice != 12);
    return 0;
}