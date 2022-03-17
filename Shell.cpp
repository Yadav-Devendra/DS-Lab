#include <iostream>
#include <string>

using namespace std;

 int shellSort(int arr[], int size)
    {
        int n = size;

        // Start with a big gap, then reduce the gap
        for (int gap = n/2; gap > 0; gap /= 2)
        {
            // Do a gapped insertion sort for this gap size.
            // The first gap elements a[0..gap-1] are already
            // in gapped order keep adding one more element
            // until the entire array is gap sorted
            for (int i = gap; i < n; i += 1)
            {
                // add a[i] to the elements that have been gap
                // sorted save a[i] in temp and make a hole at
                // position i
                int temp = arr[i];
 
                // shift earlier gap-sorted elements up until
                // the correct location for a[i] is found
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
 
                // put temp (the original a[i]) in its correct
                // location
                arr[j] = temp;
            }
            cout<<"Pass"<<" : "; 
                for ( int k = 0; k < n; k++)
                {
                    cout<<arr[k]<<" ";
                }
                cout<<endl;
        }
        return 0;
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
    int n, i;
    cout<<"Enter number of elements to be sorted: "<<endl;
    cin>>n;
    int arr[n];
    for ( i = 0; i < n; i++)
    {
        cout<<"Enter "<<i+1<<" element"<<endl;
        cin>>arr[i];
    }
    shellSort(arr, n);
    cout<<"Sorted array is: ";
    printArray(arr, n);
    return 0;
}