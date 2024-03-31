#include <iostream>
#include <vector>
using namespace std;

vector<int> FindCommon(vector<int> arr1, vector<int> arr2){
    int i=0, j=0, m=arr1.size(), n=arr2.size();
    vector<int> res;
    while(i < m && j < n){
        if(arr1[i] < arr2[j]){
            i++;
        }
        else if(arr1[i] > arr2[j]){
            j++;
        }
        else if(arr1[i] == arr2[j]){
            res.push_back(arr1[i]);
            i++; j++;
        }
    }
    return res;
}

int main(){
    int m, n, temp;
    cout<<"Enter size of first array (m): ";
    cin>>m;
    cout<<"Enter elements: ";
    vector<int> arr1;
    for(int i=0; i<m; i++){
        cin>>temp;
        arr1.push_back(temp);
    }
    cout<<"Enter size of second array (n): ";
    cin>>n;
    cout<<"Enter elements: ";
    vector<int> arr2;
    for(int i=0; i<n; i++){
        cin>>temp;
        arr2.push_back(temp);
    }
    vector<int> res = FindCommon(arr1, arr2);
    if(!res.empty()){
        for(int i=0; i<res.size(); i++)
            cout<<res[i]<<" ";
    } else {
        cout<<"No Common Elements Exist"<<endl;
    }
}

// DONE