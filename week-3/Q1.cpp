// Given an unsorted array of integers, design an algorithm and a program to sort the
// array using insertion sort. Your program should be able to find number of
// comparisons and shifts ( shifts - total number of times the array elements are shifted
// from their place) required for sorting the array.

# include "bits/stdc++.h"
using namespace std;


void insertionSort(vector <int> &arr,int *comp,int *shifts){
    int i,j,temp;
    for(i=1;i<arr.size();i++){
        temp = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>temp){
            *comp = *comp + 1;
            *shifts = *shifts + 1;
            arr[j+1]=arr[j];
            j = j-1;
        }
        arr[j+1]=temp;
        *shifts = *shifts + 1;
    }
}


int main(){
    int t;
    cout<<"Enter Tescases : "<<endl; cin>>t;

    for(int it=0;it<t;it++){
        int n,comp=0,shifts=0;
        vector<int> arr;
        cout<<"Enter length of Array : "; cin>>n;
        cout<<"Enter Elements :"; 
        for(int i=0;i<n;i++){
            int num;
            cin>>num;
            arr.push_back(num);
        }

        insertionSort(arr,&comp,&shifts);

        cout<<"Sorted :";
        for(auto it:arr){
            cout<<it<<" ";
        }
        cout<<endl;

        cout<<"Shifts :"<<shifts<<endl;
        cout<<"Comparisions :"<<comp<<endl;
    }


    return 0;
}