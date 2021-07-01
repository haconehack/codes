#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

static char srcstr[100][128];
static char tostr[100][128];
char *fptr;
char pdx[512];

int init_words()
{
        int i = 0;
        FILE *fpp, *fppp, *fpx;
        int nmb = 0;
        fpp = NULL;
        fppp = NULL;

        memset(srcstr, 0, sizeof(srcstr));
        memset(tostr, 0, sizeof(tostr));

        system("rm -rf data; cp ./data.orig.bak data");

        fpp = fopen("./wordlist.lst", "r");
        fppp = fopen("./wordlist2.lst", "r");
        fpx = fopen("./data", "r");

        fptr = malloc(32*128);

        nmb = fread(fptr, 32, 128, fpx);

//      printf("%s\n", fptr);

        while(!feof(fpp))
        {
                fscanf(fpp, "%s\n", srcstr[i]);
                fscanf(fppp, "%s\n", tostr[i]);
                ++i;
        }

        fclose(fpp);
        fclose(fppp);

        return 1;
}

int change_words(char *str1, char *str2)
{
        int i = 0, j = 0, k = 0;
        char *str_1, *str_2;
        char *p = NULL;
        FILE *fpp = NULL;
        int nmb = 0;
        FILE *fpx = NULL;

        p = strstr(fptr, str1);

        if(p == NULL)
                return 1;

        *(p) = '\0';
        p += strlen(str1);
        sprintf(pdx, "%s%s%s", fptr, str2, p);

        fpp = fopen("./data", "w");
        fprintf(fpp, "%s", pdx);
        fclose(fpp);

        fpx = fopen("./data", "r");
        nmb = fread(fptr, 32, 128, fpx);

        //printf("%s", pdx);

}

int main()
{
        int a = 0, b = 1;
        int i = 0, jj = 0;
        char *ppop = NULL;

        if(init_words())
                printf("[o] init_word list.lst list2.lst\n");

        // changed words.
        for(i = 0; i < 3; i++)
        {
                for(jj = 0; jj < 10; jj++)
                {
                        change_words(srcstr[i], tostr[i]);
                        change_words(srcstr[i], tostr[i]);
                }
        }

        printf("%s\n", pdx);

        printf("[fptr] = %s\n", fptr);

}
