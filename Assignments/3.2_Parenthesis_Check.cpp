#include <bits/stdc++.h>
using namespace std;

typedef struct stack_c
{
    int size;
    int top;
    char *arr;
} ss;

int isEmpty(ss *ptr)
{
    return ptr->top == -1;
}

void push_c(ss *ptr, char data)
{
    ptr->top++;
    ptr->arr[ptr->top] = data;
}

char pop_c(ss *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    char value = ptr->arr[ptr->top];
    ptr->top--;
    return value;
}

int main()
{
    cout << "Enter your string: \n";
    string s;
    getline(cin, s); // Use getline to read the entire input line

    int length = s.length();

    ss *stck = new ss;
    stck->size = length;
    stck->top = -1;
    stck->arr = new char[length];

    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            push_c(stck, s[i]);
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            char topElement = isEmpty(stck) ? '\0' : pop_c(stck);

            if ((s[i] == ')' && topElement != '(') ||
                (s[i] == '}' && topElement != '{') ||
                (s[i] == ']' && topElement != '['))
            {
                cout << "Parenthesis unmatched: Closing parenthesis without a matching opening parenthesis." << endl;
                delete[] stck->arr;
                delete stck;
                return 0;
            }
        }
    }

    if (!isEmpty(stck))
    {
        cout << "Parenthesis unmatched: Opening parenthesis without a matching closing parenthesis." << endl;
    }
    else
    {
        cout << "All parentheses are well-paired!" << endl;
    }

    delete[] stck->arr;
    delete stck;
    return 0;
}
