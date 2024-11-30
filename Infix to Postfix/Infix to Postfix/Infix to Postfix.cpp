// Infix to Postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char token) {
    switch (token)
    {
    case '^':
        return 3; break;
    case '/':
    case '*':
        return 2; break;
    case '-':
    case '+':
        return 1; break;
    default:
        return 0;
       
    }
}

int main()
{
    string infix;
    char postfix[100];
    stack<char> S;
    int j = 0;
    char token;

    char next;
    char pop;
    getline(cin, infix);
    for (int i = 0; i < infix.length(); i++) {
        token = infix[i];

        switch (token) {
        case '(':
            S.push(token);
            break;
        case ')':
            while ((next = S.top()) != '(') {
                postfix[j++] = next;
                S.pop();
            }
            S.pop();

            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!S.empty() && precedence(pop = S.top()) >= precedence(token))
            {
                postfix[j++] = pop;
                S.pop();
            }
            S.push(token);
            break;
        default :
            postfix[j++] = token;
        }
    }
    while (!S.empty())
    {
        postfix[j++] = S.top();
        S.pop();
    }
    postfix[j] = '\0';

    for (int i = 0; i < strlen(postfix); i++) {
        cout << postfix[i] << " ";
    }
    return 0;
}