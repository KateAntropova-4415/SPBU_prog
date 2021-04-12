//Task є10  13. "≈сли слово нечетной длины, удалить его среднюю букву.(СabcabТ->ТababТ)"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void A(char* s);
void B(char* s);
void second(char* s);
void third(char* s);

int main(int argc, char* argv[])
{
    char* input;
    char* output;
    input = (char*)calloc(256, sizeof(char));
    output = (char*)calloc(256, sizeof(char));

    printf("Please enter input file name:\n");
    gets(input);
    printf("Please enter output file name:\n");
    gets(output);

    if (argc >= 2) {
        input = argv[1];
    }
    if (argc == 3) {
        output = argv[2];
    }

    FILE* in = fopen(input, "r");

    if (in == NULL) {
        printf("error\n");
    }
    else {
        FILE* out = fopen(output, "w");
        char* s;
        char s1[256];
        char n[] = "\n";
        s = (char*)calloc(256, sizeof(char));
        fgets(s, 256, in);
        strcpy(s1, s);

        A(s);
        fwrite(s, strlen(s), 1, out);
        fwrite(n, 1, 1, out);

        B(s1);
        fwrite(s1, strlen(s1), 1, out);
        fwrite(n, 1, 1, out);

        second(s);
        fwrite(s, strlen(s), 1, out);
        fwrite(n, 1, 1, out);

        third(s);
        fwrite(s, strlen(s), 1, out);
        fwrite(n, 1, 1, out);

        fclose(out);
    }
    return 0;
}

void A(char* s) {

    char s1[256] = "";
    char* str = strtok(s, " ,.");

    while (str != NULL)
    {
        strcat(s1, str);
        strcat(s1, " ");
        str = strtok(NULL, " ,.");
    }

    strcpy(s, s1);
    s[strlen(s) - 1] = '\0';
}

void B(char* s) {
    int k = 0;
    for (int i = 0; i <= strlen(s); i++) {
        if (s[i] == ' ') {
            if (k == 0) continue;
            if (s[i + 1] == ' ') continue;
        }
        s[k] = s[i];
        k++;
    }

    for (k = k - 3; (k > 0) && (s[k] == ' ' || s[k] == '.'); k--) {
        s[k] = '\0';
    }
}

void second(char* s) {
    char s1[256] = "";
    char* str = s;
    char* last = strrchr(s, ' ') + 1;
    char* next = strchr(s, ' ');

    while (next != NULL) {
        *next = '\0';
        if (strcmp(str, last)) {
            strcat(s1, str);
            strcat(s1, " ");
        }
        str = next + 1;
        next = strchr(str, ' ');
    }

    strcpy(s, s1);
    s[strlen(s1) - 1] = '\0';
}

void third(char* s) {
    char s1[256] = "";
    int k[256];
    for (int i = 0; i < 256; i++)
    {
        k[i] = 0;
    }

    int N = 0, i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] != ' ' && s[i]!='\0')
        {
            k[N]++;
        }
        else
        {
            if (k[N] % 2 != 0 && k[N] > 1)
            {
                k[N] = i - (k[N] / 2) - 1;
                N++;
            }
            else k[N] = 0;
        }
    }
    if (k[N] % 2 != 0 && k[N] > 1)
    {
        k[N] = i - (k[N] / 2) - 1;
        N++;
    }
    else k[N] = 0;

    int j = 0, t = 0;
    for (i = 0; i <= strlen(s); i++)
    {
        if (i == 0 && k[N] == 0)
        {
            s1[t] = s[i];
            t++;
        }
        else if (i != k[j])
        {
            s1[t] = s[i];
            t++;
        }
        else if (i == k[j] && k[j]>0)
        {
            if (j < N)
            j++;
        }
    }
    strcpy(s, s1);
    s[strlen(s1)] = '\0';
}