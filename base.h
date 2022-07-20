#ifndef base

#include <stdio.h>
void message(int x, char str[])
{
    printf("\n| %7d                %-34s |", x, str);
}
void top()
{

    printf("\n-------------------------------------------------------------\n");
    printf("| Reference no.                 CONTEXT                     |\n|                                                           |");
}

void end()
{
    printf("\n-------------------------------------------------------------\n");
    printf("\nEnter the corresponding Reference no. for required calculation:\t");
}
void head(char str[])
{
    printf("\n|                                                           |\n");
    printf("      ...*** %s ***...    ", str);
    printf("\n|                                                           |");
}
void sub_head(char str[])
{
    printf("\n|                                                           |\n");
    printf("       >>>>> %s    ", str);
    printf("\n|                                                           |");
}
void topic(char str[])
{
    printf("\n\n          ****** %s ******\n\n",str);
}
void lbk()
{
    printf("| Reference no.                 CONTEXT                     |\n|                                                           |");
}
void filegame(char str[])
{
    printf("\nLooking for output\nCheck %s.txt\n",str);
}

void carryon()
{
    topic("Press any key to continue...");
}
void begindat()
{
    printf("***");
}
#define base 
#endif