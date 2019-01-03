#include <stdio.h>

int
get_str(char buf[], int max_len)
{
    int c, len = 0;
    while( (c = getchar()) != '\n') {
        if (len >= max_len) {
            printf("input is too long!\n");
            return -1;
        }
        buf[len++] = c;
    }
    buf[len] = '\0';
    printf("%s (%d)\n", buf, len);
    return 0;
}