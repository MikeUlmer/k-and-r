/*
Exer 1.12
*/
#include <stdio.h>

#define IN 1
#define OUT 0

main() {
    int c;

    //Print histogram of the lengths of words. Try horizontal then vertical output.
    while ((c=getchar()) != EOF) {
        if (c == '\t' || c == ' ' || c == '\n') {
            putchar('\t');
        } else {
            putchar('X');
        }
    }


    // Print input one word per line
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == '\t' || c == ' ' || c == '\n') {
            putchar('\n');
        }
    }
}
