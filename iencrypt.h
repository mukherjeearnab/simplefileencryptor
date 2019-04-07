#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include "putil.h"

#pragma once


void Encrypt(char fname[100], int PIN)
{
    int dim[2];
    TerminalDimentions(&dim);

    char ch, encFileName[150];
    FILE *fps, *fpt;
    int FSize = FileSize(fname);
    strcpy(encFileName, fname);
    strcat(encFileName, ".Encrypted");

    fps = fopen(fname, "r");
	if(fps == NULL)
	{
		PrintMiddle("Error in opening source file..!!", 15);
		fclose(fps);
    	}
	fpt = fopen(encFileName, "w");
	if(fpt == NULL)
	{
		PrintMiddle("Error in opening temp.txt file..!!", 16);
		fclose(fps);
   	}

	if(fps != NULL && fpt != NULL)
	{
        char total[20], seeks[20], statement[30];
        sprintf(total, "%d", FSize);
        gotoxy(0, 16);
        int progress = 1, seek = 0;
        while(1)
        {
            seek++;
            ch = fgetc(fps);
            if(feof(fps))
            {
                printf("!");
                break;
            }
            else
            {
                ch = ch + PIN;
                fputc(ch, fpt);
                
                if(seek % 1234 == 0 || seek == FSize)
                 {
                    sprintf(seeks, "%d", seek);
                    strcat(seeks, " Out Of ");
                    strcat(seeks, total);
                    strcpy(statement, "Progress - ");
                    strcat(statement, seeks);
                    PrintMiddle(statement, 16);
                 }
                /*if(((seek/FSize)* 100) == ((progress/dim[0])*100))
                {
                    printf("=");
                    progress++;
                }*/
            }
        }
        fclose(fps);
        fclose(fpt);
        remove(fname);
        PrintMiddle("File Successfully Encrypted ! ! ! !", 18);
	}
}

void Decrypt(char fname[100], int PIN)
{
    int dim[2];
    TerminalDimentions(&dim);

    char ch, encFileName[150];
    FILE *fps, *fpt;
    int FSize = FileSize(fname);
    strcpy(encFileName, fname);
    for(int a = strlen(encFileName) - 1; a >= 0 ; a--)
    {
        if(encFileName[a] == '.')
        {
            encFileName[a] = '\0';
            break;
        }
    }
    fps = fopen(fname, "r");
	if(fps == NULL)
	{
		PrintMiddle("Error in opening source file..!!", 15);
		fclose(fps);
    	}
	fpt = fopen(encFileName, "w");
	if(fpt == NULL)
	{
		PrintMiddle("Error in opening temp.txt file..!!", 16);
		fclose(fps);
    	}

	if(fps != NULL && fpt != NULL)
	{
        char total[20], seeks[20], statement[30];
        sprintf(total, "%d", FSize);
        gotoxy(0, 16);
        int progress = 1, seek = 0;
        while(1)
        {
            seek++;
            ch = fgetc(fps);
            if(feof(fps))
            {
                printf("!");
                break;
            }
            else
            {
                ch = ch - PIN;
                fputc(ch, fpt);

                if(seek % 1234 == 0 || seek == FSize)
                 {
                    sprintf(seeks, "%d", seek);
                    strcat(seeks, " Out Of ");
                    strcat(seeks, total);
                    strcpy(statement, "Progress - ");
                    strcat(statement, seeks);
                    PrintMiddle(statement, 16);
                 }
            }
        }
        fclose(fps);
        fclose(fpt);
        remove(fname);
        PrintMiddle("File Successfully Decrypted ! ! ! !", 18);
	}
}
