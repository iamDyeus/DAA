#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &arr, int left, int right){
    int pivot = arr[right];
    int i = left-1;
    for(int j=left; j<right; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void QuickSort(vector<int> &arr, int left, int right){
    if(left>=right) return;
    int p = partition(arr, left, right);
    QuickSort(arr, left, p-1);
    QuickSort(arr, p+1, right);
}

vector<int> FindSum(vector<int> arr, int key){
    int len = arr.size();
    vector<int> res;
    int i=0, j=len-1;
    while(arr[j] >= key)
        j--;
    while(i < j){
        if(arr[i] + arr[j] == key){
            res.push_back(arr[i]);
            res.push_back(arr[j]);
            return res;
        }

        if(arr[i] + arr[j] < key)
            i++;
        if(arr[i] + arr[j] > key)
            j--;
    }
    return res;
}

int main(){
    int iter, len, temp, key;
    cout<<"Enter number of cases: ";
    cin>>iter;
    for(int i=0; i<iter; i++){
        cout<<"Enter length of "<<i+1<<" case: ";
        cin>>len;
        cout<<"Enter elements: ";
        vector<int> arr;
        for(int j=0; j<len; j++){
            cin>>temp;
            arr.push_back(temp);
        }
        cout<<"Enter the key: ";
        cin>>key;
        QuickSort(arr, 0, len-1);
        vector<int> res = FindSum(arr, key);
        if(!res.empty())
            cout<<res[0]<<" "<<res[1]<<endl;
        else
            cout<<"No Such Element Exist"<<endl;
    }
}

// DONE