#include iostream
using namespace std;

class Stack {
private
    int top;
    int maxSize;
    int stackArray;
public
    Stack(int size) {
        maxSize = size;
        stackArray = new int[maxSize];
        top = -1;
    }

    ~Stack() {
        delete[] stackArray;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == maxSize - 1;
    }

    void push(int value) {
        if (!isFull()) {
            stackArray[++top] = value;
        } else {
            cout  Stack overflow!!n;
        }
    }

    void pop() {
        if (!isEmpty()) {
            --top;
        } else {
            cout  Stack underflow!!n;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return stackArray[top];
        } else {
            cout  Stack is empty!!n;
            return -1;   Indicate an error condition
        }
    }
};

int main() {
    Stack myStack(5);   Provide size when creating the stack

    cout  Is empty   myStack.isEmpty()  endl;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout  Is full   myStack.isFull()  endl;

    myStack.push(40);
    myStack.push(50);

    cout  Top Element   myStack.peek()  endl;   Change topElement to peek

    cout  Is full   myStack.isFull()  endl;
    myStack.pop();
    myStack.pop();

    cout  Top element after popping   myStack.peek()  endl;   Change topElement to peek
    myStack.push(60);
    
    return 0;
}