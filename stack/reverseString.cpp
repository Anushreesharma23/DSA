//reverse a string using stack
#include<iostream>
#include<stack>
using namespace std;

int main(){
    string str="anuna";
    stack<char>s;
    for(int i =0; i<str.size();i++){
        char ch=str[i];
        s.push(ch);
    }
    string ans ="";
    while(s.size()!=NULL){
        char ch=s.top();
        ans.push_back(ch);
        s.pop();
    }
    cout<<"answer is:"<<ans<<endl;
    return 0;
}