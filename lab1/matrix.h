#ifndef LAB1_MATRIX_H
#define LAB1_MATRIX_H
#include "struct.h"
namespace lab1 {
struct Matrix {
    int n;
    int m;
    struct List *rows;
};
    Matrix *create(int n, int m);

    void add_el(Matrix &matr, int row, int column, double val);

    void del(Matrix *matr);

    Matrix *task(const Matrix &old);

    void print_matrix(const Matrix &matr);


}
#endif


