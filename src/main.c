#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "client_networks/server_service.h"
#include "client_networks/client_socket.h"
#include "client_networks/stringx.h"
#include "client_networks/matrix.h"

enum ServerService {
    CHARACTER_COUNT = '1',
    WORD_COUNT,
    REVERSE_STRING,
    STRING_WITHOUT_VOWELS,
    DETERMINAN_AND_INVERSE_MATRIX
};
bool is_service_available(server_service *service, char *service_name) {
    char *service_availibility = "INACTIVE";
    service_availibility_check(service, service_name, service_availibility);
    return (strcmp(service_availibility, "ACTIVE") == 0);
}
void character_count(server_service *service) {
    if(!is_service_available(service, "CHARACTER_COUNT")) {
        printf("Layanana CHARACTER_COUNT tidak aktif");
        return;
    }

    char text[BUFFER_SIZE-10]; // "10 char reserved for 'REQUEST ' and the rest for safety"
    printf("input string: ");
    fgets(text, sizeof(text), stdin);

    size_t num;
    if(service_character_count(service, text, &num) < 0) {
        return;
    }
    
    bool is_valid = character_len(text) == num;
    service_acknowledgement(service, is_valid);
    printf("jumlah karakter (%s): %zu", (is_valid) ? "VALID": "INVALID",num);

}
void word_count(server_service *service) {
    if(!is_service_available(service, "WORD_COUNT")) {
        printf("Layanan WORD_COUNT tidak aktif");
        return;
    }

    char text[BUFFER_SIZE-10]; // "10 char reserved for 'REQUEST ' and the rest for safety"
    printf("input string: ");
    fgets(text, sizeof(text), stdin);

    size_t num;
    if(service_word_count(service, text, &num) < 0) {
        return;
    }
    bool is_valid = word_len(text) == num;
    service_acknowledgement(service, is_valid);
    printf("jumlah kata (%s): %zu", (is_valid) ? "VALID": "INVALID",num);

}
void t_reverse_string(server_service *service) {
    if(!is_service_available(service, "REVERSE_STRING")) {
        printf("Layanan REVERSE_STRING tidak aktif");
        return;
    }

    char text[BUFFER_SIZE-10]; // "10 char reserved for 'REQUEST ' and the rest for safety"
    printf("input string: ");
    fgets(text, sizeof(text), stdin);

    char reversed[BUFFER_SIZE];
    if(service_reverse_string(service, text, reversed) < 0) {
        return;
    }
    char reversed_test[BUFFER_SIZE];
    if(reverse_string(text, reversed_test) <0) {
        printf("error: t_reverse_string -> reverse_string");
        return;
    }
    bool is_valid = strcmp(reversed, reversed_test) == 0;
    service_acknowledgement(service, is_valid);
    printf("string terbalik (%s): %zu", (is_valid) ? "VALID": "INVALID", reversed);

}
void string_without_vowels(server_service *service) {
    if(!is_service_available(service, "STRING_WITHOUT_VOWELS")) {
        printf("Layanan STRING_WITHOUT_VOWELS tidak aktif");
        return;
    }

    char text[BUFFER_SIZE-10]; // "10 char reserved for 'REQUEST ' and the rest for safety"
    printf("input string: ");
    fgets(text, sizeof(text), stdin);

    char without_vowels[BUFFER_SIZE];
    if(service_string_without_vowels(service, text, without_vowels) < 0) {
        return;
    }
    char without_vowel_test[BUFFER_SIZE];
    if(string_without_vocal_alphabet(text, without_vowel_test) <0) {
        printf("error: string_without_vowels -> string_without_vocal_alphabets");
        return;
    }
    bool is_valid = strcmp(without_vowels, without_vowel_test) == 0;
    service_acknowledgement(service, is_valid);
    printf("string tanpa vokal (%s): %zu", (is_valid) ? "VALID": "INVALID", without_vowels);
}
void determinan_and_inverse_matrix(server_service *service) {
    if(!is_service_available(service, "DETERMINAN_AND_INVERSE_MATRIX")) {
        printf("Layanan DETERMINAN_AND_INVERSE_MATRIX tidak aktif");
        return;
    }

    double matrix[3][3];
    printf("input matrix: ");
    if(scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]) < 9) {
        printf("Input tidak valid.");
        return;
    }

    double d_determinan;
    double m_out[3][3];
    if(service_determinan_and_inverse_matrix(service, matrix, &d_determinan, m_out) < 0) {
        return;
    }
    double determinan_test = determinan(matrix);
    double m_out_test[3][3];
    if(inverse_matrix(matrix, m_out_test) < 0 ) {
        printf("deteriman_and_inverse_matrix -> inverse_matrix");
        return;
    }

    bool is_valid = (d_determinan == determinan_test) && (is_matrix_equal(m_out, m_out_test));
    service_acknowledgement(service, is_valid);
    char *is_valid_str = (is_valid) ? "VALID": "INVALID";
    printf("hasil determinan (%s): %lf", is_valid_str, d_determinan);
    printf("hasil inverse matrix (%s): %lf %lf %lf %lf %lf %lf %lf %lf %lf", is_valid_str, m_out[0][0], m_out[0][1], m_out[0][2], m_out[1][0], m_out[1][1], m_out[1][2], m_out[2][0], m_out[2][1], m_out[2][2]);
}

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
  /*
    server_service *service = service_init();
    if(service == NULL) {
        return 1;
    }

    while(1) {
        printf("input: ");
        char user_input[50];
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = '\0'; // remove '\n'

        // EXIT
        if(strcmp(user_input, "exit") == 0) {
            printf("[+] EXIT\n");
            break;
        }

        switch(user_input[0]) {
            case CHARACTER_COUNT: {
                character_count(service);
                break;
            }
            case WORD_COUNT: {
                word_count(service);
                break;
            }
            case REVERSE_STRING:{
                t_reverse_string(service);
                break;
            }
            case STRING_WITHOUT_VOWELS: {
                string_without_vowels(service);
                break;
            }
            case DETERMINAN_AND_INVERSE_MATRIX: {
                determinan_and_inverse_matrix(service);
                break;
            } 
            default : {
                printf("Input tidak valid");
            }
        }
    }
    
    service_stop(service);
    */

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
