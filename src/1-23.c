/* Decommenter - removes all comments */


/*

Read a line character by character.  Starting state is "normal code".
From normal code, you can encounter a character constant, a string literal,
or a comment.

If you are in a character constant, you can encounter an escape sequence
Disregard the character after a backslash - it could be anything, even a 
single quote.  If you encou"thisnter a single quote not preceded by a backslash
return to the previous state.

If you are in a string literal, the same rules apply, but you use double
quotes.

If you encounter a forward slash while in normal code, check for an asterisk
and enter a comment if found.

If you find a double forward slash, enter a comment and leave it after a newline

While in a comment, if you find an asterisk check for a forward slash, if found
leave the comment.

Modes:
0: normal code
1: character constant
2: string literal
3: comment
5: escape sequence

While in mode 3 or 4, stop copying text to the output, just insert a newline
or whatever if that's all that line has.

Retrieve a line of code
Parse it for state
Return altered line based on state
*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int retrieve(char target[], int limit);
int parse(char src[], char tgt[], int mode, int length);

main()
{
    int mode = 0;
    int len;        /* current line length */
    char line[MAXLINE];     /* current input line */
    char parsed[MAXLINE];

    while ((len = retrieve(line, MAXLINE)) > 0){
        mode = parse(line, parsed, mode, len);
        printf("%s", parsed);
    }

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

int parse(char s[], char t[], int mode, int l)
{
    int i, x=0, m;
    m = mode;
    //printf("Parsing line: %s\n", s);
    for(i=0; i<l; i++){
        switch (m) {
            case 0:{
                if(s[i]=='/'&&s[i+1]=='*'){
                    //printf("3 from 0");
                    m = 3;
                    i++;
                } else if(s[i]=='\'') {
                    //printf("1 from 0");
                    m = 1;
                    t[x] = s[i];
                    x++;
                } else if(s[i]=='\"'){
                    //printf("2 from 0");
                    m = 2;
                    t[x] = s[i];
                    x++;
                } else if(s[i]=='\\'){
                    //printf("5 from 0");
                    //m = 5;
                    t[x] = s[i];
                    t[x+1] = s[i+1];
                    i++;
                    x+=2;
                } else {t[x]=s[i];
                    x++;
                }
                break;}
            case 1: 
                if(s[i]=='\''){
                    //printf("0 from 1");
                    m = 0;
                    t[x] = s[i];
                    x++;
                } else if(s[i]=='\\'){
                    //printf("5 from 1");
                    //m = 5;
                    t[x] = s[i];
                    t[x+1] = s[i+1];
                    i++;
                    x+=2;
                } else {t[x]=s[i];
                    x++;
                }
                break;
            case 2: 
                if(s[i]=='\"'){
                    //printf("0 from 2");
                    m = 0;
                    t[x] = s[i];
                    x++;
                } else if(s[i]=='\\'){
                    //printf("5 from 2");
                    //m = 5;
                    t[x] = s[i];
                    t[x+1] = s[i+1];
                    i++;
                    x+=2;
                } else {t[x]=s[i];
                    x++;
                }
                break;
            case 3: 
                if(s[i]=='*'&&s[i+1]=='/'){
                    //printf("0 from 3");
                    m = 0;
                    i++;
                } 
                break;
        }
        if(x==0){
            t[0]='\0';
        } else if(t[x-1] != '\n'){
            t[x] = '\n';
            t[x+1] = '\0';
        } else {t[x] = '\0';}
    }
    return m;
}