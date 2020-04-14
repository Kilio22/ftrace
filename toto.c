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
    // write(1, "i am in toto()\n", 15);
    printf("i am in toto()\n");
}

void tutu(void)
{
    // write(1, "i am in tutu()\n", 15);
    printf("i am in tutu()\n");
}

int main(void)
{
    toto();
    tutu();
    return 0;
}