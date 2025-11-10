#include <iostream>
using namespace std;

struct Node{
    int e;
    Node* next;
};
Node* rear=NULL;

void add(int x){
    Node* n=new Node{x,NULL};
    if(!rear){
        rear=n; n->next=n;
    } else {
        n->next=rear->next;
        rear->next=n;
        rear=n;
    }
}

void process(){
    if(!rear) return;
    Node* f=rear->next;
    cout<<"Processed: "<<f->e<<"\n";
    if(f==rear) rear=NULL;
    else rear->next=f->next;
    delete f;
}

void display(){
    if(!rear) return;
    Node* t=rear->next;
    do{
        cout<<t->e<<" ";
        t=t->next;
    }while(t!=rear->next);
}

void cancel(int x){
    if(!rear) return;
    Node *cur=rear->next, *prev=rear;
    do{
        if(cur->e==x){
            if(cur==rear && cur==rear->next) rear=NULL;
            else{
                prev->next=cur->next;
                if(cur==rear) rear=prev;
            }
            delete cur; break;
        }
        prev=cur; cur=cur->next;
    }while(cur!=rear->next);
}

int main(){
    add(1); add(2); add(3);
    display();
}