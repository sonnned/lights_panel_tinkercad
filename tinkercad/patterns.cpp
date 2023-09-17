#include <iostream>

using namespace std;

void create_first_pattern(int (*matrix)[8], int size) {
    int half = size / 2;

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < size; j++) {
            if ((j < (half - i - 1)) || (j > (half + i))) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = 1;
            }
        }
    }

    for (int i = half; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((j < (i - half)) || (j >= (size - (i - half)))) {
                matrix[i][j] = 0;
            } else {
                matrix[i][j] = 1;
            }
        }
    }
}
