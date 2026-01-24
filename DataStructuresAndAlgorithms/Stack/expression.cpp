#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to get precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Function to check if character is operator
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Infix to Postfix
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;

for (int i = 0; i < infix.length(); ++i) {
    char ch = infix[i];
        if (isalnum(ch)) {
            postfix += ch;
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop(); // remove '('
        }
        else if (isOperator(ch)) {
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Step 2: Swap '(' with ')' and vice versa
    for (int i = 0; i < infix.length(); ++i) {
        if (infix[i] == '(') infix[i] = ')';
        else if(infix[i] == ')') infix[i] = '(';
    }

    // Step 3: Get postfix of modified expression
    string revPostfix = infixToPostfix(infix);

    // Step 4: Reverse postfix to get prefix
    reverse(revPostfix.begin(), revPostfix.end());
    return revPostfix;
}


// Main function
int main() {
    string infix, postfix, prefix;

    cout << "Enter infix expression(Only without spaces): ";
    cin >> infix;

    postfix = infixToPostfix(infix);
    prefix = infixToPrefix(infix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix : " << prefix << endl;

    return 0;
}