#include "strophoid.h"
#include <cmath>
#include <exception>
//#include <iostream>


#define PI acos(-1)

using namespace std;
using namespace lab2;
	Strophoid::Strophoid(double x0) :a(x0, 0) {}
	Strophoid::Strophoid(const Point &p0) {
		if (p0.y != 0 || p0.x == 0) {
			throw std::exception();
		}
		a = p0;
	}

	//setter
	Strophoid& Strophoid::setA(const Point &p0) {
		if (p0.y != 0 || p0.x == 0) {
			throw std::exception();
		}
		this->a = p0;
		return *this; 
	}
// дополнительно по циклу нйти площадь петли без формулы
// метод вывода острим
// сделать испольняемый файл и подключить к библиотеку 
	const Point& Strophoid::getA() const {return this->a;}


	void Strophoid::printA(std::ostream &os) {
		os << "x=" << a.x << "  y=" << a.y << endl;
	}

	double Strophoid::getY(double x0) const {
		return abs(this->a.x)*sqrt((abs(this->a.x)+x0)/(abs(this->a.x)-x0));
	}

	double Strophoid::getRo(double angle) const {
		return -abs(this->a.x)*(cos(2*angle))/cos(angle); 
	}

	double Strophoid::getRad() const { return abs(this->a.x)*sqrt(2);}

	double Strophoid::area() const {
		return 2*pow(abs(this->a.x), 2) - 0.5*PI * pow(abs(this->a.x), 2);;
	}

	double Strophoid::area2() const {
		double res=0;
		double aa = abs(a.x);
		double d = aa/10000;
		double x=-aa;
		for(int i = 0; i < 10000; ++i) {
			res += x*sqrt((aa+x)/(aa-x))*d;
			x+=d;
		}
		return -2*res;
	}

	double Strophoid::volumeSpin() const {return PI * pow(abs(this->a.x), 3)*(2*log(2)-4/3);}

	double Strophoid::asympArea() const { return 2 * pow(abs(this->a.x), 2)+0.5*PI*pow(abs(this->a.x),2);}



