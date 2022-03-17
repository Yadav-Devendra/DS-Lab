#include <iostream>
#include <string>

using namespace std;

int* bubbleSort(int arr[], int size){
        int n = size;
        for (int i = 0; i < n-1; i++){
            for (int j = 0; j < n-i-1; j++){
                if (arr[j] > arr[j+1])
                {
                    // swap arr[j+1] and arr[j]
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
        return arr;
}

int binarySearch(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at mid, then return it
    if (array[mid] == x)
      return mid;

    // Search the left half
    if (array[mid] > x)
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);
  }

  return -1;
}

/* Prints the array */
    void printArray(int arr[], int size)
    {
        int n = size;
        for (int i=0; i<n; ++i){
            cout<<arr[i]<<" ";
        }
    }

int main(){
    int n, i, s,f;
    int *a;
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
    a = bubbleSort(arr, n);
    cout<<"Sorted array is: ";
    printArray(a, n);
    cout<<"\n";
    f = binarySearch(a, s, 0, n-1);
    if(f == -1){
        cout<<"Element not found";
    }
    else{
        cout<<"Element found at "<<f+1<<" position";
    }
    return 0;
}