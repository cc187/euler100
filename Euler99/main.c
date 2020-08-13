#include <stdio.h>
#include <math.h>

int compare(double b1, double e1, double b2, double e2);

int main() {

    char *file_name = "../p099_base_exp.txt";

    double largest_base = 0;
    double largest_exp = 0;
    unsigned int largest_line = 0;
    unsigned int current_line = 0;

    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {

        printf("Couldn't open file %s.\n", file_name);
        return 1;
    }

    char *line = NULL;
    size_t len = 0;
    while (getline(&line, &len, fp) != -1) {

        current_line += 1;
        double current_base;
        double current_exp;

        // conversions may fail without error
        sscanf(line, "%lf,%lf", &current_base, &current_exp);

        if (compare(largest_base, largest_exp, current_base, current_exp) == 1) {
            largest_base = current_base;
            largest_exp = current_exp;
            largest_line = current_line;
        }
    }


    printf("line: %d\n", largest_line);

    printf("compare 2^5 and 2^7: %d\n", compare(2, 5, 2, 5));

    return 0;
}

/**
 * Compares two numbers of the form b1^e1 and b2^e2.
 * Based on https://math.stackexchange.com/a/1329636
 *
 * @param b1 the base component for the first number
 * @param e1 the exponent component for the first number
 * @param b2 the base component for the second number
 * @param e2 the exponent component for the second number
 *
 * @return -1 if the first number is greater, 1 if the second number is greater, 0 if the numbers are equal
 */
int compare(double b1, double e1, double b2, double e2) {

    if (b1 > b2 && e1 > e2) {

        return -1;
    }

    if (b1 < b2 && e1 < e2) {

        return 1;
    }

    if (b1 > b2) {

        b1 = b1 / b2;
        e2 = fabs(e1 - e2);

        return compare(b1, e1, b2, e2);
    } else if (b2 > b1) {

        e1 = fabs(e1 - e2);
        b2 = b2 / b1;

        return compare(b1, e1, b2, e2);
    } else {

        // bases are equal, compare exponents
        if (e1 > e2) {
            return -1;
        } else if (e2 > e1) {
            return 1;
        } else {
            return 0;
        }
    }
}
