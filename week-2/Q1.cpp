// Given a sorted array of positive integers containing few duplicate elements, design
// an algorithm and implement it using a program to find whether the given key
// element is present in the array or not. If present, then also find the number of copies
// of given key. (Time Complexity = O(log n))


#include "bits/stdc++.h"
using namespace std;

// Solution Approach : 
// We perform binary search and get the key's position (res)
// then we in a loop perform binary search towards the left and right of 'res'
//  until we count all the occurences of the digit.

int BinarySearch(int arr[], int left, int right, int key){
    if(right >= left){
        int mid = left + (right - left) / 2;
        
        if(arr[mid] == key)
            return mid;
        
        if(arr[mid] > key)
            return BinarySearch(arr, left, mid-1, key);
        
        if(arr[mid] < key)
            return BinarySearch(arr, mid+1, right, key);
    }
    return -1;
}

int main()
{
    int iter, len, key, res, first, min, max, count;
    cout << "Enter number of cases: ";
    cin >> iter;
    for (int i = 0; i < iter; i++)
    {
        cout << "Enter length of " << i + 1 << " sorted array: ";
        cin >> len;
        cout << "Enter elements: ";
        int arr[len];
        for (int j = 0; j < len; j++)
            cin >> arr[j];
        cout << "Enter element to search: ";
        cin >> key;
        res = BinarySearch(arr, 0, len - 1, key);
        // Key Found
        if (res != -1)
        {
            // Saving original index
            first = res;
            // Checking duplicates towards left
            while (res != -1)
            {
                min = res;
                res = BinarySearch(arr, 0, res - 1, key);
            }
            // Checking duplicates towards right
            res = first;
            while (res != -1)
            {
                max = res;
                res = BinarySearch(arr, res + 1, len - 1, key);
            }
            cout << key << " - " << max - min + 1 << endl;
        }
        else
            cout << "Key not present" << endl;
    }
}
