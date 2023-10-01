#include<iostream>
using namespace std;
int main(){
    int a = 6;
    int b = 4;
    cout<<"a&b:"<< (a&b) <<endl;
    cout<<"a|b:"<<(a|b)<<endl;
    cout<<"~a:"<<~a<<endl;
    cout<<"a^b:"<<(a^b)<<endl;
    cout<< (17>>1)<<endl;
    cout<< (17>>2) <<endl;
    cout<<"*************"<<endl;
    int i = 7;

    cout<< (++i) <<endl;
    // 8 
    cout<< (i++) <<endl;
    // 8 , i = 9
    cout<< (i--) <<endl;
    //9 , i = 8 
    cout<< (--i) <<endl; 
    // 7, i =7
}