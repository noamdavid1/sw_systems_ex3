#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TXT 1024
#define WORD 30

int calculation_Gematria(char word)
{
    if ((word < 123) && (word > 96))
    {
        return (word - 96);
    }
    if ((word > 64) && (word < 91))
    {
        return (word - 64);
    }
    return 0;
}

void Gematria_Sequences(char text[TXT], char word[WORD])
{
    printf("Gematria Sequences: ");
    int wanted_sum = 0;
    for (int j = 0; j < strlen(word); j++)
    {
        wanted_sum += calculation_Gematria(word[j]);
    }
    int min_seq = 0;
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        min_seq = 0;
        if (calculation_Gematria(text[i]) == 0)
        {
            continue;
        }

        if (text[i] == '~')
        {
            printf("\n");
            return;
        }
        for (int j = i; j < strlen(text); j++)
        {
            min_seq += calculation_Gematria(text[j]);
            if (min_seq == wanted_sum)
            {
                if (count != 0)
                {
                    printf("~");
                }
                for (int k = i; k <= j; k++)
                {
                    printf("%c", text[k]);
                }
                count++;
                break;
            }
            else if (min_seq > wanted_sum)
            {
                break;
            }
        }
    }
    printf("\n");
}

char Atbash(char c)
{
    char small_alfa_beta[26] = "abcdefghijklmnopqrstuvwxyz";
    char big_alfa_beta[26] = "ABCDEFGHIJKLMNOPQRSYUVWXYZ";
    int index;
    char ans = 0;
    if ((c < 110) && (c > 96))
    {
        index = 25 - (c - 97);
        ans = small_alfa_beta[index];
        return ans;
    }
    else if ((c < 123) && (c > 109))
    {
        index = 26 - (c - 96);
        ans = small_alfa_beta[index];
        return ans;
    }
    else if ((c < 78) && (c > 64))
    {
        index = 25 - (c - 65);
        ans = big_alfa_beta[index];
        return ans;
    }
    else if ((c < 91) && (c > 77))
    {
        index = 26 - (c - 64);
        ans = big_alfa_beta[index];
        return ans;
    }
    return ans;
}

int find_word(char text[TXT], char word[WORD], int x)
{
    int count = 0;
    int j = 0;
    while (j < strlen(word) && word[j] == text[x])
    {
        if (word[j] == text[x])
        {
            if (count == strlen(word) - 1)
            {
                return x;
            }
            count++;
            j++;
            x++;
        }
        if (text[x] == ' ')
        {
            x++;
        }
    }
    return -1;
}

void Atbash_Sequences(char text[TXT], char word[WORD])
{
    printf("Atbash Sequences: ");
    int index = 0;
    int sum = 0;
    int size = strlen(word);
    int size1 = strlen(text);
    char sequence[WORD];
    char revers_atbash[size];
    int count = size - 1;
    for (int i = 0; i < strlen(word); i++)
    {
        sequence[i] = Atbash(word[i]);
    }
    for (int i = 0; i < strlen(word); i++)
    {
        revers_atbash[count] = sequence[i];
        count--;
    }
    for (int j = 0; j < size1; j++)
    {
        index = find_word(text, sequence, j);
        if (index != -1)
        {
            if (sum != 0)
            {
                printf("~");
            }
            for (int n = j; n <= index; n++)
            {
                printf("%c", text[n]);
            }
            sum++;
        }
    }
    for (int j = 0; j < size1; j++)
    {
        index = find_word(text, revers_atbash, j);
        if (index != -1)
        {
            if (sum != 0)
            {
                printf("~");
            }
            for (int n = j; n <= index; n++)
            {
                printf("%c", text[n]);
            }
            sum++;
        }
    }
    printf("\n");
}

void remove_char(char new_word[], char s1)
{
    for (int i = 0; i < strlen(new_word); i++)
    {
        if (new_word[i] == s1)
        {
            *(new_word + i) = ' ';
        }
    }
}

int counter(char text[TXT], char word[WORD], int* i)
{
    int size = strlen(word);
    int count = 0;
    for (int j = *i; j < strlen(text); j++)
    {
        if (isspace(text[j]) != 0 && count == 0)
        {
            (*i)++;
            continue;
        }
        if (count != size && text[j] != ' ')
        {
            count++;
        }
        if (count == size)
        {
            return j;
        }
    }
    return -1;
}

int get_index(char text[TXT], char word1[WORD], int j, int c)
{
    char word[WORD];
    strcpy(word, word1);
    int k = 0;
    int sum = 0;
    int i = j;
    int bool = 0;
    int size = strlen(word);
    while (i <= c)
    {
        for (int n = 0; n < strlen(word); n++)
        {
            if (text[i] != word[n] && word[n] != ' ' && text[i] != ' ')
            {
                bool = -1;
            }
            else if (word[n] == ' ' || text[i] == ' ')
            {
                continue;
            }
            else
            {
                bool = 0;
                break;
            }
        }
        if (bool != 0)
        {
            return -1;
        }
        if (word[k] == text[i] && word[k] != ' ' && text[i] != ' ')
        {
            remove_char(word, word[k]);
            sum++;
            k = 0;
            i++;
        }
        else if (word[k] == ' ')
        {
            k++;
        }
        else if (text[i] == ' ')
        {
            i++;
        }
        else if (word[k] != text[i] && word[k] != ' ' && text[i] != ' ')
        {
            k++;
        }
        if (size == sum)
        {
            return c;
        }
    }
    return -1;
}

void Anagram_Sequences(char text[TXT], char word[WORD])
{
    printf("Anagram Sequences: ");
    int check = 0;
    int seq = 0;
    int sum = 0;
    int i = 0;
    while (i < strlen(text))
    {
        check = counter(text, word, &i);
        seq = get_index(text, word, i, check);
        if (seq != -1)
        {
            if (sum != 0)
            {
                printf("~");
            }
            for (int n = i; n <= seq; n++)
            {
                printf("%c", text[n]);
            }
            sum++;
        }
        i++;
    }
}
