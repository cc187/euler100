#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAMES C(NAIVE)C(ITER)C(ITER3)
#define C(x) x,
typedef enum {
    NAMES KERNEL_KIND_TOTAL, UNDEFINED
} kernel_kind;
#undef C
#define C(x) #x,
const char *const kernel_kind_names[] = {NAMES};
#undef C

typedef unsigned int (*kernel)(void);

kernel get_chosen_kernel(int argc, char **argv);

unsigned int naive();

unsigned int iterating();

unsigned int iterating_three_numbers();

int main(int argc, char **argv) {

    kernel chosen_kernel = NULL;
    unsigned int sum;
    const unsigned int expected = 4613732;

    chosen_kernel = get_chosen_kernel(argc, argv);

    for (unsigned int i = 0; i < 100000000; ++i) {
        sum = chosen_kernel();
    }

    printf("expected: %d\nresult:   %d\n", expected, sum);

    return 0;
}

unsigned int iterating() {

    unsigned int sum = 2; // starting with 2 since the 'current' value starts at 3

    unsigned int previous_one = 2;
    unsigned int previous_two = 1;
    unsigned int current = previous_one + previous_two;

    while (current < 4000000) {

        if (current % 2 == 0) {
            sum += current;
        }

        previous_two = previous_one;
        previous_one = current;
        current = previous_one + previous_two;
    }

    return sum;
}

// only every third number is even
unsigned int iterating_three_numbers() {

    unsigned int sum = 2; // starting with 2 since the 'current' value starts at 3

    unsigned int previous_two = 1;
    unsigned int previous_one = 2;
    unsigned int current;

    while (1) {

        current = previous_one + previous_two;
        previous_two = previous_one;
        previous_one = current;

        current = previous_one + previous_two;
        previous_two = previous_one;
        previous_one = current;

        current = previous_one + previous_two;
        previous_two = previous_one;
        previous_one = current;

        // only the third sum produces a new even number, so we test here if the value is still less than 4m
        if (current >= 4000000) break;
        sum += current;
    }

    return sum;
}

unsigned int naive() {

    return 0;
}

void print_kernel_kind_values() {
    for (int i = 0; i < KERNEL_KIND_TOTAL; ++i) {
        printf("%s ", kernel_kind_names[i]);
    }
    printf("\n");
}

kernel get_chosen_kernel(int argc, char **argv) {

    if(argc == 1) {
        printf("Need the kind of kernel to run. Possible values:\n");
        print_kernel_kind_values();
        exit(1);
    }

    kernel_kind k = ITER;
    for (int i = 0; i < KERNEL_KIND_TOTAL; ++i) {

        if(0 == strcmp(argv[1], kernel_kind_names[i])) {

            k = i;
        }
    }

    if(k == UNDEFINED) {
        printf("Cannot recognize kernel kind %s. Possible values:\n", argv[1]);
        print_kernel_kind_values();
        exit(1);
    }

    kernel chosen_kernel = NULL;
    switch (k) {

        case NAIVE:
            chosen_kernel = naive;
            break;
        case ITER:
            chosen_kernel = iterating;
            break;
        case ITER3:
            chosen_kernel = iterating_three_numbers;
            break;
        default:
            chosen_kernel = naive;
            break;
    }

    printf("running kernel %s\n", kernel_kind_names[k]);

    return chosen_kernel;
}