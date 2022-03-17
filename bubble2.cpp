#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printArray(array<int, 10> arr);

void insertionSort(array<int, 10> arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = i; j > 0; j--)
        {
            // cout<<j-1<<" "<<j<<endl;
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
        }
        // cout<<"Next pass"<<endl;
    }
    printArray(arr);
}
void selectionSort(array<int, 10> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(arr[i], arr[min]);
        }
    }
    printArray(arr);
}
void shellSort(array<int, 10> arr)
{
    for (int gap = arr.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < arr.size(); i++)
        {
            for (int j = i - gap; j >= 0; j -= gap)
            {
                if (arr[j] > arr[j + gap])
                {
                    swap(arr[j + gap], arr[j]);
                }
            }
        }
    }
    printArray(arr);
}
void bubbleSort(array<int, 10> arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int swapped = 0;
        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = 1;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    printArray(arr);
}
void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = x;
}
void printArray(array<int, 10> arr)
{
    for (auto element : arr)
    {
        cout << element << endl;
    }
}
int main()
{
    array<int, 10> arr;
    cout << "Size of the array is :" << arr.size() << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = (rand() % 100 + 1);
    }
    cout << "Unsorted Array\n";
    printArray(arr);
    cout << "Sorted Array\n";
    // bubbleSort(arr);
    // insertionSort(arr);
    // selectionSort(arr);
    shellSort(arr);
    return 0;
}