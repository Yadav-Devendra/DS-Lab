#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *root = NULL;

Node *Insert(Node *root, int data)
{
    if (!root)
    {
        Node *newNode = new Node(data);
        return newNode;
    }
    else if (data > (root->data))
    {
        root->right = Insert(root->right, data);
    }
    else if (data < (root->data))
    {
        root->left = Insert(root->left, data);
    }
    return root;
}

Node *Delet(treeNode *node, int data)
{
    Node *temp;
    if (node == NULL)
    {
        cout << "Element Not Found";
    }
    else if (data < node->data)
    {
        node->left = Delet(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = Delet(node->right, data);
    }
    else
    {
        if (node->right && node->left)
        {
            temp = FindMin(node->right);
            node->data = temp->data;
            node->right = Delet(node->right, temp->data);
        }
        else
        {
            temp = node;
            if (node->left == NULL)
                node = node->right;
            else if (node->right == NULL)
                node = node->left;
            free(temp);
        }
    }
    return node;
}

void Inorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    Inorder(node->left);
    cout << node->data << " ";
    Inorder(node->right);
}

void Preorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    Preorder(node->left);
    Preorder(node->right);
}

void Postorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    Postorder(node->left);
    Postorder(node->right);
    cout << node->data << " ";
}

int main()
{
    int choice, val;
    cout << "BINARY TREE OPERATIONS" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.FindMin\n7.FindMax\n8.Search\n9.Count\n10.Exit\n ";
    do
    {
        cout << "\nEnter the Choice: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter element to be insert:";
            cin >> val;
            root = Insert(root, val);
            cout << "\nElements in BST are:";
            Inorder(root);
            cout << "\n----------------------------------------------" << endl;
            break;
        case 2:
            cout << "\nEnter element to be deleted:";
            cin >> val;
            root = Delet(root, val);
            cout << "\nAfter deletion elements in BST are:";
            Inorder(root);
            cout << "\n----------------------------------------------" << endl;
            break;
        case 3:
            cout << "\nInorder Travesals is:";
            Inorder(root);
            cout << "\n----------------------------------------------" << endl;
            break;
        case 4:
            cout << "\nPreorder Traversals is:";
            Preorder(root);
            cout << "\n----------------------------------------------" << endl;
            break;
        case 5:
            cout << "\nPostorder Traversals is:";
            Postorder(root);
            cout << "\n----------------------------------------------" << endl;
            break;
        // case 6:
        //     temp = FindMin(root);
        //     cout << "\nMinimum element is :" << temp->data;
        //     cout << "\n----------------------------------------------" << endl;
        //     break;
        // case 7:
        //     temp = FindMax(root);
        //     cout << "\nMaximum element is :" << temp->data;
        //     cout << "\n----------------------------------------------" << endl;
        //     break;
        // case 8:
        //     cout << "\nEnter element to be searched:";
        //     cin >> ch;
        //     temp = Find(root, ch);
        //     if (temp == NULL)
        //     {
        //         cout << "Element is not found" << endl;
        //     }
        //     else
        //     {
        //         cout << "Element " << temp->data << " is Found\n";
        //     }
        //     cout << "\n----------------------------------------------" << endl;
        //     break;
        case 10:
            exit(0);
            break;
        default:
            cout << "\nSelect Proper Option (1/2/3/4/5/6/7/8/9/10)" << endl;
            break;
        }
    } while (choice != 10);
    return 0;
}