#include <stdio.h>
#include <stdlib.h>

void	solve(char *str1, char *str2)
{
	int	i;
	int j;
	int ascii[256] = {0};

	i = 0;
	while (str2[i])
	{
		if (ascii[(int)str2[i]] == 0)
			ascii[(int)str2[i]] = 1;
		i++;
	}

	i = 0;
	j = 0;
	while (str1[i])
	{
		if (ascii[(int)str1[i]] == 1)
		{
			ascii[(int)str1[i]] = 2;
			write(1, &str1[i], 1);
		}
		i++;
	}
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
