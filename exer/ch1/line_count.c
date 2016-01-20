#include <stdio.h>

main() {
    long nc = 0;
    while(getchar() != EOF) {
        ++nc;
        printf("%1d\n", nc);
    }
}
