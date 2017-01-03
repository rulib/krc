#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int retrieve(char target[], int limit);
void strip(char source[], char output[], int limit);

main()
{   
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    char stripped[MAXLINE]; /* stripped output of line */

    while ((len = retrieve(line, MAXLINE)) > 0){
        if(len > 1){
            strip(line, stripped, MAXLINE);
            printf("%s", stripped);
        }
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

void strip(char src[], char out[], int lim)
{
    int i, last;
    for (i=0; i<lim-1 && src[i] != '\n'; i++){
        if (src[i] != '\t' && src[i] != ' '){
            last = i;
        }
    }
    for (i = 0; i<=last; i++){
        out[i] = src[i];
    }
    out[last+1] = '\n';
    out[last+2] = '\0';
}
