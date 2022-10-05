#include "strophoid.h"
//#include <iostream>


using namespace std;
using namespace lab2;



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


int main() {
	int flag=1;
	double x0, y0, tmp, res;
	Strophoid str;
	const char *mess00 ="";
	const char *mess0 = "Enter x coordinate of strophoid's point A";
	//const char *mess00 = "Enter y coordinate of strophoid's point A";
	const char *mess1 = "1. Set A";
	const char *mess2 = "2. Get A";
	const char *mess3 = "3. Y out of x";
	const char *mess4 = "4. Distance to center (of angle)";
	const char *mess5 = "5. Radius of curvature";
	const char *mess6 = "6. Loop area";
	const char *mess7 = "7. Body of revolution volume";
	const char *mess8 = "8. Area between branches and asymptote";
	const char *mess9 = "9. Area by integral";
	const char *mess10 = "Iput x";
	const char *mess11 = "Input angle";
	const char *mess12 = "10. Quit";
	const char *arr[] = {mess1, mess2, mess3, mess4, mess5, mess6, mess7, mess8, mess9, mess12};
	for(;;) {
		input(x0, mess0);
		try {
			str = Strophoid(x0);
		}
		catch (std::exception &exc) {
			cout << "Invalid arguement\n";
			continue;
		}
		break;
	}
	while (flag) {
		for (int i = 0; i < 10; ++i) {
			cout << arr[i] << endl;
		}
		cout << endl;
		input(flag, mess00, -1, 10);
		switch (flag)
		{
			case 1: {
				input(x0, mess0);
				try {
					str.setA(Point(x0, 0));
				}
				catch (std::exception &exc) {
					cout << "Invalid arguement\n";
				}
				break;
			}
			case 2: {
				//Point p = str.getA();
				//cout << "x=" << p.x << " y=" << p.y << endl;
				str.printA(cout);
				break;
			}
			case 3: {
				input(tmp, mess10);
				res = str.getY(tmp);
				cout << "+-" << res << endl;
				break;
			}
			case 4: {
				input(tmp, mess11);
				res = str.getRo(tmp);
				cout << res << endl;
				break;
			}

			case 5: {
				cout << str.getRad() << endl;
				break;
			}
			case 6: {
				cout << str.area() << endl;
				break;
			}
			case 7: {
				cout << str.volumeSpin() << endl;
				break;
			}
			case 8: {
				cout << str.asympArea() << endl;
				break;
			}

			case 9: {
				cout << str.area2() << endl;
				break;
			}

			case 10: {
				flag = 0;
				break;
			}
		
		}

	}
	return 0;

}








