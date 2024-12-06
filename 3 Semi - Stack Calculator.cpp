#include <iostream> // cin cout
#include <stack> // stack lib - stack data struct
#include <string> // string lib - use string class
#include <cctype> // for isdigit()
using namespace std; // bye std::

int performOperation(int a, int b, char op) { 
    switch (op) {
        case '+': return a + b; // if op + then sum of a and b
        case '-': return a - b; // if op - then diff of a and b
        case '*': return a * b; // if op * then product of a and b
        case '/': return a / b; // if op / then quotient of a and b
    }
    return 0; // if op is none of the expected, return 0
}

// takes 2 int and an operator and performs the specified operation then returns result

int precedence(char op) { // to determine precedence of given operator (PEMDAS)
    if (op == '+' || op == '-') return 1; // returns 1 for add & sub (lower precedence)
    if (op == '*' || op == '/') return 2; // returns 2 for mul and div (higher precedence)
    return 0; // invalid operators or parentheses
}

void evaluateTop(stack<int>& values, stack<char>& ops) { // to eval top operation
    int b = values.top(); values.pop();
    int a = values.top(); values.pop();
    char op = ops.top(); ops.pop();
    values.push(performOperation(a, b, op));
}
// retrieves the top two values and top operator, pops them from their respective stacks and then pushes the result of the operation back to values stack

int calculate(string expression) {
    stack<int> values; // stack to store integers
    stack<char> ops;   // stack to store operators

    for (int i = 0; i < expression.length(); i++) { // iterates over each char in the input string
        if (isdigit(expression[i])) { // checks if current char is a digit
            int val = 0;
            while (i < expression.length() && isdigit(expression[i])) {
                val = val * 10 + (expression[i] - '0');
                i++;
            }
            values.push(val);
            i--; // adjust because the loop will also increment i
        } else if (expression[i] == '(') { // if ( then push to ops stack
            ops.push(expression[i]);
        } else if (expression[i] == ')') { // same here
            // Solve the entire bracket
            while (!ops.empty() && ops.top() != '(') {
                evaluateTop(values, ops);
            }
            ops.pop(); // Remove '(' 
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            // checks the precedence / order / PEMDAS
            while (!ops.empty() && precedence(ops.top()) >= precedence(expression[i])) {
                evaluateTop(values, ops); 
            }
            ops.push(expression[i]); 
        }
    }

    // Evaluate the remaining operators in the stack
    while (!ops.empty()) {
        evaluateTop(values, ops);// check until its all empty
    }

    return values.top(); //result will be at the top of the value stack
}

int main() {
    string expression;
    cout << "Enter an expression: "; // user input here 
    cin >> expression;
    cout << "Result: " << calculate(expression) << endl; //result from function here
    return 0;
}


/* my sources:

https://youtu.be/_EvA-F9EPVo?si=SGtsBL1uTeKzF3ZA
https://youtu.be/TKh2E9U8Z30?si=Jnzq9DTQ6wu5A6k3
https://youtu.be/CypWbdyQfLQ?si=4QkWCtHsfu47L5KZ

*/