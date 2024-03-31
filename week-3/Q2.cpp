// Given an unsorted array of integers, design an algorithm and implement a program to sort this
// array using selection sort. Your program should also find number of comparisons and number of
// swaps required.

#include "bits/stdc++.h"
using namespace std;

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(vector<int> &arr, int *comp, int *swaps)
{
    int i, j, min_index;
    for (i = 0; i < arr.size()-1; i++)
    {
        min_index = i;
        for(j=i+1;j<arr.size();j++){
            if(arr[j]<arr[min_index]){
                *comp =*comp + 1;
                min_index = j;
            }
        }
        
        *swaps = *swaps+1;
        swap(&arr[min_index],&arr[i]);
        
        // Alternative Modified selection sort :
        // if(min_index != i){
        //     *swaps = *swaps+1;
        //     swap(&arr[min_index],&arr[i]);
        // }
    }
}

int main()
{
    int t;
    cout << "Enter Tescases : " << endl;
    cin >> t;

    for (int it = 0; it < t; it++)
    {
        int n, comp = 0, swaps = 0;
        vector<int> arr;
        cout << "Enter length of Array : ";
        cin >> n;
        cout << "Enter Elements :";
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr.push_back(num);
        }

        selectionSort(arr, &comp, &swaps);

        cout << "Sorted :";
        for (auto it : arr)
        {
            cout << it << " ";
        }
        cout << endl;

        cout << "Shifts :" << swaps << endl;
        cout << "Comparisions :" << comp << endl;
    }

    return 0;
}