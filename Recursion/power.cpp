#include<iostream>
using namespace std;

int power(int a, int b){
    //base case
    if(b==0)
        return 1;
    if(b==1)
        return a;

    //resurcive call
    int ans = power(a,b/2);

    //processing
    if(b%2==0){
        return ans*ans;
    }
    else2{
        return a*ans*ans;
    }
}
int main(){
    int a,b;
    cout<<"enter the numbers"<<endl;
    cin>>a>>b;
    cout<<endl;
    int ans = power(a,b);
    cout<<"Answer is"<<ans<<endl;
return 0;
}