// Given an already sorted array of positive integers, design an algorithm and implement it using a
// program to find whether a given key element is present in the sorted array or not. For an array 
// arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once 
// the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation 
// from the index 2kto find the element key. 
// (Complexity < O(n), where n is the number of elements need to be scanned for searching):


// We'll be using jump search in this program.

# include "bits/stdc++.h"
using namespace std;

int JumpSearch(vector <int> arr,int key){
    int step = sqrt(arr.size());
    int prev = 0;

    while ( arr[step-1] < key && step < arr.size()){
        prev = step;
        step = step + sqrt(arr.size());
        if(prev>=arr.size()) return -1;
    }

    // Linear search  
    while(arr[prev] < key){
        prev++;
        if(prev >= arr.size()) return -1;
    }

    if(arr[prev]==key){
        return prev;
    }

    return -1;
}


int main()
{
    int t, n, key;
    cout << "Enter TestCases : ";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cout << "Enter Size : ";
        cin >> n;
        vector<int> arr(n);
        cout << "Enter Elements : ";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        cout << "Enter Key : ";
        cin >> key;
        int res = JumpSearch(arr, key);
        if (res == -1)
        {
            cout << "Not Present" << endl;
        }
        else
        {
            cout << "Present" << endl;
        }
    }
}