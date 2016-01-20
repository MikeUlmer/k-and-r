/*
Comprises exercises 1.6, 1.7, 1.8, 1.9, and 1.10 of K&R
*/
//Control-D is how to intro a EOF!
#include <stdio.h>

main() {
    int c, wts_count,d;

    //printf("This is EOF: %d\n", EOF);

    //printf("getchar() != EOF is equal to 1 or 0: %d\n", getchar() != EOF);

    printf("Output the tabs, backspaces, and backslashes as their literal characters.\n");
    while((c=getchar()) != EOF) {
        if(c == '\t') {
            putchar('\\'); putchar('t');
        } else if(c == '\b') {
            putchar('\\'); putchar('b');
        } else if(c == '\\') {
            putchar('\\');
        } else {
            putchar(c);
        }
    }

    printf("Count all line breaks, spaces, and tabs.\n");
    while((c=getchar()) != EOF) {
        wts_count += (c == '\n' || c == ' ' || c == '\t') ? 1 : 0;
    }
    printf("Word/tab/space count: %d\n\n", wts_count);

    printf("Shorten any given series of character\'s spaces to one space between characters.\n");
    while((c=getchar()) != EOF) {
        if(c == ' ') {
            while( (c=getchar()) == ' '); //moves the pointer c is at--iterates--until hits a char.
            putchar(' ');
        }
        putchar(c);
    }





}
