/*

x90(nop):: SIGABRT For smashing stack mitigation than SIGSEGV.

root@ubuntu:~/dev# gcc signal_test.c -o signal
root@ubuntu:~/dev# ./signal
--
*** stack smashing detected ***: ./signal terminated
signal handler called by signaling
Aborted (core dumped)
root@ubuntu:~/dev#

*/
#include <stdio.h>
#include <signal.h>

void handler_ove(int sn)
{

        printf("signal handler called by signaling\n");
}

int main()
{
        char a[10];

        signal(SIGABRT, &handler_ove);
        strcpy(a, "AAAABBBBCCCCDDDDEEEEFFFFHackedPwned\n");
        printf("--\n");

}
