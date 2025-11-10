#include <iostream>
#include <list>
using namespace std;

list<int> h[10];

int hashF(int k){ return k%10; }

void insertK(int k){ h[hashF(k)].push_back(k); }

void searchK(int k){
    for(int x:h[hashF(k)]) 
        if(x==k) cout<<"Found";
}

void display(){
    for(int i=0;i<10;i++){
        cout<<i<<": ";
        for(int x:h[i]) cout<<x<<" ";
        cout<<"\n";
    }
}

int main(){
    insertK(10); insertK(21); display();
}