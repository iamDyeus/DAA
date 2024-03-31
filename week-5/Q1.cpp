#include <iostream>
#include <vector>
using namespace std;

void CheckDuplicate(vector<char> arr){
    int minEle=arr[0], maxEle=arr[0], len = arr.size();
    for(int i=1; i<len; i++){
        if(maxEle<arr[i])
            maxEle = arr[i];
        if(minEle>arr[i])
            minEle = arr[i];
    }
    vector<int> countArr;
    countArr.assign(maxEle-minEle+1, 0);
    for(int i=0; i<len; i++){
        countArr[arr[i]-minEle]++;
    }
    int maxInd=0, maxVal=countArr[0];
    for(int i=1; i<countArr.size(); i++){
        if(maxVal < countArr[i]){
            maxInd = i;
            maxVal = countArr[i];
        }
    }
    if(maxVal>1){
        cout<<char(maxInd+minEle)<<" - "<<maxVal<<endl;
    } else {
        cout<<"No Duplicates Present"<<endl;
    }
}

int main(){
    int iter, len, res;
    char temp;
    cout<<"Enter number of cases: ";
    cin>>iter;
    for(int i=0; i<iter; i++){
        cout<<"Enter length of "<<i+1<<" case: ";
        cin>>len;
        cout<<"Enter elements: ";
        vector<char> arr;
        for(int j=0; j<len; j++){
            cin>>temp;
            arr.push_back(temp);
        }
        CheckDuplicate(arr);
    }
}

// DONE