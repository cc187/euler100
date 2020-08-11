#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

int main() {

    uint64_t prime_limit = 2000000;

    uint64_t sum = 0;

    uint64_t *primes = malloc(prime_limit * sizeof(*primes));
    uint64_t *starting_mult = malloc(prime_limit * sizeof(*starting_mult));

    primes[0] = 2;
    starting_mult[0] = 4;
    primes[1] = 3;
    starting_mult[1] = 9;

    sum += 2 + 3; // adding the first 2 primes, the rest are added in the loop

    unsigned int num_primes = 2;

    for (unsigned int n = 6; n-1 < prime_limit; n += 6) {

        unsigned int x = n-1;

        uint64_t limit = sqrt(x) + 1;
        bool is_prime = true;

        for (unsigned int p = 0; p < num_primes; ++p) {

            uint64_t prime = primes[p];
            if (prime > limit) {
                break;
            }

            uint64_t mult = starting_mult[p];
            while (mult < x) {
                mult += prime;
            }

            if (mult == x) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {

            primes[num_primes] = x;
            starting_mult[num_primes] = x * x;
            num_primes += 1;

            sum += x;
        }

        x = n+1;

        limit = sqrt(x) + 1;
        is_prime = true;

        for (unsigned int p = 0; p < num_primes; ++p) {

            uint64_t prime = primes[p];
            if (prime > limit) {
                break;
            }

            uint64_t mult = starting_mult[p];
            while (mult < x) {
                mult += prime;
            }

            if (mult == x) {
                is_prime = false;
                break;
            }
        }

        if (is_prime) {

            primes[num_primes] = x;
            starting_mult[num_primes] = x * x;
            num_primes += 1;

            sum += x;
        }
    }

    printf("sum: %lu\n", sum);

    return 0;
}
