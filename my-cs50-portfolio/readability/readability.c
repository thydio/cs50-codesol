#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int c_w(string s);
int c_l(string s);
int c_s(string s);
int main(void)
{
    string s = get_string("Text: ");

    int sen = c_s(s);
    int wor = c_w(s);
    int let = c_l(s);

    float L = (float) let*100/wor;
    float S =(float) sen*100/wor;

    float i = floor(0.0588 * L - 0.296 * S - 15.8) ;



    if(i < 1 )
    {
        printf("Before Grade 1\n");
    }
    else if (i >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",(int)i);
    }

}

int c_w(string s) //computes no of words
{
    int counter = 1;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if(s[i] == ' ' && s[i+1] != ' '){
            counter++;
        }
    }

    return counter;
}

int c_l(string s)
{
    int counter = 0;

    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if(s[i] != ' '  && s[i] != '?' && s[i] != '!' )
        {
            counter++;
        }
    }

    return counter;
}

int c_s(string s)
{
    int counter = 0;
    for (int i = 0, l = strlen(s); i < l; i++)
    {
        if(s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
             counter++;
        }

    }
    return counter;
}
