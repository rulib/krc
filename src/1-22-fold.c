/* 
Fold - breaks lines > MAXOUT into multiple lines at last space before MAXOUT chars
If no spaces before MAXOUT chars breaks at MAXOUT chars
*/

#include <stdio.h>
#define MAXLINE 1024 /* maximum input line size */
#define MAXOUT 80 /* terminal width - aka max output line */

void retrieve(char target[], int limit);
void printFolded(char source[]);
/* Main control program */
int main(void)
{
	char line[MAXLINE];
	while(line[0] != '\0'){
		retrieve(line, MAXLINE);
		printFolded(line);
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

/* 
breaks lines > MAXOUT into multiple lines at last space before MAXOUT chars
If no spaces, breaks at MAXOUT chars 
*/
void printFolded(char line)
{
	int charCounter, lastSpace, breakCounter;
	char output[MAXLINE];
	charCounter = lastspace = 0;
	while(charCounter < MAXLINE && line[charCounter] != '\n' && line[charCounter] != '\0'){
		/*
		Check for breakpoints
		*/
		if(charCounter < MAXOUT && line[charCounter] == ' '){
			lastSpace = charCounter;
		}
	}
	if(charCounter <= MAXOUT) {
		printf("%s", line);
	}
	else if (charCounter > MAXOUT && lastSpace > 0){
		breakCounter = 0;
		while(breakCounter < lastSpace){
			output[breakCounter] = line[breakCounter];
			breakCounter++
		}
		output[breakCounter] = '\n';
		output[breakCounter+1] = '\0';
		printf("%s", output);
		while(breakCounter < MAXLINE && line[breakCounter] != '\0'){
			output[breakCounter] = line[breakCounter];
			breakCounter++
		}
	}
}
