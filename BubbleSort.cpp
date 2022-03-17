#include <iostream>
#include <string>
using namespace std;


int main(){
    int arr[] = {4,3,2,1,10,50,9,25};
    int i,j,temp;
    int size = sizeof(arr) / sizeof(arr[0]);
    string s1 = " iteration";
    for(i=1;i<size;i++){
        cout<<i;
        cout<<s1;
        cout<<"\n";
        for(j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    cout<<"\n";
    for ( i = 0; i < size; i++)
    {
        cout<<arr[i];
        cout<<"\n";
    }
    
    cout<<"Done";
    return 0;
}