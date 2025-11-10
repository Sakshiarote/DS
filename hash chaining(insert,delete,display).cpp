#include <iostream>
#include <list>
using namespace std;

list<int> h[10];
int hashF(int k){ return k%10; }

void insertK(int k){ h[hashF(k)].push_back(k); }

void deleteK(int k){ h[hashF(k)].remove(k); }

void display(){
    for(int i=0;i<10;i++){
        cout<<i<<": ";
        for(int x:h[i]) cout<<x<<" ";
        cout<<"\n";
    }
}

int main(){
    insertK(11); insertK(21);
    deleteK(11);
    display();
}