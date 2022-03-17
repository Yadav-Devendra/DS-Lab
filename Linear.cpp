#include <iostream>
#include <string>

using namespace std;

int linearSearch(int arr[], int n, int s){
    for(int i = 0; i < n; i++){
        if(arr[i] == s){
            return i;
        }
    }
    return -1;
}

int main(){
    int n, i, s,f;
    cout<<"Enter elements for array: "<<endl;
    cin>>n;
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        cout<<"Enter "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    cout<<"Enter element to search: "<<endl;
    cin>>s;
    f = linearSearch(arr,n,s);
    if(f == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at "<<f+1<<" position";
    }
    return 0;
}