#include <stdio.h>
#include <stdlib.h>
#define M 100
char *decToBin(int n)
{
    char *b = (char *)malloc(M);
    int i = 0;
    while (n > 0)
    {
        b[i++] = (n % 2) + '0';
        n /= 2;
    }
    b[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        char temp = b[j];
        b[j] = b[i - 1 - j];
        b[i - 1 - j] = temp;
    }
    return b;
}
char *decToOct(int n)
{
    char *o = (char *)malloc(M);
    int i = 0;
    while (n > 0)
    {
        o[i++] = (n % 8) + '0';
        n /= 8;
    }
    o[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        char temp = o[j];
        o[j] = o[i - 1 - j];
        o[i - 1 - j] = temp;
    }
    return o;
}
char *decToHex(int n)
{
    char *h = (char *)malloc(M);
    int i = 0;
    while (n > 0)
    {
        int r = n % 16;
        h[i++] = (r < 10) ? (r + '0') : (r - 10 + 'A');
        n /= 16;
    }
    h[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        char temp = h[j];
        h[j] = h[i - 1 - j];
        h[i - 1 - j] = temp;
    }
    return h;
}
char *decToBase(int n, int base)
{
    char *r = (char *)malloc(M);
    int i = 0;
    while (n > 0)
    {
        int mod = n % base;
        r[i++] = (mod < 10) ? (mod + '0') : (mod - 10 + 'A');
        n /= base;
    }
    r[i] = '\0';
    for (int j = 0; j < i / 2; j++)
    {
        char temp = r[j];
        r[j] = r[i - 1 - j];
        r[i - 1 - j] = temp;
    }
    return r;
}
int main()
{
    int n = 42;
    printf("Decimal to Binary: %s\n", decToBin(n));
    printf("Decimal to Octal: %s\n", decToOct(n));
    printf("Decimal to Hexadecimal: %s\n", decToHex(n));
    printf("Decimal to Base 5: %s\n", decToBase(n, 5));
    return 0;
}
