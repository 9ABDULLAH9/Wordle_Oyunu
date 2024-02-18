#ifndef FUNCTION_H
#define FUNCTION_H

// Dosya Bilgileri
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Dosya Adı ve Versiyon Bilgisi
#define DOSYA_ADI "function.h"
#define VERSIYON "1.0"

// Yazar Bilgisi
#define YAZAR "Abdullah Mert Serhan"

// Fonksiyon Prototipleri
void findCommonChars(char *str1, char *str2, int *cetele);

int *find_common_indices(char *str1, char *str2);

char* findDifferentCharacters(const char *firstString, const char *secondString);

void printArray(char *msg, int *arr, int size);

void updateCetele(char *str, int *cetele, int increment);

#endif // FUNCTION_H
