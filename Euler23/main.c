#include <stdio.h>
#include <stdbool.h>

static inline bool is_abundant(unsigned int n);

static unsigned int sum_divisors(unsigned int n);

static void find_soa(
        const unsigned int *abundants,
        unsigned int num_abundants,
        bool *soa_map);

static unsigned int find_abundants(unsigned int *abundants);

static unsigned int sum_non_soa(const bool *soa_map);

int main() {

    // 1) find abundants
    unsigned int abundants[7000];
    unsigned int num_abundants = find_abundants(abundants);

    // 2) find all sums of abundants (soa) up to 28123
    // this maps each number to whether it is a soa
    bool soa_map[28124] = {false};
    find_soa(abundants, num_abundants, soa_map);

    // 3) iterate up to 28123 and sum non-soa
    unsigned int sum = sum_non_soa(soa_map);

    printf("answer:   %d\nsolution: %d\n", sum, 4179871);

    return 0;
}

static unsigned int find_abundants(unsigned int *abundants) {

    unsigned int num_abundants = 0;

    for (unsigned int i = 12; i < 28123; ++i) {
        if (is_abundant(i)) {
            abundants[num_abundants] = i;
            num_abundants += 1;
        }
    }

    return num_abundants;
}

static void find_soa(
        const unsigned int *abundants,
        const unsigned int num_abundants,
        bool *soa_map) {

    for (unsigned int i = 0; i < num_abundants - 1; ++i) {

        const unsigned int a1 = abundants[i];

        for (unsigned int j = i + 1; j < num_abundants; ++j) {

            const unsigned int a2 = abundants[j];
            const unsigned int soa = a1 + a2;

            if (soa > 28123) {

                break;
            }

            soa_map[soa] = true;
        }
    }
}

static unsigned int sum_non_soa(const bool *soa_map) {

    unsigned int sum = 0;

    for (unsigned int i = 0; i <= 28123; ++i) {

        if (soa_map[i] != 1) {
            sum += i;
        }
    }

    return sum;
}

static bool is_abundant(const unsigned int n) {

    return sum_divisors(n) > n;
}

static unsigned int sum_divisors(const unsigned int n) {

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
