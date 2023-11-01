#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int>q;
    q.push(23);
    q.push(07);
    q.push(27);
    cout<<"the size of the queue is "<<q.size()<<endl;
    q.pop();
    cout<<"the size of the queue is "<<q.size()<<endl;

    if(q.empty()){
        cout<<"the queue is empty"<<endl;
    }
    else{
        cout<<"the queue is not empty"<<endl;
    }

    return 0;
}