//Author: Clovis Wanderley Bertholini Sobrinho
//Date: April, 25, 2020.
//Problem Set 2 --> cs50 --> substitution.c
//that enables you to encrypt messages using a substitution cipher. 
//At the time the user executes the program, they should decide, 
//by providing a command-line argument, on what the key should 
//be in the secret message they’ll provide at runtime.

//header's files
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <cs50.h>
//end header's files

//functions declarations
int validateArgs(int n, string v[]);
void cipherText(string s);
//end declarations

//main code
int main(int argc, string argv[])
{
	int isValid = validateArgs(argc, argv);
	if (isValid == 0)
	{
		cipherText(argv[1]);
		return 0;
	}
	else
	{
		return 1;
	}
}
//end main code

//validateArgs implementation
int validateArgs(int n, string v[])
{
	if (n != 2)
	{
		printf("Usage: ./substitution key");
		return 1;
	}
	else
	{
		if (strlen(v[1]) != 26)
		{
			printf("Key must contain 26 characters.");
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
//end validateArgs

//cipherText implementation
void cipherText(string s)
{
	//take a plain text
	printf("plaintext: ");
	string plain = GetString();
	
	//creating a cipher text
	string cipher = plain;
	for (int c = 0; c < strlen(plain); c++)
	{
		if ((plain[c] > 64 && plain[c] < 91))
		{
			for (int i = 65; i < 91; i++)
			{
				if (plain[c] == i)
				{
					cipher[c] = toupper(s[i - 65]);
					break;
				}
			}
		}
		if ((plain[c] > 96 && plain[c] < 123))
		{
			for (int i = 97; i < 123; i++)
			{
				if (plain[c] == i) 
				{
					cipher[c] = tolower(s[i - 97]);
					break;
				}
			}
		}
	}
	printf("ciphertext: %s\n", cipher);
}
//end cipherText