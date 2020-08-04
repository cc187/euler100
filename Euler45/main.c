#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

uint64_t triangle(uint64_t n);

uint64_t pentagonal(uint64_t n);

uint64_t hexagonal(uint64_t n);

void triangle_inc_test();

void pentagonal_inc_test();

void hexagonal_inc_test();

uint64_t calc();

uint64_t calc2();

int main() {

    const int num_iters = 100000;
    uint64_t res = -1;
    struct timeval start, end;

    gettimeofday(&start, NULL);
    for (int i = 0; i < num_iters; ++i) {
        res = calc2();
    }
    gettimeofday(&end, NULL);
    uint64_t seconds = end.tv_sec - start.tv_sec;
    uint64_t ms = end.tv_usec - start.tv_usec;
    uint64_t total_time_spent_ms = seconds * 1000000 + ms;
    double time_spent_ms = 1.0 * total_time_spent_ms / num_iters;
    printf("time:   %fms\n", time_spent_ms);

    printf("answer: 1533776805\nnumber: %ld\n", res);

    return 0;
}

// calculate next h
// calculate next p that is >= than h
// if p = h
// calculate next t that is >= than p
// if t = n
// then return t
// else go back to outer loop
// else go back to outer loop
uint64_t calc() {

    uint64_t n_t = 285;
    uint64_t n_p = 165;
    uint64_t n_h = 143;


    while (1) {

        n_h += 1;
        uint64_t h = hexagonal(n_h);

        n_p += 1;
        uint64_t p = pentagonal(n_p);
        while (p < h) {
            n_p += 1;
            p = pentagonal(n_p);
        }
        if (p == h) {

            n_t += 1;
            uint64_t t = triangle(n_t);
            while (t < p) {
                n_t += 1;
                t = triangle(n_t);
            }
            if (t == p) {

                return t;
            }
        }
    }
}

uint64_t calc2() {

    // hexagonal variables
    uint64_t h = 0;
    uint64_t h_inc = 1;
    uint64_t h_inc_inc = 4;

    // pentagonal variables
    uint64_t p = 0;
    uint64_t p_inc = 1;
    uint64_t p_inc_inc = 3;

    // triangle variables
    uint64_t t = 0;
    uint64_t t_inc = 1;
    uint64_t t_inc_inc = 1;

    while (1) {

        // calc next h
        h += h_inc;
        h_inc += h_inc_inc;

        // calculate next p that is >= than h
        p += p_inc;
        p_inc += p_inc_inc;
        while (p < h) {
            p += p_inc;
            p_inc += p_inc_inc;
        }

        // if p = h
        if (p == h) {

            // calculate next t that is >= than p
            t += t_inc;
            t_inc += t_inc_inc;
            while (t < p) {
                t += t_inc;
                t_inc += t_inc_inc;
            }

            // if t = p = h, we found our number, otherwise continue to the next h
            if (t == p && t > 40755) {

                return t;
            }
        }
    }
}

void triangle_inc_test() {

    uint64_t t = 0;
    uint64_t t_inc = 1;
    uint64_t t_inc_inc = 1;

    for (int n = 1; n < 1000; ++n) {

        t += t_inc;
        t_inc += t_inc_inc;

        printf("f: %lu\tt: %lu\n", triangle(n), t);
    }
}

void pentagonal_inc_test() {

    uint64_t p = 0;
    uint64_t p_inc = 1;
    uint64_t p_inc_inc = 3;

    for (int n = 1; n < 1000; ++n) {

        p += p_inc;
        p_inc += p_inc_inc;

        printf("f: %lu\tp: %lu\n", pentagonal(n), p);
    }
}

void hexagonal_inc_test() {

    uint64_t h = 0;
    uint64_t h_inc = 1;
    uint64_t h_inc_inc = 4;

    for (int n = 1; n < 1000; ++n) {

        h += h_inc;
        h_inc += h_inc_inc;

        printf("f: %lu\th: %lu\n", hexagonal(n), h);
    }
}

uint64_t triangle(uint64_t n) {

    return n * (n + 1) / 2;
}

uint64_t pentagonal(uint64_t n) {

    return n * (3 * n - 1) / 2;
}

uint64_t hexagonal(uint64_t n) {

    return n * (2 * n - 1);
}