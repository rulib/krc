/*
Write a program to check for unbalanced parens, brackets, and braces.
Account for quotes (single and double), escape sequences, and comments.

So we are looking for {} [] () '' "" \ //
Relevant escape sequences are escaped versions of all of the above - that is to say
the program never enters a new "mode" in the char following \

Relevant modes are derived from all of the above
Read the program one char at a time (checking for comments and escapes) and
enter and exit  modes.  If a mode is never exited, or an exit is encountered for a mode
that you are not actually in, throw an error.

Track modes in a big array I guess since we don't have any better data structures yet
Increment and decrement the index in an integer
*/

#include <stdio.h>
#define MAXLINE 1024 /* maximum input line size */
#define MAXSTACK 1024 /* maximum stack size */
#define MAXOUT 80 /* terminal width - aka max output line */
#define DEFAULT 0
#define CURLYBLOCK 1
#define BRACKETS 2
#define PAREN 3
#define SQUOTE 4
#define DQUOTE 5
#define COMMENT 6
#define SINGLECOMMENT 7
#define OPENERS ('{' || '(' || '[')
#define CLOSERS ('}' || ')' || ']')

void retrieve(char target[], int limit);
void parseCode(char target[]);

/* Main control program */
int main(void)
{
	int stackPosition;
	int stack[MAXSTACK];
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
void parsecode(char s[], int stack[], int stackPosition)
{
    int c, i;
}

