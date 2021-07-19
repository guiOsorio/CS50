// this program uses the caesar's cipher to provide a ciphered version of a string, using a command-line argument to determine the key

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int validate_arg(char* s);

int main(int argc, char* argv[])
{
    // check if argument is valid
    if((argc != 2) || !validate_arg(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // if argument is valid, the following code will run
    int key = atoi(argv[1]); // convert the key to an integer
    // ask user for input
    char input[50];
	printf("plaintext: ");
	scanf("%s", input);
    // transform original text into ciphered text
    int i;
    int len;
    for(i = 0, len = strlen(input); i < len; i++)
    {
        char c = input[i];
        if(isalpha(c))
        {
            if(isupper(c))
            {
                input[i] = (c-'A'+key)%26 + 'A';
            }
            else
            {
                input[i] = (c-'a'+key)%26 + 'a';
            }
        }
    }
    // show cipheredtext
    printf("chiphertext: %s\n", input);
}

int validate_arg(char* s)
{
	int i;
	int len;
    for(i = 0, len = strlen(s); i < len; i++)
    {
        if(!isdigit(s[i]))
        {
            return 0;
        }
    }

    return 1;
}

