#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

int main() {
    char targetWord[11];
    char guess[11];
    int wordLength;

    // Kullanıcıdan hedef kelimeyi al
    do {
        printf("Bulunmasi istenen kelimeyi girin (en fazla 10 harfli, en az 1 harfli): ");
        scanf("%s", targetWord);
        wordLength = strlen(targetWord);
    } while (wordLength < 1 || wordLength > 10);

    // Tahmin döngüsü
    while (1) {
        printf("%d harfli kelime tahmininizi girin: ", wordLength);
        scanf("%s", guess);

        // Tahminin uzunluğunu kontrol et
        if (strlen(guess) != wordLength) {
            printf("Tahmininiz %d harfli olmalidir. Lutfen tekrar deneyin.\n", wordLength);
            continue;
        }

        // Küçük harfe dönüştür
        for (int i = 0; i < wordLength; i++) {
            guess[i] = tolower(guess[i]);
        }

        // Ortak indisleri bul
        int *commonIndices = find_common_indices(targetWord, guess);

        // Sonuçları yazdır
        printf("Kelime: ");
        for (int i = 0; i < wordLength; i++) {
            if (commonIndices[i] != -1 && targetWord[i] == guess[i]) {
                printf("%c", targetWord[i]);
            } else {
                printf("_");
            }
        }
        printf("\n");

        printf("Yeri yanlis harfler: ");
        for (int i = 0; i < wordLength; i++) {
            if (commonIndices[i] != -1 && targetWord[i] != guess[i]) {
                printf("%c", targetWord[i]);
                if (i != wordLength - 1) printf(", ");
            }
        }
        printf("\n");

        printf("Olmayan harfler: ");
        char *differentChars = findDifferentCharacters(targetWord, guess);
        printf("%s\n", differentChars);

        // Doğru kelimeyi bulunca çık
        if (strcmp(targetWord, guess) == 0) {
            printf("Tebrikler! Dogru kelimeyi buldunuz.\n");
            free(commonIndices);
            free(differentChars);
            break;
        }

        free(commonIndices);
        free(differentChars);
    }

    return 0;
}
