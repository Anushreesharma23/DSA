#include<iostream>
using namespace std;

void print(int *arr, int s, int e){
       for(int i = 0; i<=e; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

bool binarySearch(int *arr, int s, int e, int k){
    print(arr,s,e);
 
    if(s>e){
        cout<<"nopes"<<endl;
        return false;
    }
    int mid = s + (e-s) / 2;
    cout<<"the value of mid is"<<" "<<arr[mid]<<endl;

    if(arr[mid] == k){
        cout<<"yesh"<<endl;
        return true;
    }
    if(arr[mid]>k){
        return binarySearch(arr, s, mid-1, k);
    }

    else{
        return binarySearch(arr, mid+1, e, k);
    }
}

int main(){
    int arr[5] = {1,2,4,6,7};
    int size = 5;
    int key = 7;
    cout<<"the key is present or not"<<endl<<binarySearch(arr, 0, 5, key)<<endl;
    return 0;
}