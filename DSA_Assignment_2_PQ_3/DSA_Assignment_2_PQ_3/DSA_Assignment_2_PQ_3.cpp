#include <iostream>
#include <string>

using namespace std;

// Custom stack implementation
class Stack {
private:
    char* arr;
    int capacity;
    int top;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }
    void push(char c);
    char pop();
    char peek();

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

};
    void Stack::push(char c) {
        if (isFull()) {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = c;
    }

    char Stack::pop() {
        if (isEmpty()) {
            cout << "Stack underflow!\n";
            return '\0';
        }
        return arr[top--];
    }

    char Stack::peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return '\0';
        }
        return arr[top];
    }

   



int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1; 
}


string infixToPostfix(const string& infix) {

    string postfix;
    Stack s(infix.length());

    for (char ch : infix) {
        // If character is an operand, add it to the postfix expression
        if (isalnum(ch))
            postfix += ch;
        // If character is an opening parenthesis, push it onto the stack
        else if (ch == '(')
            s.push(ch);
        // If character is a closing parenthesis, pop and add operators from stack to postfix until opening parenthesis is encountered
        else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop(); // Discard the '('
        }
        // If character is an operator
        else {
            // Pop and add operators from stack to postfix if they have higher precedence than the current operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
                postfix += s.pop();
            s.push(ch); // Push the current operator onto the stack
        }
    }

    // Pop and add remaining operators from stack to postfix
    while (!s.isEmpty())
        postfix += s.pop();

    return postfix;
}

int main() {
    string expressions[] = { "a+b", "(a+b)*c", "a*(b+c)", "a/b+c/d", "(a+b)*(c+d)", "((a+b)*c)-d" };
    int numExpressions = sizeof(expressions) / sizeof(expressions[0]);

    for (int i = 0; i < numExpressions; ++i) {
        cout << "Infix: " << expressions[i] << endl;
        cout << "Postfix: " << infixToPostfix(expressions[i]) << endl;
    }

    return 0;
}
