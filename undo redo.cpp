#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<string> undo, redo;
    string doc = "", change;

    int ch;
    do {
        cout << "\n1.Make Change  2.Undo  3.Redo  4.Display  5.Exit\n";
        cin >> ch;

        if (ch == 1) {
            cout << "Enter change: ";
            cin >> change;
            undo.push(doc);
            doc = change;
            while(!redo.empty()) redo.pop();

        } else if (ch == 2 && !undo.empty()) {
            redo.push(doc);
            doc = undo.top();
            undo.pop();

        } else if (ch == 3 && !redo.empty()) {
            undo.push(doc);
            doc = redo.top();
            redo.pop();

        } else if (ch == 4) {
            cout << "Document: " << doc << endl;
        }

    } while (ch != 5);
}