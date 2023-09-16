#include<iostream>
using namespace std;
  int main(){
    /*
    int a[20]={1,2,3,5};
    cout<<&a[0]<<endl;
    cout<<&a<<endl;
    cout<<a<<endl;

    int *ptr=&a[0];
    cout<<ptr<<endl;
    cout<<*ptr<<endl;
    cout<<&ptr<<endl;

    cout<<"________________"<<endl;
    int temp[10]={1,2};
    cout<<sizeof(temp)<<endl;
    cout<<sizeof(&temp)<<endl;
    cout<<&temp<<endl;
    cout<<&(*temp)<<endl;

    int *p = &temp[1];
    cout<<sizeof(p)<<endl;
    cout<<sizeof(*p)<<endl;
    cout<<sizeof(&p)<<endl;
    */

    int arr[10];
    // arr = arr + 1;
    cout<<arr<<endl;
    int *ptr = &arr[0];
    ptr = ptr+1;
    cout<<ptr<<endl;
    ptr = ptr+2;
    cout<<ptr<<endl;
    return 0;
  }
