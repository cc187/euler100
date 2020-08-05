#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(unsigned int number) {

    char str[7];
    int size = sprintf(str, "%d", number);

    const int half_size = size / 2;
    for (int i = 0; i < half_size; ++i) {

        const char i1 = str[i];
        const char i2 = str[size - i - 1];
        if (i1 != i2) {
            return false;
        }
    }

    return true;
}

int main() {

    unsigned int largest_palindrome = 0;

    for (int i = 100; i <= 999; ++i) {
        for (int j = 100; j <= 999; ++j) {

            unsigned int product = i * j;
            if (is_palindrome(product)) {

                if (product > largest_palindrome) {
                    largest_palindrome = product;
                }
            }
        }
    }

    printf("answer: %d\n", largest_palindrome);

    return 0;
}
