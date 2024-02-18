#include "function.h"

char* findCommonChars(char *str1, char *str2);
int	*find_common_indices(char *str1, char *str2);
char* findDifferentCharacters(const char *firstString, const char *secondString);

int main(void)
{
	char kelime[100];

	int thmne[10];
	int thmf[10];

	char *find_wi[50];

	char *wrong_index[50];
	char *wrong_char[50];

    printf("Bulunmasini istediginiz kelimeyi girin: ");
    scanf("%s", kelime);
    
	int kelime_uzunluk = strlen(kelime);

    //kelime harfleri küçült
	for (int i = 0; i < kelime_uzunluk; i++)
            kelime[i] = tolower(kelime[i]);

	//döngü başlar
    while (1) {
		char tahmin[100];

        //tahmin al
        printf("%d harfli kelime tahmininizi girin: ", kelime_uzunluk);
        scanf("%s", tahmin);
        
		//tahmin uzunluk kontrol
        if (strlen(tahmin) != kelime_uzunluk) {
            printf("Tahmininiz %d harfli olmalidir. Lutfen tekrar deneyin.\n", kelime_uzunluk);
            continue;
        }

		//kelimeleri küçült
        for (int i = 0; i < kelime_uzunluk; i++) 
            tahmin[i] = tolower(tahmin[i]);

		//tahminin doğru karakterlerini yazdır
		*thmne = find_common_indices(kelime, tahmin);
		printf("Kelime: ");
		for (int i = 0; i < kelime_uzunluk; i++)
		{
			if (thmne[i] == i)
				printf("%c", kelime[thmne[i]]);
			else
				printf("_");
		}








		//keime doğru ise programı bitirdim
        if (strcmp(tahmin, kelime) == 0) {
            printf("Tebrikler! Dogru kelimeyi buldunuz.\n");
            break;
        }
	}
	return (0);
}
