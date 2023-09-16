#include<iostream>
using namespace std;
    int main(){
        int arr[5] = {1,2,3,4,5};
        char ch[6] = "abcde";

        cout<< arr<< endl;
        //it gives us the stringgg
        cout<< ch<< endl;

        char *c = &ch[1];
        cout<< c <<endl;
        cout<< *c <<endl;

        char temp = 'z';
        char *p = &temp;
        //it would give astring till it finds a null value
        cout<<p<<endl;
        cout<<*p<<endl;



    return 0;
}