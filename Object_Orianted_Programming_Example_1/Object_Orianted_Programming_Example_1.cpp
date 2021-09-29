#include <iostream>

using namespace std;

class Shape {

protected:

	double side1;
	double side2;

public:

	Shape(double side1=0,double side2=0):side1(side1),side2(side2){}

	virtual void Calculate() = 0;
	
};

class Square:public Shape {
	
private:

	double ratio;

public:

	Square(double side1=0,double side2=0,double ratio=0):Shape(side1,side2),ratio(ratio){}

	void Calculate() {

		if (side1 < ratio && side2 < ratio) throw(1);

		else {
			side1 = side1 - (ratio / 100);
			side2 = side2 - (ratio / 100);
			cout << "New sides are:" << side1 << "	" << side2 << endl;
		}

	}


	friend ostream& operator <<(ostream& output, Square& s) {
		output << "New sides are:" << s.side1 << " " << s.side2 << endl;
	}
};

int main()
{
	
	double side1, side2,ratio;

	cout << "Enter the sides:"; cin >> side1 >> side2;
	cout << "Enter the decrease ratio:"; cin >> ratio;

	Square s(side1, side2, ratio);
	
	try {
		s.Calculate();
	}

	catch (int x) {
		cout << "It is possible to decrease for that ratio!!" << endl;
	}

	return 0;
}





