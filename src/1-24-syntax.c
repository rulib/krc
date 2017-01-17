/*
Write a program to check for unbalanced parens, brackets, and braces.
Account for quotes (single and double), escape sequences, and comments.

X Parens
Brackets
X Braces
X SingleQuotes
X DoubleQuotes
Escape Sequences
X One Line Comments
Multi Line Comments

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
int processQuotes(int mode, int stack[], int stackPosition);
int openBlocks(int mode, int stack[], int stackPosition);
int closeBlocks(int mode, int stack[], int stackPosition);

/* Main control program */
int main(void)
{
    int stackPosition, mode;
    int stack[MAXSTACK];
    char line[MAXLINE];
    int lineNumber;
    lineNumber=0;
    mode = DEFAULT;
    stackPosition = 0;
    stack[0] = DEFAULT;
    //printf("Initializing...");
    while(1){
        retrieve(line, MAXLINE);
        if(line[0] == '\0'){
            break;
        }
        printf("%i ", ++lineNumber);
        stackPosition = parseCode(line, stack, stackPosition, mode);
        printf("\n");
        //printf("Printing stack after line %i...\n", k);
        /*for(int j=0;j<20;++j) {
             printf("%i ", stack[j]);
        }*/
    }
    if(stack[stackPosition] == SQUOTE || stack[stackPosition] == DQUOTE){
        printf("ERROR: FAIL TO CLOSE QUOTE");
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

int processQuotes(int mode, int stack[], int stackPosition){
    int oppositeQuoteMode = DQUOTE;
    if(mode == DQUOTE){oppositeQuoteMode = SQUOTE;}
    if(stack[stackPosition] == oppositeQuoteMode 
        || stack[stackPosition] == COMMENT
        || stack[stackPosition] == SINGLECOMMENT){
    }
    else if(stack[stackPosition] == mode){
        if(mode == SQUOTE){
        printf("ENDING AN SQUOTE\n");
        }
        if(mode == DQUOTE){
        printf("ENDING A DQUOTE\n");
        }
        stackPosition--;
    } else {
        stackPosition++;
        stack[stackPosition] = mode;
        if(mode == SQUOTE){
        printf("OPENING AN SQUOTE\n");
        }
        if(mode == DQUOTE){
        printf("OPENING A DQUOTE\n");
        }
    }
    return stackPosition;
}

int openBlocks(int mode, int stack[], int stackPosition){
    if(mode == CURLYBLOCK){
        printf("OPENING A CURLYBLOCK\n");
    } else if(mode == PAREN){
        printf("OPENING A PAREN\n");
    } else if(mode == BRACKETS){
        printf("OPENING A BRACKET\n");
    }
    stackPosition++;
    stack[stackPosition] = mode;
    return stackPosition;
}

int closeBlocks(int mode, int stack[], int stackPosition){
    if(stack[stackPosition] == mode){
        if(mode == CURLYBLOCK){
            printf("CLOSING A CURLYBLOCK\n");
        } else if(mode == PAREN){
            printf("CLOSING A PAREN\n");
        } else if(mode == BRACKETS){
            printf("CLOSING A BRACKET\n");
        }
        stackPosition--;
    } else {
        if(mode == CURLYBLOCK){
            printf("ERROR CLOSED } WITHOUT OPEN\n");
        } else if(mode == PAREN){
            printf("ERROR CLOSED ) WITHOUT OPEN\n");
        } else if(mode == BRACKETS){
            printf("ERROR CLOSED ] WITHOUT OPEN\n");
        }
    }
    return stackPosition;
}

int parseCode(char s[], int stack[], int stackPosition, int mode)
{
    int c, i, modeForCase;
    for(i=0; i < MAXLINE && s[i] != '\0'; ++i) {
        switch (s[i]) {
            case '\'':
                modeForCase = SQUOTE;
                stackPosition = processQuotes(modeForCase, stack, stackPosition);
                break;
            case '\"':
                modeForCase = DQUOTE;
                stackPosition = processQuotes(modeForCase, stack, stackPosition);
                break;
            case '{':
                modeForCase = CURLYBLOCK;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                    break;
                }
                stackPosition = openBlocks(modeForCase, stack, stackPosition);
                break;
            case '}': 
                modeForCase = CURLYBLOCK;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                    break;
                }
                stackPosition = closeBlocks(modeForCase, stack, stackPosition);
                break;
            case '/':
                modeForCase = COMMENT;
                if(stack[stackPosition] != COMMENT 
                    && stack[stackPosition] != SINGLECOMMENT && s[i+1] == '/'){
                    stackPosition++;
                    stack[stackPosition] = SINGLECOMMENT;
                    printf("ENTERING A SINGLE LINE COMMENT\n");
                } else if(stack[stackPosition] != COMMENT 
                    && stack[stackPosition] != SINGLECOMMENT
                    && s[i+1] == '*'){
                    stackPosition++;
                    stack[stackPosition] = COMMENT;
                    printf("ENTERING A COMMENT\n");
                }
                break;
            case '*':
                if(stack[stackPosition] == COMMENT && s[i+1] == '/'){
                    stackPosition--;
                    printf("EXITING A MULTI LINE COMMENT\n");
                }
                break;
            case '(':
                modeForCase = PAREN;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                    break;
                }
                stackPosition = openBlocks(modeForCase, stack, stackPosition);
                break;
            case ')':
                modeForCase = PAREN;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                    break;
                }
                stackPosition = closeBlocks(modeForCase, stack, stackPosition);
                break;
            case '[':
                modeForCase = BRACKETS;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                    break;
                }
                stackPosition = openBlocks(modeForCase, stack, stackPosition);
                break;
            case ']':
                modeForCase = BRACKETS;
                if(isCommentOrQuote(stack[stackPosition]) == 1) {
                    break;
                }
                stackPosition = closeBlocks(modeForCase, stack, stackPosition);
                break;
        }
    }
    if(stack[stackPosition] == SINGLECOMMENT){
        stackPosition--;
        printf("SINGLECOMMENT EXPIRES\n");
    }
    return stackPosition;
}


