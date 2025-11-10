#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<string> q;
    int ch; string e;

    do {
        cout << "\n1.Add  2.Process  3.Display  4.Cancel  5.Exit\n";
        cin >> ch;

        if (ch == 1) { cin >> e; q.push(e); }

        else if (ch == 2 && !q.empty()) { 
            cout << "Processed: " << q.front(); 
            q.pop(); 
        }

        else if (ch == 3) {
            queue<string> t = q;
            while(!t.empty()){ cout << t.front() << " "; t.pop(); }
        }

        else if (ch == 4) {
            cin >> e;
            queue<string> t;
            while(!q.empty()){
                if(q.front()!=e) t.push(q.front());
                q.pop();
            }
            q = t;
        }

    } while(ch!=5);
}