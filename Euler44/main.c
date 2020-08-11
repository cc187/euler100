#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LIMIT 10000lu
#define MAP_LIMIT 150000000lu

void find_pentagonals(uint64_t *pentagonals, bool *is_pentagonal);

int main() {

    // find the first pentagonal numbers up to the limit
    uint64_t pentagonals[LIMIT];
    bool *is_pentagonal = malloc(MAP_LIMIT * sizeof(*is_pentagonal));
    if (is_pentagonal == NULL) {
        printf("Could not allocate memory for is_pentagonal.");
        return 1;
    }
    for (unsigned int i = 0; i < MAP_LIMIT; ++i) {
        is_pentagonal[i] = false;
    }
    find_pentagonals(pentagonals, is_pentagonal);

    // test numbers whose difference is p_1, then p_2, then p_3, ...
    for (unsigned int i = 0; i < LIMIT; ++i) {

        uint64_t diff = pentagonals[i];

        for (unsigned int p = 0; p < LIMIT; ++p) {

            uint64_t current_pentagonal = pentagonals[p];

            uint64_t candidate = current_pentagonal + diff;

            // needed not to segfault
            if(candidate > MAP_LIMIT) {
                break;
            }

            if(!is_pentagonal[candidate]) {
                continue;
            }

            uint64_t sum = current_pentagonal + candidate;

            // needed not to segfault
            if(sum > MAP_LIMIT) {
                break;
            }

            if(is_pentagonal[sum]) {

                printf("Found pair: <%lu, %lu>\nDifference: %lu\n", current_pentagonal, candidate, diff);
                return 0;
            }
        }
    }

    printf("Could not find pair with %lu pentagonal numbers. Last pentagonal number found: %lu.\n", LIMIT,
           pentagonals[LIMIT - 1]);
    return 0;
}

void find_pentagonals(uint64_t *pentagonals, bool *is_pentagonal) {

    uint64_t num_pent = 0;

    // pentagonal variables
    uint64_t p = 0;
    uint64_t p_inc = 1;
    uint64_t p_inc_inc = 3;

    while (num_pent < LIMIT) {

        p += p_inc;
        p_inc += p_inc_inc;

        pentagonals[num_pent] = p;
        is_pentagonal[p] = true;

        num_pent += 1;
    }
}
