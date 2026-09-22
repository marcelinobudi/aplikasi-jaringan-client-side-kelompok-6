#include <stdio.h>
#include <stdbool.h>

//menghitung nilai determinan matrix
double determinan(double matrix[3][3]) {
    double result = 0.0;

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
int inverse_matrix(double matrix[3][3], double inversed[3][3]) {
    double det = determinan(matrix);

    /* Matrix tidak memiliki invers */
    if (det == 0.0) {
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
bool is_matrix_equal(double matrix1[3][3], double matrix2[3][3]) {
    double epsilon = 0.000001;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (fabs(matrix1[i][j] - matrix2[i][j]) > epsilon) {
                return false;
            }
        }
    }

    return true;
}
