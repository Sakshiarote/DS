#include <iostream>
using namespace std;

int h[10];

int hashF(int k){ return k%10; }

void insertK(int k){
    int i=hashF(k);
    while(h[i]!=0) i=(i+1)%10;
    h[i]=k;
}

void searchK(int k){
    int i=hashF(k), c=0;
    while(h[i]!=k && h[i]!=0 && c<10){
        i=(i+1)%10; c++;
    }
    if(h[i]==k) cout<<"Found";
}

void display(){
    for(int i=0;i<10;i++) cout<<i<<":"<<h[i]<<"\n";
}

int main(){
    insertK(10); insertK(20); display();
}