#include <bits/stdc++.h>
using namespace std;

bool balance(string expr)
{
    stack<char> s;
    char x;
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
        }
        else if (s.empty())
        {
            return 0;
        }
        else
        {
            switch (expr[i])
            {
            case ')':
                x = s.top();
                if (x == '[' || x == '{')
                {
                    return 0;
                }
                s.pop();
                break;

            case ']':
                x = s.top();
                if (x == '(' || x == '{')
                {
                    return 0;
                }
                s.pop();
                break;

            case '}':
                x = s.top();
                if (x == '(' || x == '[')
                {
                    return 0;
                }
                s.pop();
                break;

            default:
                break;
            }
        }
    }
    return s.empty();
}

int main()
{
    string expr;
    cout << "Enter a string :";
    cin >> expr;
    if (balance(expr))
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not balanced";
    }
    return 0;
}