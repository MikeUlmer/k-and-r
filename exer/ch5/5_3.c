/*
Write a pointer version of the function strcat that we showed in chapter 2: strcat(s, t)
copies the string t to the end of s
*/

#include <stdio.h>

#define MAX_LEN 10

void
ptr_strcat(char s[], char t[])
{
    /* Version 3 */
    char *s_p = s;
    char *t_p = t;
    while(*s_p != '\0') {
        s_p++;
    }
    while((*s_p = *t_p)) {
        if (++s_p > &s[MAX_LEN]) {
            printf("Concated strings are too long. Catting what I can.\n");
            *--s_p = '\0';
            break;
        }
        t_p++;
    }
    //printf("This is new string: %s\n", s);


    /* Version 1 -- Not using pointer arithmetic to do this*/
    // int i = 0, s_c = 0, t_c = 0;
    // char *s_p = s;
    // char *t_p = t;
    // while (*s_p != '\0') {
    //     s_p++;
    //     s_c++;
    // }
    // while (*t_p != '\0') {
    //     t_p++;
    //     t_c++;
    // }

    // printf("S is %d long & T is %d long\n", s_c, t_c);

    // if (s + MAX_LEN - s_p > MAX_LEN) {
    //     printf("T can't concat onto s. T is too long\n");
    //     return -1;
    // }

    // while (t[i] != '\0') {
    //     s[s_c] = t[i];
    //     i++;
    //     s_c++;
    // }
    // s[s_c] = '\0';
    // return s_c;

    /* version 2 -- Not using pointer arithmetic to do this again*/
    // int i, j;
    // int do_concat = 0;
    // //char *s_p = s;
    // for (i = 0, j = 0; i < MAX_LEN; i++) {
    //     if (s[i] == '\0') {
    //         do_concat = 1;
    //     }
    //     if (do_concat) {
    //         int check = MAX_LEN - i - j;
    //         printf("How much space left: %d\n", check);
    //         if (check == 0) {
    //             printf("NO ROOM TO CONCAT!\n");
    //             break;
    //         }
    //         s[i] = t[j];
    //         if (t[j] == '\0') {
    //             break;
    //         }
    //         j++;
    //     }
    // }
    // printf("This is new string size: %d\n", i);
    // return i;
}

int
main(void)
{
    int c, s_len = 0, t_len = 0;
    char s[MAX_LEN], t[MAX_LEN];

    printf("Enter s: ");
    while( (c = getchar()) != '\n') {
        if (s_len >= MAX_LEN) {
            printf("s is too long!\n");
            return 1;
        }
        s[s_len++] = c;
    }
    s[s_len] = '\0';
    printf("%s (%d)\n", s, s_len);

    printf("Enter t: ");
    while( (c = getchar()) != '\n') {
        if (t_len >= MAX_LEN) {
            printf("t is too long!\n");
            return 1;
        }
        t[t_len++] = c;
    }
    t[t_len] = '\0';
    printf("%s (%d)\n", t, t_len);

    ptr_strcat(s, t);
    printf("Catted string: %s\n", s);
    return 0;
}