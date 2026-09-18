#include <stdio.h>
#include <stdbool.h>

//menghitung nilai determinan matrix
int32_t determinan(int32_t matrix[3][3]) {
    int32_t result = 0;

    result =
        matrix[0][0] * (
            matrix[1][1] * matrix[2][2] -
            matrix[1][2] * matrix[2][1]
        )
        - matrix[0][1] * (
            matrix[1][0] * matrix[2][2] -
            matrix[1][2] * matrix[2][0]
        )
        + matrix[0][2] * (
            matrix[1][0] * matrix[2][1] -
            matrix[1][1] * matrix[2][0]
        );

    return result;
}

//Menghitung invers dari suatu matrix 
//jika fungsi mengembalikan -1 => error.
int inverse_matrix(int32_t matrix[3][3], int32_t inversed[3][3]) {
    int32_t det = determinan(matrix);

    /* Matrix tidak memiliki invers */
    if (det == 0) {
        return -1;
    }

    inversed[0][0] =
        (matrix[1][1] * matrix[2][2] -
         matrix[1][2] * matrix[2][1]) / det;

    inversed[0][1] =
        (matrix[0][2] * matrix[2][1] -
         matrix[0][1] * matrix[2][2]) / det;

    inversed[0][2] =
        (matrix[0][1] * matrix[1][2] -
         matrix[0][2] * matrix[1][1]) / det;

    inversed[1][0] =
        (matrix[1][2] * matrix[2][0] -
         matrix[1][0] * matrix[2][2]) / det;

    inversed[1][1] =
        (matrix[0][0] * matrix[2][2] -
         matrix[0][2] * matrix[2][0]) / det;

    inversed[1][2] =
        (matrix[0][2] * matrix[1][0] -
         matrix[0][0] * matrix[1][2]) / det;

    inversed[2][0] =
        (matrix[1][0] * matrix[2][1] -
         matrix[1][1] * matrix[2][0]) / det;

    inversed[2][1] =
        (matrix[0][1] * matrix[2][0] -
         matrix[0][0] * matrix[2][1]) / det;

    inversed[2][2] =
        (matrix[0][0] * matrix[1][1] -
         matrix[0][1] * matrix[1][0]) / det;

    return 0;
}

//menentukan kesaaan matrix dari hasil server
bool is_matrix_equal(int32_t matrix1[3][3], int32_t matrix2[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return false;
            }
        }
    }

    return true;
}
