/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** toto
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// call   0x401146 <toto>
// 0x401176 <main+9>:   call   0x401157 <tutu>

void toto(void)
{
    printf("i am in toto()\n");
}

void tutu(void)
{
    printf("i am in tutu()");
}

int main(void)
{
    toto();
    kill(getpid(), SIGWINCH);
    tutu();
    exit(0);
}