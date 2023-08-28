#include<iostream>
using namespace std;
  
int main(){

    //creating a 2D Array
    int arr[3][3];

    //taking input in 2D Array
    cout<<"Enter the elements of the array";
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    //showing output in 2D Array
    cout<<"the array is"<<endl;
     for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<< endl;
    }

return 0;
}
