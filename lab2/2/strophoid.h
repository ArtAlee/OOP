#ifndef STROPHOID_H
#define STROPHOID_H
#include <iostream>
namespace lab2{
	struct Point {
		double x;
		double y;
		Point(double x=0, double y=0) : x(x), y(y) {} 
	};


	class Strophoid
	{
	private:
		Point a;	

	public:
		Strophoid(double x0=1);
		Strophoid(const Point &p0);
		Strophoid& setA(const Point &p0);
		const Point& getA()const;
		double getY(double x0)const;
		double getRo(double angle)const;
		double getRad()const;
		double area()const;
		double volumeSpin()const;
		double asympArea()const;		

		double area2()const;
		void printA(std::ostream &os);

	};


}


#endif
