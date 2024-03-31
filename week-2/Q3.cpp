//  Given an array of nonnegative integers, design an algorithm and a program to count the number
// of pairs of integers such that their difference is equal to a given key, K.


// Solution Approach : 
// - firstly sort the array
// - using a brute force aproach traverse to find (arr[i] - arr[k] == key)

#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}

void QuickSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int p = partition(arr, left, right);
    QuickSort(arr, left, p - 1);
    QuickSort(arr, p + 1, right);
}

int FindDifference(vector<int> arr, int key)
{
    int len = arr.size(), res = 0;
    QuickSort(arr, 0, len - 1);
    for (int i = len - 1; i >= 1; i--)
        for (int j = len - 2; j >= 0; j--)
            if (arr[i] - arr[j] == key)
                res++;
    return res;
}

int main()
{
    int iter, len, temp, key, res;
    cout << "Enter number of cases: ";
    cin >> iter;
    for (int i = 0; i < iter; i++)
    {
        cout << "Enter length of " << i + 1 << " case: ";
        cin >> len;
        cout << "Enter elements: ";
        vector<int> arr;
        for (int j = 0; j < len; j++)
        {
            cin >> temp;
            arr.push_back(temp);
        }
        cout << "Enter key element: ";
        cin >> key;
        res = FindDifference(arr, key);
        cout << res << endl;
    }
}
