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

void create_second_pattern(int (*matrix)[8], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                matrix[i][j] = 1;
                matrix[i][size - j - 1] = 1;
            }
        }
    }
}

void create_fourth_pattern(int (*matrix)[8], int size) {
    int decreaser = 3;

    for (int i = 0; i < size; i++) {
        int counter = 4;
        for (int j = 0; j < size; j++) {
            if (i < size / 2) {
                if (i == j) {
                    matrix[i][j] = 1;
                } else if ((counter > 1) && (j > i)) {
                    matrix[i][j] = 1;
                    counter--;
                } else {
                    matrix[i][j] = 0;
                }
            } else {
                if (j + i == size - 1) {
                    matrix[i][j] = 1;
                } else if ((counter > 1) && (j >= decreaser)) {
                    matrix[i][j] = 1;
                    counter--;
                } else {
                    matrix[i][j] = 0;
                }
            }
        }
        if (i >= size / 2) {
            decreaser--;
        }
    }
}
