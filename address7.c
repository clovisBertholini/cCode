// Prints a string's address as well the addresses of its chars

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string s = "CLOVIS";
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
    printf("%p\n", &s[4]);
    printf("%p\n", &s[5]);
    printf("%p\n", &s[6]);
}