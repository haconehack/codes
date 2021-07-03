/*
root@ubuntu:~/dev# gcc token_strtok.c -o token_strtok
root@ubuntu:~/dev# ./token_strtok
xxxxkjasdkj
asd
talo
hacker
root@ubuntu:~/dev# 
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    char str[] = "xxxxkjasdkj asd talo hacker";

    char *ptr = strtok(str, " ");

    while (ptr != NULL)
    {
        printf("%s\n", ptr);
        ptr = strtok(NULL, " ");
    }

    return 0;
}


root@ubuntu:~/dev#
