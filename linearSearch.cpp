#include<iostream>

using namespace std;

int linearSearch(int arr[], int n, int x){
    for ( int i = 0; i < n; i++)
    {
        if(arr[i] == x){
            return i + 1;
        }
    }
    return 0;
}

int main(){
    int n, i, x, f;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array:"<<endl;
    for ( i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"\nEnter element to search: ";
    cin>>x;
    f = linearSearch(arr, n, x);
    if(!f){
        cout<<"Element not found";
    }
    else{
        cout<<"Element fount at "<<f<<" position";
    }
    return 0;
}