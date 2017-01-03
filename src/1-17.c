#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
int retrieveline(char line[], int maxline);

/* print longest input line */
main()
{   
    int i;
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = retrieveline(line, MAXLINE)) > 0)
        if (len > 80) {
            printf("%s", line);
        }
    return 0;
}

/* get line: read a line into s, return length */
int retrieveline(char s[], int lim)
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
