#include "function.h"

void findCommonChars(char *str1, char *str2, int *cetele) 
{
    // İlk stringdeki her karakterin cetvelini artır
    while (*str1) {
        cetele[(unsigned char)*str1]++;
        str1++;
    }

    // İkinci stringdeki her karakterin cetvelini azalt
    while (*str2) {
        cetele[(unsigned char)*str2]--;
        str2++;
    }
}


int	*find_common_indices(char *str1, char *str2) 
{
	int i;
	int common_indices_count = 0;

	// Ortak indislerin bulunması
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] == str2[i]) {
			common_indices_count++;
		}
	}
	
	// Ortak indislerin dizisini oluştur
	int *common_indices = (int *)malloc((common_indices_count + 1) * sizeof(int));
	if (common_indices == NULL) {
		printf("Bellek hatasi! Yeterli bellek yok.");
		exit(EXIT_FAILURE);
	}

    // Ortak indisleri doldur
	int index = 0;
	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
		if (str1[i] == str2[i]) {
			common_indices[index++] = i;
		}
	}

    // Diziyi sonlandır
	common_indices[index] = -1;

	return common_indices;
}

char* findDifferentCharacters(const char *firstString, const char *secondString) 
{
    // Karakterlerin sayısını tutmak için bir cetvel oluşturuyoruz
    int charTally[256] = {0}; // ASCII karakterler için
    int diffCount = 0;

    // İlk stringdeki her karakterin cetvelini artır
    while (*firstString) {
        charTally[(unsigned char)*firstString]++;
        firstString++;
    }

    // İkinci stringdeki her karakterin cetvelini azalt
    while (*secondString) {
        charTally[(unsigned char)*secondString]--;
        secondString++;
    }

    // İkinci stringde olup ilk stringde olmayan karakterlerin sayısını hesapla
    for (int i = 0; i < 256; i++) {
        if (charTally[i] < 0) {
            diffCount++;
        }
    }

    // İkinci stringde olup ilk stringde olmayan karakterleri bir diziye kaydet
    char *diffChars = (char*)malloc(diffCount * sizeof(char));
    if (diffChars == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < 256; i++) {
        if (charTally[i] < 0) {
            diffChars[index++] = (char)i;
        }
    }

    return diffChars;
}

void printArray(char *msg, int *arr, int size) {
    printf("%s", msg);
    for (int i = 0; i < size; i++)
        if (arr[i])
            printf("%c, ", (char)i);
    printf("\n");
}

void updateCetele(char *str, int *cetele, int increment) {
    while (*str) {
        cetele[(unsigned char)*str] += increment;
        str++;
    }
}
