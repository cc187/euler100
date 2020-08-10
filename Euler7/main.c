#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

static uint64_t get_nth_prime(unsigned int n);

int main() {

    for (int n = 1; n <= 10; ++n) {

        printf("%uth prime: %lu\n", n, get_nth_prime(n));
    }

    printf("%uth prime: %lu\n", 10001, get_nth_prime(10001));
    return 0;
}

/**
 *
 * Produces the nth prime: 1st: 2, 2nd: 3, 3rd: 5, 4th: 7, 5th: 11, 6th: 13, ...
 *
 * Based on https://www.codevamping.com/2019/01/incremental-sieve-of-eratosthenes/
 *
 * @param n the index of the prime, with n >= 1
 * @return
 */
uint64_t get_nth_prime(unsigned int n) {

    uint64_t *primes = malloc(n * sizeof(*primes));
    uint64_t *starting_mult = malloc(n * sizeof(*starting_mult));

    primes[0] = 2;
    starting_mult[0] = 4;
    primes[1] = 3;
    starting_mult[1] = 9;

    unsigned int num_primes = 2;

    for (unsigned int x = 5; num_primes < n; ++x) {

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
        }
    }

    return primes[n - 1];
}