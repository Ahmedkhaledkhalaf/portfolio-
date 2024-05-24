#include <stdio.h>

void string_reverse (char *first, char *last);

void word_reverse (char *word);

int main()
{

    char string[]="i love programming";
    word_reverse(string);
    printf("%s", string);
    return 0;
}

void string_reverse (char *first, char *last)
{
    char temp;
    while (first<last)
    {
        temp = *first;
        *first++ = *last;
        *last-- = temp;

    }
}


void word_reverse (char *word)
{
    char *word_start = word;
    char *temp = word;
    while (*temp)
    {
        temp++;
        if (*temp == '\0')
        {
            string_reverse(word_start, temp-1);
        }
        else if (*temp == ' ')
        {
            string_reverse(word_start, temp-1);
            word_start = temp+1;
        }
    }
    string_reverse(word, temp-1);
}
