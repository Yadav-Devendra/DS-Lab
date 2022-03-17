#include <iostream>
using namespace std;

void bubbleSort(int *arr, int size)
{

    int n = size;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap arr[j+1] and arr[j]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int x){
    int l, h, m;
    l = arr[0];
    h = arr[n-1];

    while(l <= h){
        m = l + (h - l) / 2;

        if(arr[m] == x){
            return m + 1;
        }
        else if(arr[m] > x){
            h = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    return 0;
}

int main()
{
    int n, i, x, f;
    cout << "Enter number of elements for array: ";
    cin >> n;
    int arr[n];
    cout<<"Enter elements in the array:"<<endl;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to search: ";
    cin >> x;
    bubbleSort(arr, n);
    // cout<<"Sorted array is\n";
    // for ( i = 0; i < n; i++)
    // {
    //     cout<<arr[i]<<endl;
    // }
    f = binarySearch(arr, n, x);
    if(!f){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at "<<f<<" position";
    }
    return 0;
}