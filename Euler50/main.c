#include "primes.h"

#include <stdio.h>
#include <stdint.h>

#define PRIME_LIMIT 1000000

int main() {

    // find primes below 1000000
    unsigned int primes[PRIME_LIMIT];
    char prime_map[PRIME_LIMIT];
    unsigned int num_primes = primes_up_to_and_map(primes, prime_map, PRIME_LIMIT);
    printf("primes found: %u\nlast prime: %u\n", num_primes, primes[num_primes - 1]);

    unsigned int longest_sum = 0;
    unsigned int sum = 0;

    for (unsigned int i = 0; i < num_primes; ++i) {

        unsigned int candidate_sum = primes[i];
        unsigned int primes_used = 1;

        for (unsigned int j = i + 1; j < num_primes; ++j) {

            candidate_sum += primes[j];
            primes_used += 1;

            // stop the current search if the sum is greater than the limit
            // move to the next starting point
            if (candidate_sum > PRIME_LIMIT) {
                break;
            }

            if (candidate_sum > 1000 &&
                primes_used > 1 &&
                prime_map[candidate_sum]) {

                if(primes_used > longest_sum) {

                    longest_sum = primes_used;
                    sum = candidate_sum;
                }
            }
        }
    }

    printf("sum: %u, primes used: %u\n", sum, longest_sum);

    return 0;
}
