#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static char orig_str[64];

unsigned int strstr_count(char *tofind)
{
        int a = 0;
        char *pos = orig_str;
        int len = 0;

        len = strlen(tofind);

        // pos and locate the pos with +len and it worked.
        while((pos = strstr(pos, tofind)) != NULL)
        {
                a++;
                pos = pos + len;
        }

        return a;

}

int main()
{
        int a = 0;
        char *findstr = "hacktheplanet";

        strcpy(orig_str, "asdasdhacktheplanethackhackhacktheplanethacktheplanet");

        a = strstr_count(findstr);
        printf("src=%s\n", orig_str);
        printf("\'%s\' count = %d\n", findstr, a);
}
