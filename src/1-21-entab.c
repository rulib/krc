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
		newCharLength = num chars after entab
		oldCharLength = original character length
		charsToTabStop = starts at 7, ends at 0
		spaces = counter for number of spaces in a sequence

		Every time you insert a tab you need to make sure to keep incrementing oldCharLength
	*/
	int newCharLength, oldCharLength, charsToTabStop, spaces;
	newCharLength = oldCharLength = 0;
	/* iterate through original string input */
	while(oldCharLength < MAXLINE && input[oldCharLength] != '\0'){
		if(input[oldCharLength] != ' '){
			output[newCharLength] = input[oldCharLength];
			++newCharLength;
			++oldCharLength;
		}
		else {
			spaces = charsToTabStop = 0;
			/* Start looking for spaces */
			while(input[oldCharLength + spaces] == ' '){
				++spaces;
			}
			/*Replace spaces with tab*/
			charsToTabStop = TABSTOP - (oldCharLength % TABSTOP);
			if(charsToTabStop <= spaces && spaces > 1){
				output[newCharLength] = '\t';
				++newCharLength;
				oldCharLength += charsToTabStop;
			}
			/*Or handle handful of spaces*/
			else{
				for(spaces; spaces > 0; spaces--){
					output[newCharLength] = input[oldCharLength];
					++newCharLength;
					++oldCharLength;
				}
			}
		}
	}
	output[newCharLength] = '\0';
}