#include <iostream>
#include "matrix.h"
using namespace std;
using namespace lab1;

template <typename T> 
void input(T &n, const char * mess, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max())
{
    for (;;) {
        cin.clear();
        cout << mess << endl;
        if ((cin >> n).good()) {
            if (n <= max && n >= min) return;
            cout << "Invalid value\n";
        }
        if (cin.fail()) {
            cout << "Wrong input, repeat please.\n";
            //cin.clear();
            ///cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

Matrix* input_matr() {
    int n, m, row, column, res, flag = 1;
    double value;
    const char *mess1 = "Enter the number of rows";
    const char *mess2 = "Enter the number of columns";
    const char *mess3 = "Enter the row of item (\"-1\" to stop )";
    const char *mess4 = "Enter the column of item";
    const char *mess5 = "Enter the value of item";
    input(n, mess1); 
    input(m, mess2); 
    Matrix *a = create(n, m);
    cout << "elements of matrix:\n";
    for(;;) {
        input(row, mess3, -1, n-1); 
        if (row == -1) return a;
        input(column, mess4, 0, m-1); 
        input(value,mess5);
        add_el(*a, row, column, value);
        cout << "Item added succesfully\n";
    }

}

int main() {
    int flag = 1;
    Matrix *matr, *changed;
    input(flag, "1:Input matrix\n2:Finish programm\n", 1, 2); //
    while (flag == 1) {
        try{
            matr = input_matr();
        }
        catch (std::bad_alloc &ba) {
            cout << "Allocation failure" << endl;
            del(matr);
            return 1;
        }
        try {
            changed = task(*matr);
        }
        catch (std::bad_alloc &ba) {
            cout << "Allocation failure" << endl;
            del(matr);
            if (changed) del(changed);
            continue;
        }
        if (matr->rows) {
            cout << "Old matrix:" << endl;
            print_matrix(*matr);
            cout << "New matrix:" << endl;
            print_matrix(*changed);
        }
        else cout << "Empty matrix" << endl;
        del(matr);
        del(changed);
        input(flag, "1:Input matrix\n2:Finish programm\n", 1, 2); //s
    }
    return 0;
}










