#include <iostream>
using namespace std;

char stack[20];
int top = -1;
string stackOutput = "";

void push(char val) {
    stack[++top] = val;
    stackOutput += val;
}

char pop() {
    stackOutput.erase(stackOutput.size() - 1, 1);
    char val = stack[top--];
    return val;
}

char peek() {
    return stack[top];
}

int checkLevel(char operation) {
    if (operation == '(' || operation == ')') {
        return 0;
    } else if (operation == '^') {
        return 3;
    } else if (operation == '*' || operation == '/') {
        return 2;
    } else if (operation == '+' || operation == '-') {
        return 1;
    }
    return -1;
}

void convertToPostfix(string input) {
    string output = "";

    cout << "| Input | Stack | Output |" << endl;
    cout << "------------------------" << endl;

    for (int i = 0; i < input.length(); i++) {

        cout << "| " << input[i] << "     | " << stackOutput << "    | " << output << "    |" << endl;
        cout << "------------------------" << endl;

       
        if (isdigit(input[i])) {
            output += input[i];
        }
       
        else if (input[i] == '(') {
            push(input[i]);
        }
       
        else if (input[i] == ')') {
            while (top >= 0 && peek() != '(') {
                output += pop();
            }
            pop();
        }
       
        else {
            while (top >= 0 && checkLevel(peek()) >= checkLevel(input[i])) {
                output += pop();
            }
            push(input[i]);
        }
    }

   
    while (top >= 0) {
        output += pop();
    }

    cout << "Postfix expression: " << output << endl;
}

int main() {
    string input = "1+2*(3^2-1)";
    convertToPostfix(input);

    return 0;
}

