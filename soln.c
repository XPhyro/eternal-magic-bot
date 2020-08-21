#include "soln.h"
#include "stdlib.h"
#include "memory.h"
#include "stdio.h"

char solve(int w, int h, const char *mat, unsigned long long *soln)
{
    int size = w * h;

    if(issolved(size, mat))
    {
        *soln = 0;
        return 1;
    }

    char *matcpy = malloc(size * sizeof(char));
    unsigned long long comb = 1;
    unsigned long long mcomb = (1 << size);

    while(comb != 0 && comb <= mcomb)
    {
        memcpy((void *)matcpy, mat, size);

        for(int i = 0; i < size; ++i)
        {
            if(comb & (1 << i))
            {
                trigger(i, w, h, matcpy);
            }
        }

        if(issolved(size, matcpy))
        {
            *soln = comb;
            return 1;
        }

        comb++;
    }

    return 0;
}

static void trigger(int i, int w, int h, char *mat)
{
    int coords[5] = {
            i, i - w, i + w, i % w ? i - 1 : -1, i % w != (w - 1) ? i + 1 : -1
    };

    int size = w * h;

    for(int j = 0; j < 5; ++j)
    {
        int c = coords[j];

        if(c < 0 || c >= size)
        {
            continue;
        }

        mat[c] = mat[c] == '0' ? '1' : '0';
    }
}

static char issolved(int size, const char *mat)
{
    for(int i = 0; i < size; ++i)
    {
        if(mat[i] == '0')
        {
            return 0;
        }
    }

    return 1;
}

void printsoln(int w, int h, unsigned long long soln)
{
    int size = w * h;
    const char *fstr = "%c";
    const char *fstrn = "%c\n";
    for(int i = 0; i < size; ++i)
    {
        unsigned long long bit = soln & (1 << i);
        printf(i % w == w - 1 ? fstrn : fstr, bit ? '1' : '0');
    }
}