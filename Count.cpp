#include <bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size);
int maxElement(int arr[], int size);
void countSort(int arr[], int size)
{
    int output[10];
    int count[10];
    int max = maxElement(arr, size);
    cout<<"Max element is :"<<max<<endl;
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    cout<<"Count array"<<endl;
    printArray(count, max + 1);
    for (int i = 0; i < size; i++)
    {
        ++count[arr[i]];
    }
    cout<<"Count array"<<endl;
    printArray(count, max + 1);
    
    for (int i = 1; i <= max; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    cout<<"Count array"<<endl;
    printArray(count, max + 1);
    for (int i = size - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
        cout<<"Position :"<<count[arr[i]]<<endl;
    }
    
    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
    printArray(arr, size);
}
int maxElement(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
int main()
{
    int array[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(array) / sizeof(array[0]);
    cout<<"Unsorted Array"<<endl;
    printArray(array, n);
    cout<<"Sorted Array"<<endl;
    countSort(array, n);
    return 0;
}