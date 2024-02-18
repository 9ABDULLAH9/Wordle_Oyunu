#include "function.h"

int main(void)
{
    char kelime[100];

    printf("Bulunmasini istediginiz kelimeyi girin: ");
    scanf("%s", kelime);

    int kelime_uzunluk = strlen(kelime);

    // kelime harfleri küçült
    for (int i = 0; i < kelime_uzunluk; i++)
        kelime[i] = tolower(kelime[i]);

    // çetele oluştur
    int *cetele = malloc(kelime_uzunluk * sizeof(int));
    if (cetele == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return 1;
    }
    for (int i = 0; i < kelime_uzunluk; i++)
        cetele[i] = 0;

    // yanlış yerdeki harfler için çetele oluştur
    int *yanlisYerdeCetele = malloc(256 * sizeof(int)); // ASCII karakterler için
    if (yanlisYerdeCetele == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return 1;
    }
    for (int i = 0; i < 256; i++)
        yanlisYerdeCetele[i] = 0;

    // olmayan harfler için çetele oluştur
    int *olmayanHarflerCetele = malloc(256 * sizeof(int)); // ASCII karakterler için
    if (olmayanHarflerCetele == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return 1;
    }
    for (int i = 0; i < 256; i++)
        olmayanHarflerCetele[i] = 0;

    // döngü başlar
    while (1) {
        char tahmin[100];

        // tahmin al
        printf("%d harfli kelime tahmininizi girin: ", kelime_uzunluk);
        scanf("%s", tahmin);

        // tahmin uzunluk kontrol
        if (strlen(tahmin) != kelime_uzunluk) {
            printf("Tahmininiz %d harfli olmalidir. Lutfen tekrar deneyin.\n", kelime_uzunluk);
            continue;
        }

        // kelimeleri küçült
        for (int i = 0; i < kelime_uzunluk; i++)
            tahmin[i] = tolower(tahmin[i]);

        // Ortak indisleri bul ve çeteleyi güncelle
        for (int i = 0; i < kelime_uzunluk; i++)
            if (kelime[i] == tahmin[i])
                cetele[i] = 1;

        // Kelimeyi yazdır
        printf("Kelime: ");
        for (int i = 0; i < kelime_uzunluk; i++)
            printf("%c", cetele[i] ? kelime[i] : '_');
        printf("\n");

        // Ortak karakterleri bul ve yanlış yerdeki harfler çetelesini güncelle
        for (int i = 0; i < kelime_uzunluk; i++)
            if (kelime[i] != tahmin[i] && strchr(kelime, tahmin[i]) != NULL)
                yanlisYerdeCetele[(unsigned char)tahmin[i]] = 1;

        // Yeri yanlış harfleri yazdır
        printArray("Yeri yanlis harfler: ", yanlisYerdeCetele, 256);

        // Olmayan harfleri bul ve çeteleyi güncelle
        for (int i = 0; i < kelime_uzunluk; i++)
            if (!strchr(kelime, tahmin[i]))
                olmayanHarflerCetele[(unsigned char)tahmin[i]] = 1;

        // Olmayan harfleri yazdır
        printArray("Olmayan harfler: ", olmayanHarflerCetele, 256);

        // Kullanıcının doğru tahminde bulunup bulunmadığını kontrol et
        if (strcmp(tahmin, kelime) == 0) {
            printf("Tebrikler! Dogru kelimeyi buldunuz.\n");
            break;
        }
    }

    // Belleği serbest bırak
    free(cetele);
    free(yanlisYerdeCetele);
    free(olmayanHarflerCetele);

    return 0;
}
