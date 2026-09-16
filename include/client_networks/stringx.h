#ifndef STRINGX_H
#define STRINGX_H
#include <stddef.h>
size_t character_len(char *text);
size_t word_len(char *text);
int reverse_string(char *text, char* output);
int string_without_vocal_alphabet(char *text, char *output);
#endif