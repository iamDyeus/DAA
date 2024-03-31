// Given an unsorted array of integers, design an algorithm and implement it using a
// program to sort an array of elements by partitioning the array into two subarrays
// based on a pivot element such that one of the sub array holds values smaller than
// the pivot element while another sub array holds values greater than the pivot
// element. Pivot element should be selected randomly from the array. Your program
// should also find number of comparisons and swaps required for sorting the array.

//  Problem Solution : 
// Modified Quick Sort (random pivot choosing)
//  also coujnt no. of swaps and comparisons

# include "bits/stdc++.h"
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int> &arr, int l, int r)
{
    int x = rand() % (r - l + 1) + l;
    swap(&arr[x], &arr[r]);

    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(vector<int> &arr, int l, int r, int &swaps)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        swaps += (p - l);
        quickSort(arr, l, p - 1, swaps);
        quickSort(arr, p + 1, r, swaps);
    }
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, swaps = 0;
        cin >> n;

        vector<int> v(n);
        for (int j = 0; j < n; j++)
        {
            cin >> v[j];
        }

        quickSort(v, 0, n - 1, swaps);
        cout << "Swaps: " << swaps << endl;
        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }
    return 0;
}