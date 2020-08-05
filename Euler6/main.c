#include <stdio.h>
#include <stdint.h>

int main() {

    int64_t sum_of_squares = 0;
    int64_t square_of_sums = 0;

    for (int i = 1; i <= 100; ++i) {

        sum_of_squares += i * i;
        square_of_sums += i;
    }
    square_of_sums *= square_of_sums;

    printf("sum_of_squares: %lu\n", sum_of_squares);
    printf("square_of_sums: %lu\n", square_of_sums);
    printf("answer: %ld\n", square_of_sums - sum_of_squares);
    return 0;
}
