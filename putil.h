#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"


#pragma once

void TerminalDimentions(int Dimentions[2])
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    Dimentions[0] = w.ws_col;
    Dimentions[1] = w.ws_row;
}

void PrintMiddle(char string[30], int y)
{
    int Dimentions[2];
    TerminalDimentions(&Dimentions);
    int length = strlen(string);
    int offset = (Dimentions[0]/2) - (length/2);
    gotoxy(offset, y);
    printf("%s", string);
}

void PrintMiddleO(char string[30], int y, int preoffset)
{
    int Dimentions[2];
    TerminalDimentions(&Dimentions);
    int length = strlen(string);
    int offset = (Dimentions[0]/2) - (length/2) - preoffset;
    gotoxy(offset, y);
    printf("%s", string);
}

void clrscr() { system("clear"); }

const char * OpenFileDialog(char path[100])
{
    FILE *f = popen("zenity --file-selection", "r");
    char filename[1024], c;
    fgets(filename, 1024, f);
    filename[strlen(filename)-1] = '\0';
    strcpy(path, filename);
}

void CleanRow(int Y)
{
    int Dimentions[2];
    TerminalDimentions(&Dimentions);
    gotoxy(0, Y);
    for(int a = 0; a < Dimentions[0]; a++)
        printf(" ");
}

void PrintAway(char string[30], int y, int xaway)
{
    gotoxy(xaway, y);
    printf("%s", string);
}

int FileSize(char file_name[])
{
    FILE* fp = fopen(file_name, "r");
    int siz = 0;
    char ch;
    while(1)
    {
        ch = fgetc(fp);
        if(feof(fp))
        {
            break;
        }
        siz++;
    }
    return siz;
}

