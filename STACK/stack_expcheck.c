#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
char s[M];
int t = -1;
void push(char c)
{
    s[++t] = c;
}
char pop()
{
    return s[t--];
}
int isEmpty()
{
    return t == -1;
}
int isValidParentheses(char *e)
{
    for (int i = 0; e[i]; i++)
    {
        if (e[i] == '(')
            push(e[i]);
        else if (e[i] == ')')
        {
            if (isEmpty())
                return 0;
            pop();
        }
    }
    return isEmpty();
}
int isValidBrackets(char *e)
{
    for (int i = 0; e[i]; i++)
    {
        if (e[i] == '{' || e[i] == '[')
            push(e[i]);
        else if (e[i] == '}' || e[i] == ']')
        {
            if (isEmpty())
                return 0;
            char top = pop();
            if ((e[i] == '}' && top != '{') || (e[i] == ']' && top != '['))
                return 0;
        }
    }
    return isEmpty();
}
int main()
{
    char expr1[] = "(a + b) * (c - d)";
    printf("Parentheses Valid: %d\n", isValidParentheses(expr1));

    char expr2[] = "{a + [b * (c + d)]}";
    printf("Brackets Valid: %d\n", isValidBrackets(expr2));

    return 0;
}
