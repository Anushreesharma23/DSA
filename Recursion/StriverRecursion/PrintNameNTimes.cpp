#include <iostream>
using namespace std;

void naming(int i, int n){
    if(i>n){
        return;
    }
    cout<<"Anu"<<endl;
    naming(i+1, n);
}


int main(){
    int n;
    cin>>n;
    naming(1,n);
}