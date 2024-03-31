// Given an array of nonnegative integers, design a linear algorithm and implement it using a 
// program to find whether given key element is present in the array or not. Also, find total number 
// of comparisons for each input case. (Time Complexity = O(n), where n is the size of input) 


#include "bits/stdc++.h"
using namespace std;

int LinearSearch(int arr[], int len, int key)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int iter, len, key, res;
    cout << "Enter number of cases: ";
    cin >> iter;
    for (int i = 0; i < iter; i++)
    {
        cout << "Enter length of " << i + 1 << " case: ";
        cin >> len;
        cout << "Enter elements: ";
        int arr[len];
        for (int j = 0; j < len; j++)
            cin >> arr[j];
        cout << "Enter element to search: ";
        cin >> key;
        res = LinearSearch(arr, len, key);
        if (res < 0)
            cout << "Not Present" << endl;
        else
            cout << "Present, comparisons : " << res + 1 << endl;
    }
}

