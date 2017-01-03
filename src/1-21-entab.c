/* Entab - replaces blanks with tabs and blanks
(each tab stop is 8 spaces long) 

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

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */
#define TABSTOP 8 /* tab stop spacing */

/*retrieves a line and stores it in target */
void retrieve(char target[], int limit);
/*removes all tabs from source and stores result in target */
void detab(char source[], char target[]);
/*takes a PREVIOUSLY DETABBED input and converts spaces to tabs in target */
void retab(char detabbed[], char target[]);

int main(void)
{
	int index, length;
	char line[MAXLINE], detabbed[MAXLINE], retabbed[MAXLINE];
	while(1){
		retrieve(line, MAXLINE);
		if(line[0] == '\0'){
			break;
		}
		detab(line, detabbed);
		retab(detabbed, retabbed);
		printf("%s", retabbed);
	}
	printf("\n");
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

void detab(char s[], char t[])
{
	int i, j, o, r;
	/* o tracks new length of line */
	o = 0;
	for(i=0; i < MAXLINE && s[i] != '\0'; ++i){
		if(s[i] == '\t'){
			/* Keep printing spaces until you hit a tabstop */
			r = (o % TABSTOP);
			for(j=0; j< TABSTOP - r; ++j){
				/* increment detabbed position counter to account for new spaces */
				o++;
				t[o] = ' ';
			}
		} else {
			/* just increment it once */
			o++;
			t[o] = s[i];
		}
	}
}

void retab(char s[], char t[])
{
	int i, j, o, r, q;
	/* i iterates thru s, o is shorter than i, tracks length of output */
	o = 0
	for(i=0; i < MAXLINE && s[i] != '\0'; ++i){
		if(s[i] == ' '){			
			q = 0;
			j = i;
			/*critically, o is used for all tabstop calcs*/
			r = TABSTOP - (o % TABSTOP);
			/*look ahead and count spaces into q*/
			while(s[j] == ' '){
				q++;
				j++;
			}
			if(q >= r){
				
			}

		} else {
			/* increment o once */
			o++;
			t[o] = s[i];
		}
	}
}