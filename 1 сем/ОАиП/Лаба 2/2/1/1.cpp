#include <iostream>

#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RU");
	double k, x, y, a, f;
	cout << "Введите значение x: ";
	cin >> x;

	cout << "Введите значение y: ";
	cin >> y;

	cout << "Viberite f: 1 - sh(x), 2 - x^2,3 - exp(x) ";

	int num;
	cin >> num;
	switch (num) {

	case 1: f = sinh(x); break;
	case 2: f = pow(x, 2); break;
	case 3: f = exp(x); break;
	default: cout << " Вы не выбрали функцию "; return 1;
	}

	a = fabs(x * y);

	if (a > 10) {
		k = log(fabs(f) + fabs(y));

	}
	else if (a < 10) {
		k = exp(f + y);
	}

	else if (a == 10) {
		k = pow(f, 1 / 3.) + y;
	}
	cout << "rezultat" << k << endl;

	return 0;
}