#include "primes.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

unsigned int primes_up_to(unsigned int *primes, unsigned int limit) {

    unsigned int *starting_mult = malloc(limit * sizeof(*starting_mult));

    primes[0] = 2;
    starting_mult[0] = 4;
    primes[1] = 3;
    starting_mult[1] = 9;
    unsigned int num_primes = 2;

    for (unsigned int x = 5; x <= limit; ++x) {

        unsigned int upper_bound = (unsigned int) sqrt(x) + 1;
        bool is_prime = true;

        for (unsigned int p = 0; p < num_primes; ++p) {

            unsigned int prime = primes[p];
            if (prime > upper_bound) {
                break;
            }

            unsigned int mult = starting_mult[p];
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

    return num_primes;
}

unsigned int primes_up_to_and_map(unsigned int *primes, char *prime_map, unsigned int limit) {

    for (unsigned int i = 0; i < limit; ++i) {
        prime_map[i] = 0;
    }

    unsigned int *starting_mult = malloc(limit * sizeof(*starting_mult));

    primes[0] = 2;
    starting_mult[0] = 4;
    primes[1] = 3;
    starting_mult[1] = 9;
    unsigned int num_primes = 2;

    for (unsigned int x = 5; x <= limit; ++x) {

        unsigned int upper_bound = (unsigned int) sqrt(x) + 1;
        bool is_prime = true;

        for (unsigned int p = 0; p < num_primes; ++p) {

            unsigned int prime = primes[p];
            if (prime > upper_bound) {
                break;
            }

            unsigned int mult = starting_mult[p];
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

            prime_map[x] = 1;
        }
    }

    return num_primes;
}
