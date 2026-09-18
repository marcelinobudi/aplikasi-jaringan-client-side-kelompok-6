#include <stdint.h>
#include <stdbool.h>

/*
Menghitung nilai determinan matrix 3x3
*/
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


/*
Menghitung invers dari suatu matrix
jika fungsi mengembalikan -1 => error.
*/
int inverse_matrix(int32_t matrix[3][3], int32_t inversed[3][3]){
    return 0;
}


/*
Menentukan kesamaan matrix
*/
bool is_matrix_equal(int32_t matrix1[3][3], int32_t matrix2[3][3]) {
    return true;
}
