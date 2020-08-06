#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static inline bool is_abundant(unsigned int n);

unsigned int sum_divisors(unsigned int n);

bool is_sum_of_abundants(unsigned int N, const unsigned int *abundants, unsigned int num_abundants);

/**
 *
 * 1) find all abundant numbers from 12 to 28123
 * 2) iterate from N=1 to 28123 and find if each number can be a sum of abundants
 *      iterate the list of abundants and subtract from from N, checking if the difference if abundant
 *      if it is, N can be expressed as a sum of two abundants
 *      it it's not, sum
 *
 *
 * @return
 */
int main() {

    // sorted list of abundants
    unsigned int abundants[7000];
    unsigned int num_abundants = 0;

    for (unsigned int i = 12; i < 28123; ++i) {
        if (is_abundant(i)) {
            abundants[num_abundants] = i;
            num_abundants += 1;
        }
    }

    unsigned int sum = 0;
    for (unsigned int N = 1; N <= 28123; ++N) {

        if(!is_sum_of_abundants(N, abundants, num_abundants)) {
            sum += N;
        }
    }

    printf("answer: %d\n", sum);

    return 0;
}

bool is_sum_of_abundants(unsigned int N, const unsigned int *abundants, unsigned int num_abundants) {

    for (unsigned int a = 0; a < num_abundants; ++a) {

        const unsigned int abundant = abundants[a];

        if (N <= abundant) {
            return false;
        }

        unsigned int diff = N - abundant;
        if (is_abundant(diff)) {

//            printf("%d = %d + %d\n", N, abundant, diff);
            return true;
        }
    }

    return false;
}

unsigned int sum_divisors(unsigned int n) {

    // 1 is always a divisor, so we start with sum=1 and the loop at 2
    unsigned int sum = 1;

    // there's a max of n/2 dividers
    for (unsigned int i = 2; i <= n / 2; ++i) {

        if (n % i == 0) {

            sum += i;
        }
    }

    return sum;
}

static inline bool is_abundant(unsigned int n) {

    return sum_divisors(n) > n;
}