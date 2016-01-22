#include <stdio.h>

#define CHAR_SPAN 94
#define LAST_CHAR 127

int main() {
    int counts[CHAR_SPAN] = {0};
	int c,
		i,
		row;
	char ch;

	while ((c = getchar()) != EOF) {
		counts[c - ' ']++;
	}

	printf("\n");
	for (ch=' ', row = 0; ch < LAST_CHAR; ch++, row++) {
		printf("%c:", ch);
		for (i = 0; i < counts[row]; i++) {
			putchar('*');
		}
		printf("\n");
	}
	return 0;
}
