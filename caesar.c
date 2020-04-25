//Author: Clovis Wanderley Bertholini Sobrinho
//Date: April, 23, 2020.
//pset2 --> caesar.c --> cs50 --> harvard
//a program called caesar that enables you to encrypt messages using Caesar’s
//cipher. At the time the user executes the program, they should decide, by
//providing a command-line argument, on what the key should be in the secret
//message they’ll provide at runtime. We shouldn’t necessarily assume that the
//user’s key is going to be a number; though you may assume that, if it is
//a number, it will be a positive integer.

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//functions' declarations
int validateArgs(int n, string s);
int cipherText(string s);
int findIntKey(string s);

//main
int main(int argsc, string argsv[])
{
    int result = validateArgs(argsc, argsv[1]);
    if (result == 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return cipherText(argsv[1]);
    }
}
//end main

//function validateArgs
int validateArgs(int n, string s)
{
    if (n != 2)
    {
        return 1;
    }
    else
    {
        for (int i = 0; i < strlen(s); i++)
        {
            if (s[i] < 48 || s[i] > 57)
            {
                return 1;
            }
        }
        return 0;

    }
}
//end validateArgs

//function cipherText
int cipherText(string s)
{
    printf("plaintext: ");
    string plain = GetString();
    string cipher = plain;
    int aux;
    int key = findIntKey(s);
    printf("%i-->key\n", key);
    //cipher text
    for (int c = 0; c < strlen(plain); c++)
    {
        //if each plain's elements is a letter [A-Z] --> 65-90 and  if actual elemnt
        //of s plus key is bigger than 90, we need a circular sum
        if (plain[c] > 64 && plain[c] < 91)
        {
            if (plain[c] + key > 90)
            {
                //aux receive the diference between the last letter on alphabet
                //and the actual letter of plain plus key value
                aux = key - (90 - plain[c]);
                while (aux > 26)
                {
                    aux -= 26;
                }
                cipher[c] = 64 + aux;
            }
            else
            {
                cipher[c] = plain[c] + key;
            }
        }
        //if is a letter [a-z] --> 97-122
        if (plain[c] > 96 && plain[c] < 123)
        {
            //if actual elemnt of s plus
            //key is bigger than 122, we need a circular sum
            if (plain[c] + key > 122)
            {
                //aux receive the diference between the last letter on alphabet
                //and the actual letter of plain plus key value
                aux = key - (122 - plain[c]);
                while (aux > 26)
                {
                    aux -= 26;
                }
                cipher[c] = 96 + aux;
            }
            else
            {
                cipher[c] = plain[c] + key;
            }
        }
    }
    printf("ciphertext: ");
    for (int c = 0; c < strlen(cipher); c++)
    {
        printf("%c", cipher[c]);
    }
    printf("\n");
    return 0;
}
//end cipherText

//function findIntKey
int findIntKey(string s)
{
    int n = 0;
    int p = 1;
    //shift string s into int key
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        switch (s[i])
        {
        case 48:
            n += 0 * p;
            break;
        case 49:
            n += 1 * p;
            break;
        case 50:
            n += 2 * p;
            break;
        case 51:
            n += 3 * p;
            break;
        case 52:
            n += 4 * p;
            break;
        case 53:
            n += 5 * p;
            break;
        case 54:
            n += 6 * p;
            break;
        case 55:
            n += 7 * p;
            break;
        case 56:
            n += 8 * p;
            break;
        case 57:
            n += 9 * p;
            break;
        default:
            break;
        }
        p *= 10;
    }
    return n;
}