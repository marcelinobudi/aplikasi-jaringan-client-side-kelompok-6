#ifndef MATRIX_H
#define MATRIX_H
#include <stdint.h>
double determinan(double matrix[3][3]);
int inverse_matrix(double matrix[3][3], double inversed[3][3]);
bool is_matrix_equal(double matrix1[3][3], double matrix2[3][3]);
#endif 