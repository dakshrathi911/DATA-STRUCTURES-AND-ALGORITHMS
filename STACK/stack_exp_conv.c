#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
char peek()
{
    return s[t];
}
int isEmpty()
{
    return t == -1;
}
int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}
char *infixToPostfix(char *e)
{
    char *r = (char *)malloc(strlen(e) + 1);
    int k = 0;
    for (int i = 0; e[i]; i++)
    {
        if (isalnum(e[i]))
            r[k++] = e[i];
        else if (e[i] == '(')
            push(e[i]);
        else if (e[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                r[k++] = pop();
            pop();
        }
        else
        {
            while (!isEmpty() && prec(peek()) >= prec(e[i]))
                r[k++] = pop();
            push(e[i]);
        }
    }
    while (!isEmpty())
        r[k++] = pop();
    r[k] = '\0';
    return r;
}
char *infixToPrefix(char *e)
{
    int len = strlen(e);
    char *r = (char *)malloc(len + 1);
    for (int i = 0; i < len; i++)
        r[i] = e[len - 1 - i];
    r[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        if (r[i] == '(')
            r[i] = ')';
        else if (r[i] == ')')
            r[i] = '(';
    }
    char *p = infixToPostfix(r);
    free(r);
    char *res = (char *)malloc(strlen(p) + 1);
    for (int i = 0; p[i]; i++)
        res[i] = p[strlen(p) - 1 - i];
    res[strlen(p)] = '\0';
    free(p);
    return res;
}
int main()
{
    char infixExp[] = "((A+B)*C-(D-E^F)^G)";
    char *postfix = infixToPostfix(infixExp);
    printf("Infix to Postfix: %s\n", postfix);
    free(postfix);

    char *prefix = infixToPrefix(infixExp);
    printf("Infix to Prefix: %s\n", prefix);
    free(prefix);

    return 0;
}
