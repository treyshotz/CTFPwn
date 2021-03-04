//
// Created by Mads Lundegaard on 01/03/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>

struct user {
    char name[16];
    int age;
    bool is_hacker;
} __attribute__((packed));

void c(char *buf, ...)
{
    va_list args;
    va_start (args, buf);     /* Initialize the argument args. */

    char arg = va_arg(args, int);

    while( arg ) {
        sprintf(buf, "%s%c", buf, arg);
        arg = va_arg(args, int);
    }

    va_end (args);                  /* Clean up. */
}

int main() {
    struct user hacker;
    hacker.is_hacker = 0;
    hacker.age = 22;

    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Hey, hacker! What's your name?\n");

    read(STDIN_FILENO, hacker.name, 30);

    fflush(stdout);
    if(hacker.age == 25 && hacker.is_hacker == 1) {
        printf("You made it! Here is the flag\n");
        char str[512];
        c(str, 'f','l','a','g','{','}');
        printf("The flag is: %s\n", str);
    } else {
        printf("Sorry you are not a hacker\n");
    }
    return 0;
}
