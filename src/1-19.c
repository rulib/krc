#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int retrieve(char target[], int limit);
void reverse(char source[], char output[], int length);

main()
{   
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    char reversed[MAXLINE]; /* stripped output of line */

    while ((len = retrieve(line, MAXLINE)) > 0){
            reverse(line, reversed, len);
            printf("%s", reversed);
    }

    return 0;
}

int retrieve(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && ((c=getchar()) != EOF) && c != '\n' ; ++i) 
        s[i] = c; 
    if (c == '\n') {
        s[i] = c; 
        ++i;
    }
    s[i] = '\0'; 
    return i;
}

void reverse(char src[], char out[], int length)
{
    /*
    A line of length 1 is going to be \n \0
    A line of length 5 is going to be a b c d \n \0
    \n is at position line[length-1], \0 is at position line[length]
    */
    int i;
    if (length == 1){
        out[0] = '\n';
        out[1] = '\0';
    } else {
        for (i=0; i<length-1; i++){
            out[i] = src[length - 2 - i];
        }
        out[length-1] = '\n';
        out[length] = '\0';
    }
}
