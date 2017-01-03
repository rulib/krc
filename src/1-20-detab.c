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

int main(void)
{
	char line[MAXLINE], output[MAXLINE];
	while(1){
		retrieve(line, MAXLINE);
		if(line[0] == '\0'){
			break;
		}
		parse(line, output);
		printf("%s", output);
	}
	return 0;
}


void retrieve(char s[], int lim)
{
    int c, i;
    for (i=0; i<lim-1 && ((c=getchar()) != EOF) && c != '\n' ; ++i) 
        s[i] = c; 
    /*Critically, stops doing getchar() once \n is encountered */
    if (c == '\n') {
        s[i] = c; 
        ++i;
    }
    s[i] = '\0'; 
}

void parse(char s[], char t[])
{
	int i, j, o, r;
	/* o tracks new length of line */
	o = 0;
	for(i=0; i < MAXLINE && s[i] != '\0'; ++i){
		if(s[i] == '\t'){
			/* Keep printing spaces until you hit a tabstop */
			r = (o % TABSTOP);
			for(j=0; j < TABSTOP - r; ++j){
				/* increment output position counter to account for new spaces */
				t[o] = ' ';
				o++;
			}
		}
		else {
			/* just increment it once */
			t[o] = s[i];
			o++;
		}
	}
	/*Crucially, terminate the line!!!!*/
	t[o] = '\0';
}