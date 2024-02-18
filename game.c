#include <stdio.h>
#include <stdlib.h>

char* solve(char* string1, char* string2) {
    int uzunluk = strlen(string1); // İfadelerin uzunluğunu alıyoruz, her ikisinin de aynı uzunlukta olduğunu varsayıyoruz
    char* sonuc = (char*)malloc((uzunluk + 1) * sizeof(char)); // Sonucu saklamak için bellekten yer ayırıyoruz

    if (sonuc == NULL) { // Bellek ayırma başarısız olduysa
        printf("Bellek ayirma basarisiz!\n");
        exit(1);
    }

    sonuc[0] = '\0'; // Sonucu boş bir string olarak başlatıyoruz
    
    for (int i = 0; i < uzunluk; i++) {
        if (string1[i] != string2[i]) { // İfadelerin aynı indexteki karakterlerini karşılaştırıyoruz
            sonuc[strlen(sonuc)] = string1[i]; // Eğer farklıysa, sonuca ekliyoruz
        }
    }
    
    sonuc[strlen(sonuc)] = '\0'; // Sonucun sonuna null karakter ekleyerek stringi sonlandırıyoruz
    return sonuc; // Sonuc dizisini döndürüyoruz
}

int	*find_common_indices(char *str1, char *str2) {
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
