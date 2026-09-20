#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tampilkan_menu() {
    printf("\n=== APLIKASI CLIENT JARINGAN ===\n");
    printf("1. Hitung Jumlah Karakter\n");
    printf("2. Hitung Jumlah Kata\n");
    printf("3. Balikkan String\n");
    printf("4. Hapus Huruf Vokal\n");
    printf("5. Hitung Determinan & Invers Matriks (3x3)\n");
    printf("0. Keluar\n");
    printf("Pilih layanan (0-5): ");
}
int main() {
    int pilihan;
    char input_string[256];
    double matrix[3][3];
    while (1) {
        tampilkan_menu();
        if (scanf("%d", &pilihan) != 1) break;
        getchar(); 

        if (pilihan == 0) {
            printf("Keluar dari program.\n");
            break;
        }
        switch (pilihan) {
            case 1:
            case 2:
            case 3:
            case 4:
                printf("Masukkan string/teks: ");
                fgets(input_string, sizeof(input_string), stdin);
                input_string[strcspn(input_string, "\n")] = 0; 
                
                printf("\n[SISTEM] Mengirim data ke server: \"%s\"\n", input_string);
                break;
            case 5:
                printf("Masukkan 9 elemen matriks 3x3 (pisahkan dengan spasi/enter):\n");
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        scanf("%lf", &matrix[i][j]);
                    }
                }
                printf("\n[SISTEM] Mengirim Matriks 3x3 ke server...\n");
                break;

            default:
                printf("Pilihan tidak valid, coba lagi.\n");
        }
    }
    return 0;
}
