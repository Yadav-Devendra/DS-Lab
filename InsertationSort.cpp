#include <iostream>
using namespace std;

int main(){
        int arr[] = {4,3,2,1,10,50,9,25};
        int i, j , key;
        int size = sizeof(arr) / sizeof(arr[0]);
        string s1 = " iteration";
        for(i=1;i<size;i++){
          key = arr[i];
          j = i - 1;
          while(j>=0 && arr[j]>key){
              arr[j+1] = key;
              j = j - 1;
          }
          arr[j+1] = key; ```````````````
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