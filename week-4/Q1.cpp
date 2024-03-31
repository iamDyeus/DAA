// Given an unsorted array of integers, design an algorithm and implement it using a
// program to sort an array of elements by dividing the array into two subarrays and
// combining these subarrays after sorting each one of them. Your program should
// also find number of comparisons and inversions during sorting the array

// Problem understanding :
// TO PERFORM MERGE SORT
// ALSO COUNT COMPARISIONS & INVERSIONS


# include "bits/stdc++.h"
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int l, int m, int r, int &comp)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
        comp++;
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int> &arr, int l, int r, int &comp)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid, comp);
        mergeSort(arr, mid + 1, r, comp);
        merge(arr, l, mid, r, comp);
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, comp = 0;
        cin >> n;

        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }

        mergeSort(v, 0, n - 1, comp);
        cout << "Comparisons: " << comp << endl;
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
