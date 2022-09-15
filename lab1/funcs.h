#ifndef LAB1_FUNCS_H
#define LAB1_FUNCS_H
#include "struct.h"
namespace lab1 {
    Matrix *create(int n, int m);

    int add_el(Matrix &matr, int row, int column, double val);

    void del(Matrix *matr);

    void find_el(List &l, double &max, double &min, int &count);

    Matrix *task(Matrix &old);

    void print_matrix(Matrix &matr);

    void push_list(List &l, Node *a);

}
#endif
