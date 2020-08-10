#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

static bool find_factors(uint64_t number, uint64_t max_num_primes, uint64_t *factors, uint64_t *num_factors);

int main() {

    uint64_t number = 600851475143;

    const uint64_t max_num_primes = 2000;
    uint64_t factors[max_num_primes];
    uint64_t num_factors;

    // the function called ignores 2 and 3!!! needs to be adapted for a general case
    bool found = find_factors(number, max_num_primes, factors, &num_factors);

    if (!found) {
        printf("Couldn't find the largest factor with %lu primes.\n", max_num_primes);
    } else {
        printf("factors: [ ");
        for (unsigned int i = 0; i < num_factors; ++i) {
            printf("%lu ", factors[i]);
        }
        printf("]\n");
    }
    return 0;
}

/**
 * Uses iterative sieve from Euler7. Look there for more info.
 *
 * @param number
 * @param max_num_primes
 * @param factors
 * @param num_factors
 * @return
 */
static bool find_factors(uint64_t number, uint64_t max_num_primes, uint64_t *factors, uint64_t *num_factors) {

    *num_factors = 0;

    uint64_t *primes = malloc(max_num_primes * sizeof(*primes));
    uint64_t *starting_mult = malloc(max_num_primes * sizeof(*starting_mult));

    primes[0] = 2;
    starting_mult[0] = 4;
    primes[1] = 3;
    starting_mult[1] = 9;

    unsigned int num_primes = 2;

    for (unsigned int x = 5; num_primes < max_num_primes; ++x) {

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

            if (number % x == 0) {
                number /= x;
                factors[*num_factors] = x;
                *num_factors += 1;

                if (number == 1) {

                    return true;
                }
            }
        }
    }

    return false;
}