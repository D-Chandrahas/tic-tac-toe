#ifndef FUNC_H
#define FUNC_H


#include <cstdlib>
#include <cstdio>
#include <ctime>



void printmmat(int mat[3][3]);

bool checkwin1(int mat[3][3]);

bool checkwin2(int mat[3][3]);

void decideX(int mat[3][3],const int &i,int &r,int &c);



#endif