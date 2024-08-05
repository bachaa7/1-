#include <iostream>
#include <math.h>
using namespace std;

int main() {

	setlocale(LC_ALL, "RU");

	double s, x, y, z, a, b, c, d, e;

	cout << "Введите x: ";
	cin >> x;

	cout << "Введите y: ";
	cin >> y;

	cout << "Введите z: ";
	cin >> z;

	a = exp(x - 1 / sin(z));
	b = pow(a, 1 / 3.);


	c = fabs(y);
	d = pow(c, 1 / 4.);
	e = pow(x + d, 1 / 2.);



	s = pow(2, -x) * e * b;

	cout << s;

	return 0;
}
