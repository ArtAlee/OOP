#include <iostream>
#include "funcs.h"
#include "struct.h"
using namespace std;
using namespace lab1;

//template <typename T = double>
double inputDBL(const char * mess, double min = numeric_limits<double>::min(), double max = numeric_limits<double>::max())
{
    double n;
    for (;;) {
        cin.clear();
        cout << mess << endl;
        if ((cin >> n).good()) {
            if (n <= max && n >= min) return n;
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
    return n;
}

int inputINT(const char * mess, int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max())
{
     int n;
    for (;;) {
        cin.clear();
        cout << mess << endl;
        if ((cin >> n).good()) {
            if (n <= max && n >= min) return n;
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
    return n;
}

Matrix* input_matr() {
    int n, m, row, column, res, flag = 1;
    double value;
    const char *mess1 = "Enter the number of rows";
    const char *mess2 = "Enter the number of columns";
    const char *mess3 = "Enter the row of item (\"-1\" to stop )";
    const char *mess4 = "Enter the column of item";
    const char *mess5 = "Enter the value of item";
    n = inputINT(mess1); 
    m = inputINT(mess2); 
    Matrix *a = create(n, m);
    if (a == nullptr) {
        cout << "Allocation failure\n";
        return nullptr;
    }
    cout << "elements of matrix:\n";
    for(;;) {
        row = inputINT(mess3, -1, n-1); 
        if (row == -1) return a;
        column = inputINT(mess4, 0, m-1); 
        value = inputDBL(mess5);
        res = add_el(*a, row, column, value);
        if (res == 1) {
            cout << "Wrong coordinates of item\nTry again\n";
            continue;
        }
        if (res == 2) {
            cout << "Allocation failure\n";
            del(a);
            return nullptr;
        }
        cout << "Item added succesfully\n";
    }

}

int main() {
    int flag = 1;
    //Matrix *matr, *changed;
    flag = inputINT("1:Input matrix\n2:Finish programm\n", 1, 2); //
    while (flag == 1) {
        Matrix *matr = input_matr();
        if (matr == nullptr) break;
        Matrix *changed = task(*matr);
        if (changed == nullptr) {
            del(matr);
            break;
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
        flag = inputINT("1:Input matrix\n2:Finish programm\n", 1, 2); //s
    }
    return 0;
}

/*
int main() {

    Matrix *m = create(234,234);
    add_el(m, 2, 2, 12);
    add_el(m, 2, 33, 12);
    add_el(m, 2, 100, 1);
    add_el(m, 2, 1, 1);
    //add_el(m, 2, 17, 511.58);

    Matrix *n = task(m);
    print_matrix(m);
    cout << std::endl;
    print_matrix(n);
    del(m);
    del(n);
    //Matrix *a = input_matr();
    //pr
    return 0;

}

*/

















/*


int main()
{
    int i,j,N,M,a[20][20];
    cout<<"N=";
    cin>>N;
    cout<<"M=";
    cin>>M;
    cout<<"Input matrix A \n";

    for (i=0; i<N; i++)

        for (j=0; j<M; j++)
            cin>>a[i][j];
    cout<<"matrix A \n";
    for (i=0; i<N; i++)
    {

        for (j=0; j<M; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    //system("pause");
    Matrix *c = create(5,6);
    return 0;
}
 */