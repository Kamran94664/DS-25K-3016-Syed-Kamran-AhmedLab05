#include <iostream>
#include <stack>
#include <string>
using namespace std;

class TextEditor {
    stack<string> undoStack;
    stack<string> redoStack;

public:
    void type(string word) {
        undoStack.push(word);

        // New typing removes the old redo history
        while (!redoStack.empty())
            redoStack.pop();

        cout << "Typed: " << word << endl;
        print();
    }

    void undo() {
        if (undoStack.empty()) {
            cout << "Nothing to undo!\n";
            return;
        }

        redoStack.push(undoStack.top());
        undoStack.pop();

        cout << "Undo: ";
        print();
    }

    void redo() {
        if (redoStack.empty()) {
            cout << "Nothing to redo!\n";
            return;
        }

        undoStack.push(redoStack.top());
        redoStack.pop();

        cout << "Redo: ";
        print();
    }

    void print() {
        stack<string> temp = undoStack;
        stack<string> reversed;

        while (!temp.empty()) {
            reversed.push(temp.top());
            temp.pop();
        }

        cout << "Document: ";

        while (!reversed.empty()) {
            cout << reversed.top() << " ";
            reversed.pop();
        }

        cout << endl;
    }
};

int main() {
    TextEditor editor;

    editor.type("Hello");
    editor.type("World");

    editor.undo();
    editor.redo();
    editor.undo();

    editor.type("There");
    editor.redo();

    return 0;
}
