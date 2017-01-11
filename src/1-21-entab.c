/* 
Entab - replaces blanks with tabs and blanks
*/

#include <stdio.h>
#define MAXLINE 1024 /* maximum input line size */
#define TABSTOP 8 /* tab stop spacing */

void retrieve(char target[], int limit);
void parse(char source[], char target[]);
void retab(char source[], char target[]);

/* Main control program */
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

/* Loads a line */
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

/* Strips out existing stray tabs */
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

/* Converts spaces to tabs */
void retab(char input[], char output[])
{
	/*
		overall length is going to be getting SHORTER here so...
		outLen = num chars after retabbing
		inLen = original character length
		toTab = starts at 7, ends at 0, characters to next tab stop
		spaces = counter for number of spaces in a sequence

		Every time you insert a tab you need to make sure to keep incrementing inLen
	*/
	int outLen, inLen, toTab, spaces;
	outLen = inLen = 0;
	/* iterate through original string input */
	while(inLen < MAXLINE && input[inLen] != '\0'){
		if(input[inLen] != ' '){
			output[outLen] = input[inLen];
			++outLen;
			++inLen;
		}
		else {
			spaces = toTab = 0;
			/* Start looking for spaces */
			while(input[inLen + spaces] == ' '){
				++spaces;
			}
			/*Replace spaces with tab*/
			toTab = TABSTOP - (inLen % TABSTOP);
			if(toTab <= spaces && spaces > 1){
				output[outLen] = '\t';
				++outLen;
				inLen += toTab;
			}
			/*Or handle handful of spaces*/
			else{
				for(spaces; spaces > 0; spaces--){
					output[outLen] = input[inLen];
					++outLen;
					++inLen;
				}
			}
		}
	}
	output[outLen] = '\0';
}