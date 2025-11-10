#include <iostream>
using namespace std;

struct Node{
    string fname;
    Node* next;
};
Node* top=NULL;

void push(string f){
    top=new Node{f,top};
}

void pop(){
    if(top){
        cout<<"Returning from: "<<top->fname<<"\n";
        Node* t=top; top=top->next; delete t;
    }
}

void display(){
    for(Node* t=top;t;t=t->next)
        cout<<t->fname<<" ";
}

int main(){
    push("A()");
    push("B()");
    display();
    pop();
    display();
}