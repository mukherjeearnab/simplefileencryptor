#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include "putil.h"
#include "iencrypt.h"

int main()
{
    MainMenu();
    return 0;
}

void MainMenu()
{
    clrscr();
    printf("\n");
    PrintMiddle("Main Menu", 2);
    PrintMiddle("-----------", 3);
    PrintMiddle("1. Encrypt a File.", 4);
    PrintMiddle("2. Decrypt a File.", 5);
    PrintMiddle("3. About.         ", 6);
    PrintMiddle("4. Exit.          ", 7);
    int item;
    while(1)
    {
        item = getch() - 48;
        if (item == 1)
        {
            EncryptFile();
            break;
        }
        else if (item == 2)
        {
            DecryptFile();
            break;
        }
        else if (item == 3)
            About();
        else if (item == 4)
            exit(0);
        else;
    }
}

void EncryptFile()
{
    clrscr();
    PrintMiddle("Encrypt a file", 2);
    PrintMiddle("----------------", 3);
    PrintAway("Enter a 4-Digit PIN for the file - ", 5, 20);
    int PIN;
    scanf("%d", &PIN);
    (PIN == 0)? ++PIN : PIN;
    char FPath[100];
    OpenFileDialog(&FPath);
    CleanRow(6);
    CleanRow(7);
    char fpout[200];
    strcpy(fpout, "The File Selected - ");
    strcat(fpout, FPath);
    PrintAway(fpout, 7, 20);
    PrintMiddle("Are You Sure, You want to Encrypt the File ??", 9);
    PrintMiddle("Yes [Y/y]          No [N/n]", 10);
    fflush(stdin);
    int yesno = getch();
    yesno = getch();
    CleanRow(9);
    CleanRow(10);
    if(yesno == 89 || yesno == 121)
    {
        PrintMiddle("Your Choice is Yes.", 9);
        //printf("%d", PIN);
        PrintMiddle("Encrypting File . . . .", 10);
        Encrypt(FPath, PIN);
    }
    else
        MainMenu();
    getch();
    MainMenu();
}

void DecryptFile()
{
    clrscr();
    PrintMiddle("Decrypt a file", 2);
    PrintMiddle("----------------", 3);
    PrintAway("Enter a 4-Digit PIN for the file - ", 5, 20);
    int PIN;
    scanf("%d", &PIN);
    CleanRow(5);
    PrintAway("", 5, 20);
    printf("Are You Sure, the File PIN is %d ? ? ? ?", PIN);
    PrintMiddle("Yes [Y/y]          No [N/n]", 6);
    (PIN == 0)? ++PIN : PIN;
    int yesno = getch();
    yesno = getch();
    if(yesno == 89 || yesno == 121)
    {
        CleanRow(5);
        CleanRow(6);
        PrintAway("", 5, 20);
        printf("The Given File PIN is - %d", PIN);
        char FPath[100];
        OpenFileDialog(&FPath);
        CleanRow(6);
        CleanRow(7);
        char fpout[200];
        strcpy(fpout, "The File Selected - ");
        strcat(fpout, FPath);
        PrintAway(fpout, 7, 20);
        CleanRow(9);
        CleanRow(10);
        PrintMiddle("Decrypting File . . . .", 10);
        Decrypt(FPath, PIN);
    }
    else
        DecryptFile();
    getch();
    MainMenu();
}

void About()
{
    clrscr();
    PrintMiddle("About", 3);
    PrintMiddle("-------", 4);
    PrintMiddle("Simple File Encryptor", 5);
    PrintMiddle("Version 1.0", 6);
    PrintMiddle("Created by - Arnab Mukherjee", 8);
    PrintMiddle("Created on Saturday, 6th April, 2019", 9);
    PrintMiddle("Language - C", 10);
    getch();
    MainMenu();
}



