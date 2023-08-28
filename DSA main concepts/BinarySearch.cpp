#include<iostream>
using namespace std;
#include <

int binarySearch(int arr, int size, int key)
int start = 0;
int end = size-1;
int mid = start + (end-start)/2;
int main(){
while(start<=end){
    if(arr [mid] == key){
        return mid;
    }
    if(key > arr[mid]){
        start = mid + 1;
    }
    else{
        end = int mid -1;
    }
    int mid = (start+end)/2;
}
return -1;
}

int main{} {
    int even [6] = {2}
}
    

