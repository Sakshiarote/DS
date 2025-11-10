#include <iostream>
using namespace std;

struct Node {
    int r; string n; float m;
    Node* next;
};

Node* head = NULL;

void add(int r,string n,float m){
    Node* p=new Node{r,n,m,head};
    head=p;
}

void display(){
    for(Node* t=head;t;t=t->next)
        cout<<t->r<<" "<<t->n<<" "<<t->m<<"\n";
}

void removeR(int r){
    Node *t=head,*p=NULL;
    while(t && t->r!=r){ p=t; t=t->next; }
    if(!t) return;
    if(!p) head=t->next; else p->next=t->next;
    delete t;
}

void update(int r,float m){
    for(Node* t=head;t;t=t->next)
        if(t->r==r) t->m=m;
}

int main(){
    add(1,"A",90); add(2,"B",80);
    display();
    update(1,95);
    removeR(2);
    display();
}