/* Entab - replaces blanks with tabs and blanks
(each tab stop is 8 spaces long) 

WORK IN PROGRESS

Track where you are in the line - index in line % 8.

Index:
	      111111
0123456789012345
Remainder:
0123456701234567
Number of spaces:
8765432187654321

Tabstop - Remainder number of spaces

Copy as normal.

Detab the text to strip existing tabs and make it easier to parse tabstops.

When you encounter a blank, start looking ahead at how many blanks it is.
Look at how many tabstops you pass.

You will need to track tabstops based on the detabbed text.
*/

/* Detab - replaces tabs with blanks (each tab stop is 8 spaces long) 

DONE

Track where you are in the line - index in line % 8.

Index:
	      111111
0123456789012345
Remainder:
0123456701234567
Number of spaces:
8765432187654321

Tabstop - Remainder number of spaces

*/

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define TABSTOP 8 /* tab stop spacing */

void retrieve(char target[], int limit);
void parse(char source[], char target[]);
void retab(char source[], char target[]);

int main(void)
{
	char line[MAXLINE], output[MAXLINE];
	while(1){
		retrieve(line, MAXLINE);
		if(line[0] == '\0'){
			break;
		}
		parse(line, output);
		retab(output, line);
		printf("%s", line);
	}
	return 0;
}


void retrieve(char s[], int lim)
{
    int c, i;
    for (i=0; i<lim-1 && ((c=getchar()) != EOF) && c != '\n' ; ++i) 
        s[i] = c; 
    if (c == '\n') {
        s[i] = c; 
        ++i;
    }
    s[i] = '\0'; 
}

void parse(char s[], char t[])
{
	int i, j, o, r;
	o = 0;
	for(i=0; i < MAXLINE && s[i] != '\0'; ++i){
		if(s[i] == '\t'){
			r = (o % TABSTOP);
			for(j=0; j < TABSTOP - r; ++j){
				t[o] = ' ';
				o++;
			}
		}
		else {
			t[o] = s[i];
			o++;
		}
	}
	t[o] = '\0';
}

void retab(char s[], char t[])
{
	/*
		overall length is going to be getting SHORTER here so...
		i = num chars after entab
		o = original character length
		Every time you insert a tab you need to make sure to keep incrementing o
	*/
	int i, j, o, r;
	o = 0;
	for(i=0; i < MAXLINE && s[i] != '\0'; ++i){
		if(s[i] == '\t'){
			r = (o % TABSTOP);
			for(j=0; j < TABSTOP - r; ++j){
				t[o] = ' ';
				o++;
			}
		}
		else {
			t[o] = s[i];
			o++;
		}
	}
	t[o] = '\0';
}