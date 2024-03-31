// Given an unsorted array of positive integers, design an algorithm and implement it using a
// program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
// Complexity = O(n log n))

#include "bits/stdc++.h"
using namespace std;

bool containsDuplicate(vector <int> arr){
    sort(arr.begin(),arr.end()); // T.C -> N LOG N
    for (int i = 0; i < arr.size()-1; i++) // T.C -> N
    {
        if ( arr[i] == arr[i+1]){
            return true;
        }
    }
    return false;

    // so total Time Complexity -> N(LOGN) + N -> O(N LOG N)
}

int main()
{
    int testcases,num;
    cout<<"Enter TestCases : "; cin >> testcases;

    for(int i=0;i< testcases;i++){
        vector<int> arr;
        int n;
        cout<<"Enter Length of Array : "; cin>>n;
        cout << "Enter Elements : ";
        for(int j=0;j<n;j++){
            cin>>num;
            arr.push_back(num);
        }
        bool hasDuplicates = containsDuplicate(arr);
        if(hasDuplicates){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
}
