#include <iostream>
using namespace std;

int main(){
    int a = 10;
    int &b = a;
    int x = 2;
    int y = x;
    cout<<b<<"=="<<y<<endl;
    a = 20;
    x = 4;
    cout<<b<<"=="<<y<<endl;
    return 0;
}