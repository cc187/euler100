#include <stdio.h>
#include <stdbool.h>

int main() {

    // 20, 10, 2
    // 19
    // 18, 9, 6, 3, 2
    // 17
    // 16, 8, 2
    // 15, 5, 3
    // 14, 7, 2
    // 13
    // 12, 6, 4, 3, 2
    // 11
    int dividers[10] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11};

    unsigned int answer = 2520;

    while (1) {

        answer++;
        bool found = true;
        for (int i = 0; i < 10; ++i) {

            if (answer % dividers[i] != 0) {
                found = false;
                break;
            }
        }

        if (found) {
            break;
        }
    }

    printf("answer: %d\n", answer);
    return 0;
}
