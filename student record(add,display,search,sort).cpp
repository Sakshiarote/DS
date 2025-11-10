#include <iostream>
using namespace std;

struct Node{
    int r; string n; float m;
    Node* next;
};

Node* head=NULL;

void add(int r,string n,float m){
    head=new Node{r,n,m,head};
}

void display(){
    for(Node* t=head;t;t=t->next)
        cout<<t->r<<" "<<t->n<<" "<<t->m<<"\n";
}

void searchR(int r){
    for(Node* t=head;t;t=t->next)
        if(t->r==r) cout<<"Found";
}

void sortByMarks(){
    for(Node* i=head;i;i=i->next)
        for(Node* j=i->next;j;j=j->next)
            if(i->m > j->m)
                swap(i->m, j->m);
}

int main(){
    add(1,"A",88); add(2,"B",95);
    sortByMarks();
    display();
}