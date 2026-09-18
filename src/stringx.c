#include <string.h>

/*
stringx -> String Extended
*/

/*
Menghitung jumlah karakter dari text
*/
size_t character_len(char *text) {
    size_t cnt = 0;

    cnt = strlen(text);
    
    return cnt;
}

/*
Menghitung jumlah kata dari text
*/
size_t word_len(char *text) {
    size_t cnt = 0;
    int dalam_kata = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') {
            if (dalam_kata == 0) {
                cnt++;
                dalam_kata = 1;
            }
        } else {
            dalam_kata = 0;
        }
    }

    return cnt;
}

/*
Membalikkan string
kembalian = -1 => error
*/
int reverse_string(char *text, char* output) {
    size_t panjang = strlen(text);

    for (size_t i = 0; i < panjang; i++) {
        output[i] = text[panjang - 1 - i];
    }

    output[panjang] = '\0';

    return 0;
}

/*
Mengembalikan string tanpa huruf vokal dari string
kembalian = -1 => error
*/

int string_without_vocal_alphabet(char *text, char *output) {
    size_t j = 0;

    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] != 'a' && text[i] != 'i' && text[i] != 'u' &&
            text[i] != 'e' && text[i] != 'o' &&
            text[i] != 'A' && text[i] != 'I' && text[i] != 'U' &&
            text[i] != 'E' && text[i] != 'O') {
            
            output[j] = text[i];
            j++;
        }
    }

    output[j] = '\0';
    return 0;
}
