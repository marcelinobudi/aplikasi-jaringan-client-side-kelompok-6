#ifndef MATRIX_H
#define MATRIX_H
#include <stdint.h>
int32_t determinan(int32_t matrix[3][3]);
int inverse_matrix(int32_t matrix[3][3], int32_t inversed[3][3]);
bool is_matrix_equal(int32_t matrix1[3][3], int32_t matrix2[3][3]);
#endif 