//
// Created by xphyro on 19/08/2020.
//

#include <memory.h>
#include "input.h"
#include "stdio.h"
#include "stdlib.h"

int getsize(const char *msg, const char *errmsg)
{
    printf("%s", msg);

    while(1)
    {
        int size;
        scanf("%d", &size);

        if(size > 0)
        {
            return size;
        }

        printf("%s", errmsg);
    }
}

char *getmat(int w, int h, const char *msg, const char *errmsg)
{
    printf("%s", msg);
    char *mat = malloc((w * h) * sizeof(char));
    char *row = alloca((w * 2 + 1) * sizeof(char)); // max 129 byte allocation (compensating for the spaces)
    char crow = 0;
    while(crow < h)
    {
        printf("%d> ", crow);
        scanf("%s", row);

        int i = 0;
        int j = 0;
        char err = 0;
        while(1)
        {
            char c = row[i++];
            if(c == '\0')
            {
                break;
            }

            // TODO: Add support for spaces
            if(c == 'r' || c == '0')
            {
                row[j++] = '0';
            }
            else if(c == 'b' || c == '1')
            {
                row[j++] = '1';
            }
            else
            {
                err = 1;
                break;
            }
        }

        if(err || strlen(row) != w)
        {
            printf("%s", errmsg);
            continue;
        }

        int rowoffset = w * crow;
        for(int k = 0; k < w; ++k)
        {
            mat[k + rowoffset] = row[k];
        }

        crow++;
    }

    return mat;
}