/*
        root@ubuntu:~/dev# ./main4
        korea
        root@ubuntu:~/dev#

        do_test example mman.h mmap()'s.
        do_test2 just memory mapping with malloc.d.
*/

#include <stdio.h>
#include <sys/mman.h>

int main()
{
        char *add = NULL;
        char *padd = NULL;

        add = (char *)malloc(1024);

        padd = mmap(add, 100, PROT_READ|PROT_WRITE, MAP_PRIVATE, NULL, NULL);
        strncpy(add, "korea", 5);

        printf("%s\n", add);
}
