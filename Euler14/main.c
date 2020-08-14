#include <stdio.h>

unsigned int get_collatz_length(unsigned int n);

int main() {

    unsigned int max_length = 0;
    unsigned int number = 0;

    for (int i = 1; i < 1000000; ++i) {

        unsigned  int length = get_collatz_length(i);
        if (length > max_length) {
            max_length = length;
            number = i;
        }
    }

    printf("max collatz length: %u, number: %u\n", max_length, number);
    return 0;
}

// this entire thing can be optimized to use memoization
unsigned int get_collatz_length(unsigned int n) {

    unsigned int length = 1; // the number itself

    while (n != 1) {

        length += 1;

        if (n % 2 == 0) {// this branch can be optimized to consider powers of 2

            n = n / 2;
        } else {

            n = 3 * n + 1;
        }
    }

    return length;
}
