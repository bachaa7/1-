#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main() {
	setlocale(LC_ALL, "RU");

	double a, b, h, x, y, s, p, d, chisl, znamen, i, n;
	cout << "¬ведите  a,b" << endl;
	cin >> a >> b;
	n = 150;
	x = a;
	h = (b - a) / 10;
	do {
		p = s = x;
		for (i = 1; i <= n; i++) {

			d = pow(-1, i);
			chisl = pow(x, 2 * i + 1);
			znamen = 2 * i + 1;
			p = d * chisl / znamen;
			s += p;

		}

		y = atan(x);
		cout << setw(15) << x << setw(15) << y << setw(15) << s << endl;
		x += h;

	} while (x <= b + h / 2);
	cout << endl;

	return 0;
}
