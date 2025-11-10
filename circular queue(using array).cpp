#include <iostream>
using namespace std;

int cq[10], front=-1, rear=-1, n=10;

bool full(){ return (front==0 && rear==n-1) || (rear+1==front); }
bool empty(){ return front==-1; }

void add(int x){
    if(full()) return;
    if(front==-1) front=0;
    rear = (rear+1)%n;
    cq[rear]=x;
}

void process(){
    if(empty()) return;
    cout<<"Processed: "<<cq[front]<<endl;
    if(front==rear) front=rear=-1;
    else front=(front+1)%n;
}

void display(){
    if(empty()) return;
    int i=front;
    while(i!=rear){
        cout<<cq[i]<<" ";
        i=(i+1)%n;
    } 
    cout<<cq[rear];
}

void cancel(int x){
    if(empty()) return;
    int t[10], k=0, i=front;
    while(true){
        if(cq[i]!=x) t[k++]=cq[i];
        if(i==rear) break;
        i=(i+1)%n;
    }
    front=0; 
    rear=k-1;
    for(i=0;i<k;i++) cq[i]=t[i];
}

int main(){
    add(1); add(2); add(3);
    display();
}