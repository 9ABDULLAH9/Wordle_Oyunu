void solve(char *str1, char *str2) {
    int i;
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