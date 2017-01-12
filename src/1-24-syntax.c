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