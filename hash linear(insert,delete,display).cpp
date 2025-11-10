#include <iostream>
using namespace std;

int h[10];

int hashF(int k){ return k%10; }

void insertK(int k){
    int i=hashF(k);
    while(h[i]!=0) i=(i+1)%10;
    h[i]=k;
}

void deleteK(int k){
    int i=hashF(k);
    while(h[i]!=k && h[i]!=0) i=(i+1)%10;
    if(h[i]==k) h[i]=0;
}

void display(){
    for(int i=0;i<10;i++)
        cout<<i<<":"<<h[i]<<"\n";
}

int main(){
    insertK(10); insertK(22);
    deleteK(10);
    display();
}