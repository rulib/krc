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

void retrieve(char target[], int limit);
int parseCode(char line[], int stack[], int stackPosition, int mode);
int isCommentOrQuote(int mode);

/* Main control program */
int main(void)
{
	int stackPosition, mode;
	int stack[MAXSTACK];
	char line[MAXLINE];
	int k;
	k=0;
	mode = DEFAULT;
	stackPosition = 0;
	stack[0] = DEFAULT;
	//printf("Initializing...");
	while(1){
		retrieve(line, MAXLINE);
		if(line[0] == '\0'){
			break;
		}
		stackPosition = parseCode(line, stack, stackPosition, mode);
		//printf("Printing stack after line %i...\n", k);
		k++;
		/*for(int j=0;j<20;++j) {
 			 printf("%i ", stack[j]);
		}*/
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

/* Loads a line */
int isCommentOrQuote(int mode){
	if(mode == SINGLECOMMENT ||
		mode == COMMENT ||
		mode == DQUOTE ||
		mode == SQUOTE){
		return 1;
	}
	return 0;
}

int parseCode(char s[], int stack[], int stackPosition, int mode)
{
    int c, i, modeForCase;
    /*for(i=0; i < MAXLINE && s[i] != '\0'; ++i) {
    	if(s[i]=='{' || s[i]=='(' || s[i]=='['){
    		printf("OPENING CHAR\n");
    	}
    	if(s[i]=='}' || s[i]==')' || s[i]==']'){
    		printf("CLOSING CHAR\n");
    	}
    }*/
    for(i=0; i < MAXLINE && s[i] != '\0'; ++i) {
	    switch (s[i]) {
            case '{':
            	modeForCase = CURLYBLOCK;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                	break;
                }
                else if(stack[stackPosition] == DEFAULT){
                    printf("OPENING A CURLYBLOCK\n");
                    stackPosition++;
                    stack[stackPosition] = CURLYBLOCK;
                } 
                else if(stack[stackPosition] == CURLYBLOCK){
                    printf("OPENING A NESTED CURLYBLOCK\n");
                    stackPosition++;
                    stack[stackPosition] = CURLYBLOCK;
                } 
                break;
            case '}': 
            	modeForCase = CURLYBLOCK;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                	break;
                }
                else if(stack[stackPosition] != CURLYBLOCK){
                    printf("ERROR, CLOSED (}) WITHOUT OPENING\n");
	                } 
                else if(stack[stackPosition] == CURLYBLOCK){
                    printf("CLOSING A CURLYBLOCK\n");
                    stackPosition--;
                } 
                break;
            case '/':
            	modeForCase = COMMENT;
            	if(stack[stackPosition] != COMMENT 
            		&& stack[stackPosition] != SINGLECOMMENT && s[i+1] == '/'){
            		stackPosition++;
            		stack[stackPosition] = SINGLECOMMENT;
            		printf("ENTERING A SINGLE LINE COMMENT\n");
            	}
            case '(':
                modeForCase = PAREN;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                	break;
                }
                else if(stack[stackPosition] == DEFAULT || 
                	stack[stackPosition] == CURLYBLOCK){
                    printf("OPENING A PAREN\n");
                    stackPosition++;
                    stack[stackPosition] = PAREN;
                } 
                else if(stack[stackPosition] == PAREN){
                    printf("OPENING A NESTED PAREN\n");
                    stackPosition++;
                    stack[stackPosition] = PAREN;
                } 
                break;
            case ')':
                modeForCase = PAREN;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                	break;
                }
                else if(stack[stackPosition] != PAREN){
                    printf("ERROR, CLOSED ()) WITHOUT OPENING\n");
	                } 
                else if(stack[stackPosition] == PAREN){
                    printf("CLOSING A PAREN\n");
                    stackPosition--;
                } 
                break;
		}
	}
	if(stack[stackPosition] == SINGLECOMMENT){
		stackPosition--;
		printf("SINGLECOMMENT EXPIRES\n");
	}
	return stackPosition;
}


