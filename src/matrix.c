#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#define BUFFER_SIZE 1024

nye nye nye 

//input matrix 3x3 bagi client
printf("Masukkan matrix 3x3: \n");
for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
        printf("M[%d][%d] = ", i + 1, j + 1);
        scanf("%lf", &matrix[i][j]);
    }
}

//menampilkan matrix
void printMatrix(double matrix[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%8.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

//menghitung nilai determinan matrix 
//sebagai pembanding hasil dari server
double determinant(double matrix [3][3]) {
    return
        matrix[0][0] * (matrix[1][1] * matrix[2][2] -
                        matrix[1][2] * matrix[2][1])
      - matrix[0][1] * (matrix[1][0] * matrix[2][2] -
                        matrix[1][2] * matrix[2][0])
      + matrix[0][2] * (matrix[1][0] * matrix[2][1] -
                        matrix[1][1] * matrix[2][0]);
}

//menghitung invers matrix
//sebagai pembanding hasil dari server
int inverseMatrix(double matrix[3][3], double inverse[3][3]){
    double det = determinant(matrix);
    if (det == 0) {
        return 0;
    }
    inverse[0][0] =
        (matrix[1][1] * matrix[2][2] -
         matrix[1][2] * matrix[2][1]) / det;

    inverse[0][1] =
        (matrix[0][2] * matrix[2][1] -
         matrix[0][1] * matrix[2][2]) / det;

    inverse[0][2] =
        (matrix[0][1] * matrix[1][2] -
         matrix[0][2] * matrix[1][1]) / det;

    inverse[1][0] =
        (matrix[1][2] * matrix[2][0] -
         matrix[1][0] * matrix[2][2]) / det;

    inverse[1][1] =
        (matrix[0][0] * matrix[2][2] -
         matrix[0][2] * matrix[2][0]) / det;

    inverse[1][2] =
        (matrix[0][2] * matrix[1][0] -
         matrix[0][0] * matrix[1][2]) / det;

    inverse[2][0] =
        (matrix[1][0] * matrix[2][1] -
         matrix[1][1] * matrix[2][0]) / det;

    inverse[2][1] =
        (matrix[0][1] * matrix[2][0] -
         matrix[0][0] * matrix[2][1]) / det;

    inverse[2][2] =
        (matrix[0][0] * matrix[1][1] -
         matrix[0][1] * matrix[1][0]) / det;
    return 1;
}


//mengirim matrix ke server
send(clientSocket, (char*)matrix, sizeof(matrix),0);
printf("\nMatriks berhasil dikirim ke server\n");
printf("Menunggu hasil dari server...\n");

//menerima hasil dari server dan memeriksa determinan
int bytesReceived = recv(clientSocket, result, BUFFER_SIZE - 1,0);
if (bytesReceived>0) {
    result[bytesReceived] = '\0';

    printf("\n===== HASIL DARI SERVER =====\n");
    printf("%s\n", result);

} else {
    printf("\nTidak menerima hasil dari server.\n");
}


/*
Menghitung nilai determinan matrix 3x3
*/
int32_t determinan(int32_t matrix[3][3]){
    int32_t result = 0;
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
