#include<iostream>
#include<string>
#include<stack>
using namespace std;

int postFix(){
    stack<int> stack;
    for(char c: exp){
        if(c >=0 && c <= 9){
            stack.push()
        }
    }
}

int main(){
    string exp = "138*+";
    cout<<evalPostfix(exp);
    return 0;
}