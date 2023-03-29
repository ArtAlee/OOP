#include <iostream>
#include <limits>
#include "matrix.h"
using namespace lab1;

#define MAX_DBL std::numeric_limits<double>::max();
#define MIN_DBL std::numeric_limits<double>::min();

using std::cin;
using std::cout;
namespace lab1 {
    //Matrix* lab1::create()
    struct Node {
        int column;
        double value;
        struct Node *next;
    };

    struct List {
       struct Node *head;
        int row;
        struct List *next;
    };

    void push_list(List &l, Node *a);
    void find_el(const List &l, double &max, double &min, int &count);
}

Matrix *lab1::create(int n, int m) {
    Matrix *matr;
//    try 
  //  {
    matr = new Matrix;
    //}
   // catch (std::bad_alloc &ba) {
   //     return nullptr;
  //  }
    matr->n = n;
    matr->m = m;
    matr->rows = nullptr;
    //matr->rows = new(std::nothrow) List;
    return matr;
}
// const
void lab1::print_matrix(const Matrix &matr) {
    //if (!matr) return;
        List *ptr = matr.rows;
        Node *tmp;
        while (ptr) {
            tmp = ptr->head;
            cout << "row" << ptr->row << ":\t";
            while (tmp) {
                cout << tmp->value << "(col:" << tmp->column << ")\t";
                tmp = tmp->next;
            }
            cout << std::endl;
            ptr = ptr->next;
        }
}

void lab1::push_list(List &l, Node *a) {
    Node *ptr = l.head;
    if (!ptr) {
        l.head = a;
        return;
    }
    if (ptr->column > a->column) { // push to head
        l.head = a;
        a->next = ptr;
        return;
    }
    if (ptr->column == a->column) {
        ptr->value = a->value;
        delete a;
        return;
    }
    Node *prev = ptr;
    ptr = ptr->next;
    while (ptr) {
        if (ptr->column > a->column) {
            prev->next = a;
            a->next = ptr;
            return;
        }
        if (ptr->column == a->column) {
            ptr->value = a->value;
            delete a;
            return;
        }
        ptr = ptr->next;
        prev = prev->next;
    }
    prev->next = a;

}
// change int to void
void lab1::add_el(Matrix &matr, int row, int column, double val) {
    Node *a;
    List *l;
    try {
        a = new Node;
        l = new List;
    }
    
    catch (std::bad_alloc &ba){
        delete a;
        delete l;
        throw ba;
        //return;
    }
    a->column = column;
    a->value = val;
    List *ptr = matr.rows;
    if (!ptr) {
        matr.rows = l;
        matr.rows->row = row;
        matr.rows->head = a;
        return;
    }
    List *prev_list = ptr;
    ptr = ptr->next;
    if (prev_list->row == row) {
        push_list(*prev_list, a);
        delete l;
        return;
    }
    if (prev_list->row > row) {
        l->row = row;
        matr.rows = l;
        l->next = prev_list;
        push_list(*l, a);
        return;
    }
    while (ptr) {
        if (ptr->row > row) {
            l->row = row;
            prev_list->next = l;
            l->next = ptr;
            push_list(*l,a);
            return;
        }
        if (ptr->row == row) {
            push_list(*ptr, a);
            delete l;
            return;
        }
        ptr = ptr->next;
        prev_list = prev_list->next;
    }
    l->row = row;
    push_list(*l, a);
    prev_list->next = l;
    return;

}


void lab1::del(Matrix *matr) {
    if (!matr) return;
    List *ptr_l = matr->rows;
    List *cur_l;
    Node *ptr_n;
    Node *cur_n;
    while (ptr_l) {
        ptr_n = ptr_l->head;
        while (ptr_n)  {
            cur_n = ptr_n->next;
            delete ptr_n;
            ptr_n = cur_n;
        }
        cur_l = ptr_l->next;
        delete ptr_l;
        ptr_l = cur_l;
    }
    delete matr;
}

//const
void lab1::find_el(const List &l, double &max, double &min, int &count) {
    if (!l.head) return;
    Node *ptr = l.head;
    int count_max=0;
    int count_min=0;
    count = 0;
    min = MAX_DBL;
    max = MIN_DBL;
    while (ptr) {
        if (ptr->value > max) {
            count_max = 1;
            max = ptr->value;
        } else if (ptr->value == max) ++count_max;


        if (ptr->value < min) {
            count_min = 1;
            min = ptr->value;
        } else if (ptr->value == min) ++count_min;
        ptr = ptr->next;
    }
    count = std::min(count_max, count_min);
}

Matrix *lab1::task(const Matrix &old) {
    //if (!old.rows) return nullptr;
    List *l_old, *l_new;
    Node *node_old, *node_new;
    Matrix *changed;
    changed = new Matrix;
    changed->n = old.n;
    changed->m = old.m;
    double min;
    double max;
    int count = 0;
    int counter_min = 0;
    int counter_max = 0;
    l_old = old.rows;
    l_new = new List;
    if (old.rows) changed->rows = l_new;
    while(l_old) {
        l_new->row = l_old->row;
        node_old = l_old->head;
        l_new->head = new Node;
        node_new = l_new->head;
        find_el(*l_old, max, min, count);
        while (node_old) {
            node_new->column = node_old->column;
            if(node_old->value == min && counter_min < count) {
                node_new->value = max;
                ++counter_min;
            }
            else if(node_old->value == max && counter_max < count) {
                node_new->value = min;
                ++counter_max;
            }
            else node_new->value = node_old->value;
            node_old = node_old->next;
            if (node_old) {
                node_new->next = new Node;
                node_new = node_new->next;
            }
        }
        counter_min = 0;
        counter_max = 0;
        l_old = l_old->next;
        if (l_old) {
            l_new->next = new List;
            l_new = l_new->next;
        }
    }
    return changed;

}



