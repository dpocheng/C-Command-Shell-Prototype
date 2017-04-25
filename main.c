//
//  lab1.c
//  Lab1
//
//  Created by Pok On Cheng on 4/6/15.
//  Copyright (c) 2015 Pok On Cheng. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char command[6];
    char filename[53];
    char filelines[255][255];
    int index, lineindex = 0;
    int quitcommand = 0;
    FILE* infile = NULL;
    FILE* outfile = NULL;
    do
    {
        printf("> ");
        scanf("%s", command);
        switch (command[0])
        {
            case 'r':
            {
                if (command[1] == 'e' && command [2] == 'a' && command[3] == 'd')
                {
                    scanf("%s", filename);
                    infile = fopen(filename, "r");
                    if (infile == NULL)
                    {
                        printf("Cannot open %s\n", filename);
                        break;
                    }
                    memset(filename, '\0', 53);
                    //strcpy(filename, "");
                    int i;
                    for (i = 0; i < 255; i++)
                    {
                        strcpy(filelines[i], "");
                    }
                    lineindex = 0;
                    while (fgets(filelines[lineindex], sizeof(filelines[lineindex]), infile) != NULL)
                    {
                        lineindex++;
                    }
                }
                break;
            }
            case 'w':
            {
                if (command[1] == 'r' && command[2] == 'i' && command[3] == 't' && command[4] == 'e')
                {
                    scanf("%s", filename);
                    outfile = fopen(filename, "w");
                    memset(filename, '\0', 53);
                    int j, k;
                    for (j = 0; j < lineindex; j++)
                    {
                        int wrote = 0;
                        for (k = 0; k < 255; k++)
                        {
                            if (filelines[j][k] == '\n')
                            {
                                fprintf(outfile, "%s", filelines[j]);
                                wrote = 1;
                                break;
                            }
                        }
                        if (wrote == 0)
                        {
                            fprintf(outfile, "%s\n", filelines[j]);
                        }
                    }
                    fflush(outfile);
                }
                break;
            }
            case 'p':
            {
                if (command[1] == 'r' && command[2] == 'i' && command[3] == 'n' && command[4] == 't')
                {
                    int i, j;
                    for (i = 0; i < lineindex; i++)
                    {
                        int printed = 0;
                        for (j = 0; j < 255; j++)
                        {
                            if (filelines[i][j] == '\n')
                            {
                                printf("%d %s", i+1, filelines[i]);
                                printed = 1;
                                break;
                            }
                        }
                        if (printed == 0)
                        {
                            printf("%d %s\n", i+1, filelines[i]);
                        }
                    }
                }
                break;
            }
            case 'd':
            {
                if (command[1] == 'e' && command[2] == 'l' && command[3] == 'e' && command[4] == 't' && command[5] == 'e')
                {
                    scanf("%d", &index);
                    int i;
                    for (i = index - 1; i < lineindex; i++)
                    {
                        strcpy(filelines[i], filelines[i+1]);
                    }
                    lineindex--;
                }
                break;
            }
            case 'q':
            {
                if (command[1] == 'u' && command[2] == 'i' && command[3] == 't')
                {
                    if (infile != NULL)
                    {
                        int i;
                        for (i = 0; i < 255; i++)
                        {
                            memset(filelines[i], '\0', 255);
                        }
                        fclose(infile);
                    }
                    if (outfile != NULL)
                    {
                        fclose(outfile);
                    }
                    quitcommand = 1;
                }
                break;
            }
            default:
            {
                break;
            }
        }
    } while (quitcommand != 1);
}
