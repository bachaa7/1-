#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct stack {
    double c;
    stack* next;
};

int pr(char a) {
    switch (a) {
    case '*':
    case '/':
        return 3;
    case '-':
    case '+':
        return 2;
    case '(':
        return 1;
    }
    return 0;
}

stack* ins(stack* p, double out) {
    stack* t = new stack;
    t->c = out;
    t->next = p;
    return t;
}

stack* outs(stack* p, double& inth) {
    stack* t = p;
    inth = p->c;
    p = p->next;
    delete t;
    return p;
}

double calculate(double a, double b, char oper) {
    switch (oper) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

int main() {
    stack* t, * op = nullptr;
    double a;
    char Ins[80], Outs[80];
    int k = 0, d = 0;
    cout << "Input: ";
    cin >> Ins;

    while (Ins[k] != '\0') {
        if (Ins[k] >= 'a' && Ins[k] <= 'z') {
            Outs[d++] = Ins[k];
        }
        if (Ins[k] == '(') {
            op = ins(op, Ins[k]);
        }
        if (Ins[k] == ')') {
            while (op->c != '(') {
                op = outs(op, a);
                if (!op) {
                    a = '\0';
                }
                Outs[d++] = a;
            }
            t = op;
            op = op->next;
            delete t;
        }
        if (Ins[k] == '+' || Ins[k] == '-' || Ins[k] == '/' || Ins[k] == '*') {
            while (op != nullptr && pr(op->c) >= pr(Ins[k])) {
                op = outs(op, a);
                Outs[d++] = a;
            }
            op = ins(op, Ins[k]);
        }
        k++;
    }

    while (op != nullptr) {
        op = outs(op, a);
        Outs[d++] = a;
    }
    Outs[d] = '\0';
    cout << "Polish Notation: " << Outs << endl;

    stack* evalStack = nullptr;
    int i = 0;
    while (Outs[i] != '\0') {
        if (Outs[i] >= 'a' && Outs[i] <= 'z') {
            double value;
            cout << "Enter value for " << Outs[i] << ": ";
            cin >> value;
            evalStack = ins(evalStack, value);
        }
        else if (Outs[i] == '+' || Outs[i] == '-' || Outs[i] == '*' || Outs[i] == '/') {
            double operand2 = evalStack->c;
            evalStack = outs(evalStack, a);
            double operand1 = evalStack->c;
            evalStack = outs(evalStack, a);
            double result = calculate(operand1, operand2, Outs[i]);
            evalStack = ins(evalStack, result);
        }
        i++;
    }

    double finalResult = evalStack->c;
    cout << "Result: " << finalResult << endl;

    return 0;
}