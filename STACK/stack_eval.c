#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define M 100

int s[M];
int t = -1;

void p(int v)
{
    if (t < M - 1)
    { // Check for stack overflow
        s[++t] = v;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int q()
{
    if (t >= 0)
    { // Check for stack underflow
        return s[t--];
    }
    else
    {
        printf("Stack Underflow\n");
        return 0; // or handle error appropriately
    }
}

int evalPostfix(char *e)
{
    for (int i = 0; e[i]; i++)
    {
        if (isdigit(e[i]))
        {
            p(e[i] - '0'); // Single digit handling
        }
        else
        {
            int v2 = q();
            int v1 = q();
            switch (e[i])
            {
            case '+':
                p(v1 + v2);
                break;
            case '-':
                p(v1 - v2);
                break;
            case '*':
                p(v1 * v2);
                break;
            case '/':
                if (v2 != 0)
                {
                    p(v1 / v2);
                }
                else
                {
                    printf("Division by zero\n");
                    return 0; // or handle error appropriately
                }
                break;
            case '^':
                p((int)pow(v1, v2)); // Casting to int
                break;
            }
        }
    }
    return q();
}

int evalPrefix(char *e)
{
    for (int i = strlen(e) - 1; i >= 0; i--)
    {
        if (isdigit(e[i]))
        {
            p(e[i] - '0'); // Single digit handling
        }
        else
        {
            int v1 = q();
            int v2 = q();
            switch (e[i])
            {
            case '+':
                p(v1 + v2);
                break;
            case '-':
                p(v1 - v2);
                break;
            case '*':
                p(v1 * v2);
                break;
            case '/':
                if (v2 != 0)
                {
                    p(v1 / v2);
                }
                else
                {
                    printf("Division by zero\n");
                    return 0; // or handle error appropriately
                }
                break;
            case '^':
                p((int)pow(v1, v2)); // Casting to int
                break;
            }
        }
    }
    return q();
}

int main()
{
    char pe[] = "53+82-*"; // Example postfix expression
    printf("Postfix: %d\n", evalPostfix(pe));

    char pre[] = "-+*2345"; // Example prefix expression
    printf("Prefix: %d\n", evalPrefix(pre));

    return 0;
}
