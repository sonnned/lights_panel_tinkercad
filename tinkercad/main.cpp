#include <iostream>
#include "patterns.h"
#include "modify.h"

using namespace std;

int main()
{
    const int size = 8;
    int matrix[size][size];

    fill_matrix(matrix, size);

    print_led_matrix(matrix, size);
}
