/*
We should return EOF for end of file,
zero if the next input is not a number,
and a positive vlaue if the input contains a valid number.

It seems like I have a real hard time if I'm not given the big picture first. Or enough of a picture where I'm comfortable
doing work.
If I'm given a task that's truly arbitrary, I have a real hard time understanding it. I want to know its purpose, how it's used,
what type of input it will get & what it will do w/ that in put afterwards.

This task was interesting in that it told me in 1 line what the program was supposed to do.
I got sidetracked in how it was used because I wanted to understand context so that I could extend it.
I don't have that luxury.

get int treats a + or - not followed by a digit as a valid representation of zero. fix it to push a character back on the input.

** I fixed this by moving the check for + or - right after the whileloop that skipped spaces
*/
#include <stdio.h>
#include <ctype.h>

#define BUFFERLENGTH 5

int n = 0, buf[BUFFERLENGTH];

int getch(void)
{
    if (n > 0) {
        int bob = buf[--n];
        //printf("\nGot buf[--n]: %d", bob);
        return bob;
    } else {
        //printf("(getchar called)\n");
        int bob = getchar();
        //printf("\ngot this from getchar: %d\n", bob);
        return bob;
    }
    //return (n > 0) ? buf[--n] : getchar();
}

void ungetch(int c)
{
    if(n < BUFFERLENGTH)
        buf[n++] = c;
    else
        printf("error: ungetch buffer overflow\n");
}

// 5.1
int
getint(int *pn)
{
    int c, sign;
    //printf("\n%s called\n", __func__);
    while (isspace(c = getch())) {
        printf("\nFound a space!");
    }
    
    if (c == '+' || c == '-') {
        //printf("\nFound a +/-");
        sign = c == '-' ? -1 : 1;
        c = getch();
    }
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        printf("\nNot a digit, input isn't over and we aren't a + or -: %c", (char)c);
        ungetch(c);
        return 0;
    }

    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');  // this adds all the characters up!
        printf("\nThis is pn: %d", *pn);
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int
main()
{
    int j = getint(&buf[n]);
    printf("\nThis is result of getint: %d\nAnd its buffer:\n", j);
    for (n = 0; n < BUFFERLENGTH; n++) {
        printf(" %c ", (char)buf[n]);
    }
    printf("\n");
}
