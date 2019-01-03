/*
Write the function strend(s, t) which returns 1 if the string T occurs at the end of the string S, and zero otherwise.

Reflections:
Upon finishing this version of strend & now looking back, I could've done this much easier by advancing both
s_p & t_p. Then decrementing each pointer until t is exhausted or we have no more s to look at.
*/

#include <stdio.h>
#include "utils.h"

#define MAX 10

int
strend(char s[], char t[])
{
    char *s_p = s;
    char *t_p = t;
    // get to the end of s because we're going to compare the beginning of t to the end of s, then back up s_p
    // and check against the beginning of t. If there's a match, then incremnet both s&t pointers & compare them.
    while (*s_p++ != '\0'){
        ;
    }

    while (*t_p != *s_p--) {
        // go backwards in s until first letter of t matches s_p or until s_p is exhausted
        // printf("Looking to see if %c matches %c. Does it? %s\n", *t_p, *s_p, *s_p == *t_p ? "YES" : "NO");
        if (*s_p == *t_p) {
            break;
        } else if (s_p == s) {  // we've exhausted the characters in s.
            goto no_match;
        }
    }

    while (*s_p++ == *t_p++) {
        if (*s_p == '\0' && *t_p == '\0') {
            // We reached the end of s & t and they were the same all the way through!
            return 1;
        }
    }

no_match:
    return 0;
}

int
main(void)
{
    int rc = 0;
    char str_1[MAX], str_2[MAX];

    printf("Enter string1: ");
    rc = get_str(str_1, MAX);
    if (rc) goto end;

    printf("Enter string2: ");
    rc = get_str(str_2, MAX);
    if (rc) goto end;

    rc = strend(str_1, str_2);
    printf("Does String 2 lives at the end of String 1? %c\n", rc ? 'Y' : 'N');

end:
    printf("Exiting (%d)\n", rc);
    return rc;
}