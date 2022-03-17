#include <iostream>
#include <cstring>
using namespace std;
//Node defination
class dnode
{
public:
    char number[50];//phone number
    char gmail[40];//email id
    char name[30];//name
    dnode *prev, *next;//previous and next pointers
    dnode(char n[], char r[], char g[])//constructors to initialize the variables
    {
        strcpy(name, n);
        strcpy(number, r);
        strcpy(gmail, g);
        next = NULL;
        prev = NULL;
    }
    friend class dlist;//giving dlist class permission to access members of this class
};
class dlist//directory list
{
    //pointer declarations for operations
    //private pointers
    dnode *head, *temp, *ptr;

    dnode *ptr1, *ptr2, *dup;

public:
    dnode *prevn;

    void insert();
    void sort();
    void deletecontact(char n[20]);
    void deletesamenumber();
    void deletesamename();
    void deletesamegmail();
    void searchbyname(char p[20]);
    void searchbynumber(char no[30]);
    void searchbygmail(char g[20]);

    // dnode *head,*temp,*ptr;
    // friend class apply;
    void accept();
    void display();
    void update(char ch[10]);
    dlist()
    {
        head = NULL;
        temp = NULL;
        ptr = NULL;
        ptr1 = NULL;
        ptr2 = NULL;
        dup = NULL;
    }
};
//function to accept data from users
void dlist::accept()
{
    char number[50];
    char gmail[40];
    char name[30];
    char ans;
    do
    {
        cout << "ENTER NAME :";
        cin >> name;
        // cin.getline (name,30);
        cout << "ENTER NUMBER    :";
        cin >> number;
        while (strlen(number) != 10)//to check lenght of phone number
        {
            cout << "ENTER VALID NUMBER  :";
            cin >> number;
        }
        cout << "ENTER G-MAIL    :";
        cin >> gmail;
        temp = new dnode(name, number, gmail);
        if (head == NULL)//if list is empty assign temp to head
        {
            head = temp;
        }
        else//go till the end of the list and add data there
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;
        }
        cout << "DO YOU WANT TO CONTINUE ? ";
        cin >> ans;
    } while (ans == 'y');
}
void dlist::display()//to display all the data
{
    ptr = head;         // point at the start
    while (ptr != NULL) // traverse till the last node 
    {
        cout << "\n\nNAME  ::\t" << ptr->name;
        cout << "\nNUMBER::\t+91-" << ptr->number;
        cout << "\nG-MAIL::\t" << ptr->gmail;
        ptr = ptr->next;
    }
}

