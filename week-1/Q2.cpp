// Given an already sorted array of positive integers, design an algorithm and implement it using a 
// program to find whether given key element is present in the array or not. Also, find total number 
// of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input)

# include "bits/stdc++.h"
using namespace std;

int BinarySearch(vector <int> arr, int l, int r , int key, int *comp){
    *comp = *comp + 1;
    if(l<r){
        int mid = (l+r)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid] > key){
            return BinarySearch(arr,l,mid-1,key,comp);
        }
        else {
            return BinarySearch(arr,mid+1,r,key,comp);
        }
    }
    return -1;
}


int main(){
    int t,n,key;
    cout<<"Enter TestCases : ";cin>>t;
    for(int i=0;i<t;i++){
        int comp =0;
        cout<<"Enter Size : "; cin>>n;
        vector <int> arr(n);
        cout<<"Enter Elements : "; for(int i=0;i<n;i++) cin>> arr[i];
        cout<<"Enter Key : "; cin>>key;
        int res = BinarySearch(arr,arr[0],arr[n-1],key,&comp);
        if(res==-1){
            cout<<"Not Present"<<endl;
        } else{
            cout << "Present" << endl;
        }
        cout<<"Comparisions :" << comp << endl;
    }
}