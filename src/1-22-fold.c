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
	while(1){
		if(line[0] == '\0'){
			break;
		}
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

output is string to be printed
next is string to be recursed on
*/
void printFolded(char line[])
{
	int charCounter, breakPoint, breakCounter, forced;
	char output[MAXLINE], next[MAXLINE];
	forced = 0;
	/* Sets up 'next' to not recurse if unused*/
	next[0] = '\0';
	charCounter = breakPoint = breakCounter = 0;
	/* Counts and checks for breakpoint */
	while(charCounter < MAXLINE && line[charCounter] != '\n' && line[charCounter] != '\0'){
		/* Check for breakpoints */
		if(charCounter < MAXOUT && line[charCounter] == ' '){
			breakPoint = charCounter;
		}
		charCounter++;
	}
	/* Handle short lines and move on */
	if(charCounter <= MAXOUT) {
		line[charCounter+1] = '\0';
		printf("%s", line);
		printf("EOS");
	}
	/* Split at last space before 80 or 80 char */
	else if (charCounter > MAXOUT){
		/* puts first 80 into output */
		if(breakPoint == 0){
			breakPoint = MAXOUT;
			forced = 1;
		}
		while(breakCounter < breakPoint && line[breakCounter] != '\0'){
			output[breakCounter] = line[breakCounter];
			breakCounter++;
		}
		output[breakCounter] = '\n';
		output[breakCounter + 1] = '\0';
		printf("%s", output);
		/* Skip the space if actually broken at space*/
		if(forced == 0){
			breakCounter++;
		}
		/* puts remainder into next */
		while(line[breakCounter] != '\0'){
			/* Note offset to account for skipping space */
			if(forced==0){
				next[breakCounter - (breakPoint+1)] = line[breakCounter];
			}
			else{
				next[breakCounter - (breakPoint)] = line[breakCounter];
			}
			breakCounter++;
		}
		next[breakCounter] = '\n';
		next[breakCounter + 1] = '\0';
		printf("EOO");
	}
	/* Handle lines without spaces */
	/*else if (charCounter > MAXOUT && breakPoint == 0){
		printf("Get some spaces bitch\n");
	}*/
	/* If there is any remainder... */
	if(next[0] != '\0'){
		printFolded(next);
	}
}
