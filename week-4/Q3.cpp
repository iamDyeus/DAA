// Given an unsorted array of integers, design an algorithm and implement it using a program to
// find Kth smallest or largest element in the array. (Worst case Time Complexity = O(n))

#include "bits/stdc++.h"
using namespace std;

int kthSmallest(vector <int> arr, int k){
    int min = arr[0];
    int count = arr.size();

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (count == k)
        {
            return arr[i];
        }
        count--;
    }
    return -1;
}

int main(){
    vector <int> arr;
    arr.push_back(4);
    arr.push_back(1);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(9);
    
    int smallest = kthSmallest(arr,2);
    // int largest = kthLargest(arr,2);

    cout<<smallest<<endl;

    return 0;
}