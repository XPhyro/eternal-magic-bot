//
// Created by xphyro on 19/08/2020.
//

#ifndef EM_RED_TO_BLUE_SOLN_H
#define EM_RED_TO_BLUE_SOLN_H

#endif //EM_RED_TO_BLUE_SOLN_H

char solve(int w, int h, const char *mat, unsigned long long *soln);

static void trigger(int i, int w, int h, char *mat);

static char issolved(int size, const char *mat);

void printsoln(int w, int h, unsigned long long soln);