#include <stdio.h>

int main()
{
        char *argd[3] = { "/bin/ls", NULL, NULL };
        execve("/bin/ls", argd, NULL);

}
