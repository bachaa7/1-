#include <iostream>
#include <iomanip>
#include <cmath>
 
using namespace std;

const double pi = 3.14159;

typedef double (*uf)(double, double, int&);

void tabl(double a, double b, double h, double eps, uf fun)
{
    int k = 0;
    double sum;
    for (double x = a; x < b + h / 2; x += h)
    {
        sum = fun(x, eps, k);
        cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
    }
}

double y(double x, double eps, int& k)
{
    return sin(x);
}

double s(double x, double eps, int& k)
{
    double a, c, sum;
    sum = a = c = x;
    k = 1;
    while (fabs(c) > eps)
    {
        c = pow(x, 2) / (2 * k * (2 * k + 1));
        a *= -c;
        sum += a;
        k++;
    }
    return sum;
}

int main()
{
    cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
    tabl(0.1, 0.8, 0.1, 0.001, y);

   cout << endl;

   cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
    tabl(0.1, 0.8, 0.1, 0.001, s);

    return 0;
}







//((pow(-1,k+1)/2)+(pow(-1,k)*6/pow(k,3)*pow(П,2)))*sinkПx