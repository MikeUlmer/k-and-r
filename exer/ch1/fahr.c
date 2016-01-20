/*
Comprises exercises 1.3, 1.4 of K&R
*/
#include <stdio.h>
#include <stdbool.h>

#define START -40
#define STOP 300
#define STEP 5

int convertTemp(int op, bool fahrConv) {
    return fahrConv ? (5.0/9.0) * (op-32) : op * (9.0/5.0) + 32;
}

main() {
    int temp;
    printf("Temp Conversion Table\n");
    for(temp = START; temp <= STOP; temp+=STEP) {
        printf("F: %d\tC: %d\t\tC: %d\tF: %d\n", temp, convertTemp(temp, true), temp, convertTemp(temp,false));
    }
}
