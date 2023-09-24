#include<iostream>
using namespace std;

bool checkPalindrome(string str, int i, int j){
    //base case
    if(i>j){
        return true;
    }
    //processing
    if(str[i] != str[j]){
        return false;
    }
    //recursive call
    else{
        return checkPalindrome(str, i+1, j-1);
    }
}

int main(){
    string name = "AnuunA ";
    cout<<endl;

    bool isPalindrome = checkPalindrome(name, 0, name.length()-1);

    if(isPalindrome){
        cout<<"The string is a palindrome"<<endl;
    }
    else{
        cout<<"The string is not a palindrome"<<endl;
    }
    return 0;
}