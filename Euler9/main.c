#include <stdio.h>

int main() {

    for (int a = 1; a < 1000; ++a) {

        for (int b = a + 1; b < 1000; ++b) {


            for (int c = b + 1; c < 1000; ++c) {

                if (a * a + b * b == c * c) {

                    if (a + b + c == 1000) {

                        printf("%d %d %d\n", a, b, c);
                        printf("product: %d\n", a * b * c);
                        return 0;
                    }
                }
            }
        }
    }

    printf("Couldn't find the triplet\n");
    return 0;
}
