/*
root@ubuntu:~/dev# cat data_mmap.dat
KoreaJap!
Jap.
Noptrix
noptrix!!!!!
x90
.
root@ubuntu:~/dev# ./main3
KoreaJap!
Jap.
Noptrix
noptrix!!!!!
x90
.

root@ubuntu:~/dev#
*/

#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
        char *addr = 0x0;
        int fd1 = 0;

        fd1 = open("data_mmap.dat", O_EXCL);

/*
   void *mmap(void *addr, size_t length, int prot, int flags,
                  int fd, off_t offset);
       int munmap(void *addr, size_t length);
*/
        if(fd1)
        {
                addr = mmap(NULL, 1000, PROT_READ, MAP_SHARED, fd1, 0);
                printf("%s\n", addr);

                munmap(addr, 1000);
                close(fd1);
        }

}