void dlist::insert()
{
    accept();
}
void dlist::sort()//sorting using bubble sort
{
    dnode *i, *j;
    int temp;
    char n[10], no[10], e[10];
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            temp = strcmp(i->name, j->name);
            if (temp > 0)
            {
                //name
                strcpy(n, i->name);
                strcpy(i->name, j->name);
                strcpy(j->name, n);

                //number
                strcpy(no, i->number);
                strcpy(i->number, j->number);
                strcpy(j->number, no);

                //email
                strcpy(e, i->gmail);
                strcpy(i->gmail, j->gmail);
                strcpy(j->gmail, e);
            }
        }
    }
}
void dlist::deletecontact(char s[20])
{
    int c = 0;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(s, ptr->name) == 0)//contact found 
        {
            c = 1;
            break;
        }
        else
        {
            c = 2;
        }
        ptr = ptr->next;
    }
    if (c == 1 && ptr != head && ptr->next != NULL)//contact found in the middle of list
    {
        ptr->prev->next = ptr->next;//set the next of previous pointer to current next
        ptr->next->prev = ptr->prev;//set previous of next pointer to previous pointer
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (ptr == head)//contact to deleted is found first on the list
    {
        head = head->next;
        head->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (ptr->next == NULL)//contact to deleted is found last on the list
    {
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        delete (ptr);
        cout << "YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
    }
    if (c == 2)//contact not found on the list
    {
        cout << "YOUR ENTERED NAME IS NOT IN THE LIST...";
    }
}
void dlist::deletesamename()//delete duplicate name
{
    ptr1 = head;
    if (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->name, ptr2->next->name) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
    }
}
void dlist::deletesamegmail()//delete duplicate gmail
{
    ptr1 = head;
    if (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->gmail, ptr2->next->gmail) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
    }
}
void dlist::deletesamenumber()//delete duplicate number
{
    ptr1 = head;
    if (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (strcmp(ptr1->number, ptr2->next->number) == 0)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete (dup);
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
    }
}
void dlist::searchbyname(char na[10])//search contacts list by name
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(na, ptr->name) == 0)
        {
            cout << "NAME FOUND" << endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"<< endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail;
        }
        ptr = ptr->next;
    }
}
void dlist::searchbynumber(char num[20])//search contacts list by number
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(num, ptr->number) == 0)
        {
            cout << "NUMBER FOUND\n"<< endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"<< endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail;
        }
        ptr = ptr->next;
    }
}
void dlist::searchbygmail(char gm[20])//search contacts list by gmail
{
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(gm, ptr->gmail) == 0)
        {
            cout << "G-MAIL FOUND\n"<< endl;
            cout << "CONTACT DETAILS ARE BELOW:\n"<< endl;
            cout << "\n\nNAME  ::\t" << ptr->name;
            cout << "\nNUMBER::\t+91-" << ptr->number;
            cout << "\nG-MAIL::\t" << ptr->gmail;
        }
        ptr = ptr->next;
    }
}
void dlist::update(char n[20])//update contacts list
{
    char ans;
    int c;
    ptr = head;
    while (ptr != NULL)
    {
        if (strcmp(n, ptr->name) == 0)//check if the name is present in the list
        {

            do
            {
                cout << "\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                cin >> c;
                switch (c)
                {
                case 1:
                    cout << "ENTER NEW-NAME=";
                    cin >> ptr->name;//update name using current pointer
                    break;
                case 2:
                    cout << "ENTER NEW PHONE-NUMBER?";
                    cin >> ptr->number;
                    while (strlen(ptr->number) != 10)
                    {
                        cout << "ENTER VALID NUMBER  :";
                        cin >> ptr->number;//update number using current pointer
                    }
                    break;
                case 3:
                    cout << "ENTER NEW G-MAIL";
                    cin >> ptr->gmail;//update email using current pointer
                    break;
                }
                cout << "DO YOU WANT TO CONTINUE UPDATING?";
                cin >> ans;
            } while (ans == 'y');
        }
        ptr = ptr->next;
    }
}
int main()
{
    char n[20];
    char nam[20];
    char name[10];
    char number[10];
    char gmail[20];
    dlist d1;
    // apply d;
    char ans;
    int ch, a;
    cout << "**************                                PHONE BOOK                          ********************";
    cout << "\n\nWHAT IS YOUR NAME ?\n";
    cin.getline(name, 20);
    cout << "\n\n!!!!!!!!!!!!!!!!!!!!!!!   WELCOME " << name << "   !!!!!!!!!!!!!!!!!!!!!";
    cout << "\n\n\nLET'S CREATE OUR PHONEBOOK " << name << "  \n\n";
    d1.accept();
    d1.sort();
    do
    {
        cout << "\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NAME IN PHONEBOOK\n6) DELETE SAME NUMBERS IN PHONEBOOK\n7) SEARCH\n8)DELETE SAME GMAIL IN PHONEBOOK\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            d1.display();
            break;
        case 2:
            d1.insert();
            d1.sort();
            break;
        case 3:
            cout << "\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
            cin >> n;
            d1.update(n);
            
            d1.sort();
            break;
        case 4:
            cout << "\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
            cin >> name;
            d1.deletecontact(name);
            break;
        case 5:
            d1.deletesamename();
            d1.display();
            break;
        case 6:
            d1.deletesamenumber();
            d1.display();
            break;
        case 7:
            do
            {
                cout << "1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL";
                cin >> a;
                switch (a)
                {
                case 1:
                    cout << "ENTER THE NAME TO BE SEARCHED\n";
                    cin >> name;
                    d1.searchbyname(name);
                    break;
                case 2:
                    cout << "ENTER THE NAME TO BE SEARCHED\n";
                    cin >> number;
                    d1.searchbynumber(number);
                    break;
                case 3:
                    cout << "ENTER THE NAME TO BE SEARCHED\n";
                    cin >> gmail;
                    d1.searchbygmail(gmail);
                    break;
                default:
                    cout << "\nNO PROPER INPUT GIVEN.....\n";
                }
                cout << "DO YOU WANT TO CONTINUE SEARCHING ?";
                cin >> ans;
            } while (ans == 'y');
            break;
        case 8:
            d1.deletesamegmail();
            d1.display();
            break;
        default:
            cout << "\nNO PROPER INPUT GIVEN..\n";
        }
        cout << "\n\nDO YOU WANT TO CONTINUE OPERATIONS ?";
        cin >> ans;
    } while (ans == 'y');
}