#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char d;
    Node *l, *r;
};

Node* st[30]; 
int top = -1;
void push(Node* n){ st[++top] = n; }
Node* pop(){ return st[top--]; }

Node* makeTree(char p[]) {
    for (int i = strlen(p)-1; i >= 0; i--) {
        Node* n = new Node{p[i], NULL, NULL};
        if (isalpha(p[i])) push(n);
        else {
            n->l = pop();
            n->r = pop();
            push(n);
        }
    }
    return pop();
}

void post(Node* r) {
    if(!r) return;
    Node* s1[30]; int t1=-1;
    Node* s2[30]; int t2=-1;

    s1[++t1]=r;
    while(t1!=-1){
        Node* x=s1[t1--];
        s2[++t2]=x;
        if(x->l) s1[++t1]=x->l;
        if(x->r) s1[++t1]=x->r;
    }
    while(t2!=-1) cout << s2[t2--]->d;
}

void del(Node* r){
    if(!r) return;
    del(r->l);
    del(r->r);
    cout << "\nDeleting: " << r->d;
    delete r;
}

int main() {
    char p[20];
    cin >> p;
    Node* root = makeTree(p);
    post(root);
    del(root);
}