#include <iostream>
using namespace std;

struct Node{
    int id;
    Node* next;
};
Node *front=NULL, *rear=NULL;

void enqueue(int x){
    Node* n=new Node{x,NULL};
    if(!rear) front=rear=n;
    else{ rear->next=n; rear=n; }
}

void dequeue(){
    if(!front) return;
    Node* t=front;
    cout<<"Served: "<<t->id<<"\n";
    front=front->next;
    if(!front) rear=NULL;
    delete t;
}

void display(){
    for(Node* t=front;t;t=t->next)
        cout<<t->id<<" ";
}

int main(){
    enqueue(1); enqueue(2); display();
    dequeue(); display();
}