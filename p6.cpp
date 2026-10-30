#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int val)
    {
        if (top >= 99)
        {
            cout << "Stack Overflow!";
            exit(1);
        }

        arr[++top] = val;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Invalid postfix expression!";
            exit(1);
        }

        return arr[top--];
    }
};

int evaluate(char x, int op1, int op2)
{
    switch (x)
    {
        case '+':
            return op1 + op2;

        case '-':
            return op1 - op2;

        case '*':
            return op1 * op2;

        case '/':
            if (op2 == 0)
            {
                cout << "Error: Division by zero!";
                exit(1);
            }
            return op1 / op2;

        case '%':
            if (op2 == 0)
            {
                cout << "Error: Modulo by zero!";
                exit(1);
            }
            return op1 % op2;

        case '$':
            return static_cast<int>(pow(op1, op2));

        default:
            cout << "Invalid operator: " << x;
            exit(1);
    }
}

int main()
{
    Stack s;
    char x;
    int op1, op2, val;

    cout << "Enter postfix expression: ";

    while (cin.get(x) && x != '\n')
    {
        if (isdigit(static_cast<unsigned char>(x)))
        {
            s.push(x - '0');
        }
        else if (x == ' ')
        {
            continue;
        }
        else
        {
            op2 = s.pop();
            op1 = s.pop();

            val = evaluate(x, op1, op2);

            s.push(val);
        }
    }

    val = s.pop();

    cout << "Answer = " << val << endl;

    return 0;
}
PS D:\yashbhushan lokhande> g++ p6.cpp 
PS D:\yashbhushan lokhande> .\p6       
Enter postfix expression: 623+-382/+*2$3+
Answer = 52
PS D:\yashbhushan lokhande> 