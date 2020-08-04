#include <stdio.h>

int main() {

    unsigned int sum = 0;
    unsigned int three = 3;
    unsigned int five = 5;

    while(three < 1000) {

        sum += three;
        three += 3;
    }

    while(five < 1000) {

        if(five % 3 != 0) {
            // only sum if this multiple of 5 is also not a multiple of 3
            sum += five;
        }

        five += 5;
    }

    printf("sum: %d\n", sum);
    return 0;
}
