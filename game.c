#include "function.h"

char* findCommonChars(char *str1, char *str2);
int	*find_common_indices(char *str1, char *str2);
char* findDifferentCharacters(const char *firstString, const char *secondString);

int main(void)
{
	char kelime[100];
    printf("Bulunmasini istediginiz kelimeyi girin: ");
    scanf("%s", kelime);
    
    int kelime_uzunluk = strlen(kelime);

	//döngü başlar
    while (1) {
        char tahmin[100];
        printf("%d harfli kelime tahmininizi girin: ", kelime_uzunluk);
        scanf("%s", tahmin);
        
        if (strlen(tahmin) != kelime_uzunluk) {
            printf("Tahmininiz %d harfli olmalidir. Lutfen tekrar deneyin.\n", kelime_uzunluk);
            continue;
        }

        for (int i = 0; i < kelime_uzunluk; i++) {
            tahmin[i] = tolower(tahmin[i]);
        }

		





        if (strcmp(tahmin, kelime) == 0) {
            printf("Tebrikler! Dogru kelimeyi buldunuz.\n");
            break;
        }
	}
	return (0);
}
