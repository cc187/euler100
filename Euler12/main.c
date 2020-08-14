#include <stdio.h>
#include <math.h>

#define LIMIT 100000000

unsigned int find_num_divisors(unsigned int number);

int main() {

    unsigned int inc = 1;
    unsigned int triangle = 0;
    while (triangle < LIMIT) {

        triangle += inc;
        inc += 1;

        if (triangle < 10000000) {
            continue;
        }

        unsigned int num_divisors = find_num_divisors(triangle);

        if (num_divisors > 500) {

            printf("triangle: %u, divisors: %u\n", triangle, num_divisors);
            return 0;
        }
    }

    printf("Couldn't find number with more than 500 divisors up to %u.\n", LIMIT);
    return 0;
}

/**
 * Fails for number == 1.
 *
 * @param number
 * @return
 */
unsigned int find_num_divisors(unsigned int number) {

    unsigned int num_divisors = 2; // 1 and itself
    unsigned int step = 2;
    unsigned int start = 3;

    if (number % 2 == 0) {

        step = 1;
        start = 2;
    }

    unsigned int i;
    for (i = start; i < sqrt(number); i += step) {

        if (number % i == 0) {

            num_divisors += 2; // both i and number/i are divisors
        }
    }

    if (1.0 * i == sqrt(number)) {
        num_divisors += 1; // add only once
    }

    return num_divisors;
}