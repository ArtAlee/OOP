//
// Created by Artem Aleksenko on 07.09.2022.
//
#include "struct.h"
#ifndef LAB1_FUNCS_H
#define LAB1_FUNCS_H
Matrix * create(int n, int m);
int add_el(Matrix &matr, int row, int column, double val);
void del(Matrix *matr);
void find_el(List *l, double &max, double &min, int &count);
Matrix * task(Matrix *old);


#endif //LAB1_FUNCS_H
