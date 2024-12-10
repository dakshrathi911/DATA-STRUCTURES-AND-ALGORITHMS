#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10
struct stack
{
    char item[STACKSIZE];
    int Top;
};
void Initialize(struct stack *s)
{
    s->Top = -1;
}
void Push(struct stack *s, char x)
{
    if (s->Top == STACKSIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->Top = s->Top + 1;
    s->item[s->Top] = x;
}
char Pop(struct stack *s)
{
    char x;
    if (s->Top == -1)
    {
        printf("Stack Underflow");
        exit(1);
    }
    x = s->item[s->Top];
    s->Top = s->Top - 1;
    return x;
}
char StackTop(struct stack *s)
{
    char x;
    x = s->item[s->Top];
    return x;
}
int Empty(struct stack s)
{
    if (s.Top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    char str[10], ans[10], x;
    int i = 0, j = 0;
    struct stack s;
    Initialize(&s);
    printf("Enter a string: ");
    scanf("%s", str);
    while (str[i] != '\0')
    {
        Push(&s, str[i]);
        i++;
    }
    while (!Empty(s))
    {
        x = Pop(&s);
        ans[j] = x;
        j++;
    }
    ans[j] = '\0';
    printf("Reversed String is:=> %s", ans);
    return 0;
}