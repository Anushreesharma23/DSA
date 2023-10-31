#include<iostream>
#include<stack>
using namespace std;

class Stack{
    //properties
    public:
    int *arr;
    int size;
    int top;

    //behavior
    Stack(int size){
        this->size = size;
        arr = new int [size];
        top = -1;
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    void pop(){
        if(top<0){
            cout<<"stack underflow"<<endl;
        }
        else if(top>=0){
            top--;
        }
    }
    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }

};
int main(){
    Stack st(3  );
    st.push(22);
    st.push(3);
    st.push(70);
    st.push(30);
    cout<<st.peek()<<endl; 
    st.pop();
    cout<<st.peek()<<endl; 
    st.pop();
    cout<<st.peek()<<endl; 
    st.pop();
    cout<<st.peek()<<endl; 
    
    if(st.isEmpty()){
        cout<<"stack is empty anu"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }
    return 0;
}
