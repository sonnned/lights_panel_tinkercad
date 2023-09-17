#include <iostream>
#include "patterns.h"

using namespace std;

void print_led_matrix(int (*matrix)[8], int size);
void fill_matrix(int (*matrix)[8], int size);

void print_led_matrix(int (*matrix)[8], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void fill_matrix(int (*matrix)[8], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = 0;
        }
    }
}

int main()
{
    const int size = 8;
    int matrix[size][size];

    fill_matrix(matrix, size);

    create_first_pattern(matrix, size);


    print_led_matrix(matrix, size);
}
