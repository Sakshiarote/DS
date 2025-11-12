#include <iostream>
#include <cstring>
using namespace std;

struct Node { char d; Node *l,*r; };

Node* build(const char* p){
    Node* s[30]; int t=-1;
    for(int i=strlen(p)-1;i>=0;i--){
        Node* n=new Node{p[i],0,0};
        if(isalpha(p[i])) s[++t]=n;
        else { n->l=s[t--]; n->r=s[t--]; s[++t]=n; }
    }
    return s[t];
}

void inorder(Node* r){ if(!r) return; inorder(r->l); cout<<r->d; inorder(r->r); }

void postNR(Node* r){
    if(!r) return;
    Node *s1[30],*s2[30]; int t1=-1,t2=-1;
    s1[++t1]=r;
    while(t1>=0){
        Node* c=s1[t1--];
        s2[++t2]=c;
        if(c->l) s1[++t1]=c->l;
        if(c->r) s1[++t1]=c->r;
    }
    cout<<"Postorder: ";
    while(t2>=0) cout<<s2[t2--]->d;
}

void delTree(Node* r){
    if(!r) return;
    delTree(r->l);
    delTree(r->r);
    cout<<"\nDeleting: "<<r->d;
    delete r;
}

int main(){
    char pre[30];
    cout<<"Enter prefix: ";
    cin>>pre;
    Node* t=build(pre);
    cout<<"Inorder: "; inorder(t);
    cout<<endl; postNR(t);
    delTree(t);
}
