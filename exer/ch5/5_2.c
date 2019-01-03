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

#include <math.h>

#define BUFFERLENGTH 5

int n = 0;
float buf[BUFFERLENGTH];

int getch(void)
{
    return (n > 0) ? buf[--n] : getchar();
}

void ungetch(int c)
{
    if(n < BUFFERLENGTH)
        buf[n++] = c;
    else
        printf("error: ungetch buffer overflow\n");
}

float
getfloat(float *pn)
{
    int c, sign, found_dec = 0;
    float multiplier;

    while (isspace(c = getch())) {
        //printf("\nFound a space!");
    }
    
    if (c == '+' || c == '-') {
        //printf("\nFound a +/-");
        sign = c == '-' ? -1 : 1;
        c = getch();
    }
    
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        //printf("\nNot a digit, input isn't over and we aren't a + or -: %c", (char)c);
        ungetch(c);
        return 0;
    }

    for (*pn = 0, multiplier = .1; isdigit(c) || c == '.'; c = getch()) {
        if (c == '.') {
            found_dec = 1;
            continue;
        }

        if (found_dec) {
            *pn += multiplier * (c - '0');
            multiplier /= 10;
        } else {
            //printf("this is %d - '0': %d\n", c, c-'0');
            //printf("this is 10 * pn: %f\n", 10 * *pn);
            *pn = 10 * *pn + (c - '0');
        }

        //printf("This is pn: %f\n\n", *pn);
    }
    *pn *= sign;
    printf("This is the number that was input: %f\n", *pn);
    if (c != EOF) {
        // The for loop looked through input up to the input that was not a digit.
        // Now it's going to throw that back on the buffer. WHy? What are we going to do with it later?
        // It doesn't matter. That's just what it does and this is exercise is almost over.
        ungetch(c);
    }
    return (float)c;
}

int
main()
{
    float i = getfloat(&buf[n]);
    printf("\nThis is result of getfloat: %f\nAnd its buffer:\n", i);
    for (n = 0; n < BUFFERLENGTH; n++) {
        printf("%c ", (char)buf[n]);
    }
    printf("\n");
    
}
