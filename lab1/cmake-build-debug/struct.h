
#ifndef LAB1_STRUCT_H
#define LAB1_STRUCT_H
struct Node {
    int column;
    double value;
    struct Node *next;
};

struct List {
    struct Node *head;
};

struct Matrix {
    int n;
    int m;
    struct List *rows;
};



#endif //LAB1_STRUCT_H
