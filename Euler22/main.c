#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "names.h"

// taken from qsort's man page
static int cmpstringp(const void *p1, const void *p2) {
    /* The actual arguments to this function are "pointers to
       pointers to char", but strcmp(3) arguments are "pointers
       to char", hence the following cast plus dereference */

    return strcmp(*(char *const *) p1, *(char *const *) p2);
}

static uint64_t alpha_value(const char *name, uint64_t size) {

    uint64_t value = 0;

    for (int i = 0; i < size; ++i) {
        const char c = name[i];
        unsigned char_value = c - 'A' + 1;
        value += char_value;
    }

    return value;
}

int main() {

    qsort(names, NUM_NAMES, sizeof(char *), cmpstringp);

    uint64_t sum = 0;
    for (int i = 0; i < NUM_NAMES; ++i) {

        const uint64_t value = alpha_value(names[i], strlen(names[i]));
        sum += (1 + i) * value;
    }

    printf("answer: %ld\n", sum);

    return 0;
}
