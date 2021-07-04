/*
        root@ubuntu:~/dev# gcc execve_test.c -o execve_test
        root@ubuntu:~/dev#
*/
#include <stdio.h>

int main()
{
        char *argd[3] = { "/bin/ls", NULL, NULL };
        char *argdd[] = { "/bin/ls", "-l", NULL };
        int stu = 0;
        int apid = 0;

        apid = fork();

        printf("----noptrix noptrix--parent id = 0 and other is above 0\n");
        if(apid == 0)
                execve("/bin/ls", argd, NULL);

        printf("---- i'm nop(kj x90 a.k.a vocalist no hacker but do hacks!\n");
        stu = execvp("ls", argdd);

        if(stu == -1)
                exit(1);

}
