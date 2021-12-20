#include<stdio.h>
#include <string.h>
#include"ex3.h"

#define TXT 1024
#define WORD 30

int main()
{

char word[WORD];
char text[TXT];

    scanf("%[^\n\t'']",word);
    scanf("%[^~]",text);

    Gematria_Sequences(text,word);
    Atbash_Sequences(text,word);
    Anagram_Sequences(text,word);
    return 0;
}