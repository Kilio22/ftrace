/*
** EPITECH PROJECT, 2020
** bootstrap
** File description:
** toto
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

const char totostr[] = "I am in toto()\n";
const char tatastr[] = "I am in tutu()\n";

int toto(void)
{
    write(1, totostr, sizeof(totostr) - 1);
}

int tutu(void)
{
    write(1, tatastr, sizeof(tatastr) - 1);
}

int main(void)
{
    toto();
    kill(getpid(), SIGUSR1);
    tutu();
    // return 0;
}
