#include <stdlib.h>
#include <iostream>

using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;
    cout << "Введите элементы матрицы " << endl;
    int** a = new int* [n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    bool sim = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != a[n - 1 - j][n - 1 - i])
            {
                sim = false;
                break;
            }
        }
        if (!sim)
        {
            break;
        }
    }
    cout << ((sim) ? "Матрица симметрична относительно побочной диагонали" :
        "Матрица не симметрична относительно побочной диагонали") << endl;
    system("pause");
}
