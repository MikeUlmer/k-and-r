/*
 * Looked up solution after I figured out my own.
 * Enhancing it. Used a few more defines.
 * Accepts any user input but confines what is graphed.
 * 
 * Notes:
 * Didn't think to pick up max in the while loop. This was the main reason
 * I stuck with horizontal display in this & 1.13 exer.
 */ 
#include <stdio.h>

#define CHAR_SPAN 94
#define LAST_CHAR 127
#define FIRST_CHAR 32

int main() {
    int counts[CHAR_SPAN] = {0};
	int c,
		x,
		y,
		max = 0;
	char ch;

	while ((c = getchar()) != EOF) {
		if (c >= FIRST_CHAR && c < LAST_CHAR) { //Define span I care to graph
			counts[c - FIRST_CHAR]++;
			
			if (counts[c - FIRST_CHAR] > max) { // conditional needed for disp vertical later.
				max = counts[c - FIRST_CHAR];
			}
		}
	}
	
	for (x = max; x >= 0; x--) {
		for (y = 0; y < CHAR_SPAN; y++) {
			putchar(counts[y] > x ? '*' : ' ');
		}
		printf("\n");
	}
	
	for (x = FIRST_CHAR; x < LAST_CHAR; x++) {
		putchar('-');
	}
	printf("\n");
	for (x = FIRST_CHAR; x < LAST_CHAR; x++) {
		putchar(x);
	}
	printf("\n\n");
	return 0;
}
