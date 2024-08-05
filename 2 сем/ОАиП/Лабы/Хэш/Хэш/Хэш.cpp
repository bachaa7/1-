#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct sotr
{
    string name;
    int Departament;
    int year;
};

void Fill(sotr* p, int count)
{
    cout << "ФИО" << endl;
    cin >> p[count].name;
    cout << "Отдел" << endl;
    cin >> p[count].Departament;
    cout << "стаж" << endl;
    cin >> p[count].year;
}

void addEl(int p, int m, int* H)
{
    int i = p % m;
    if (H[i] == -1)
    {
        int stage = 1;
        while (H[i] != -1)
        {
            i = i + pow(stage, 2);
            stage++;
            if (i == m)i = 0;
        }
        H[i] = p;
    }
}

int Search(int p, int m, int* H)
{
    int i = abs(p % m);
    int stage = 1;
    while (H[i] != -1)
    {
        if (H[i] == p)return i;
        i = i + pow(stage, 2);
        stage++;
        if (i >= m)i = 0;
    }
    return -1;
}


int main()
{
    setlocale(LC_ALL, "RU");

    sotr* begin = NULL;
    int count, m;
    cout << "количество сотрудников" << endl;
    cin >> count;
    begin = new sotr[count];
    m = 20;
    cout << "размер хэш таблицы - " << m << endl;
    int* H = new int[m];

    for (int i = 0; i < count; i++)
    {
        Fill(begin, i);
    }


    for (int i = 0; i < m; i++)
    {
        H[i] = -1;
    }
    for (int i = 0; i < count; i++)
    {
        addEl(begin[i].year, m, H);
    }

    int res, ask;
    cout << "стаж какого работника хотите найти?" << endl;
    cin >> ask;
    res = Search(ask, m, H);

    if (res == -1)
    {
        cout << "Такого результата нет";
        return 0;
    }
    cout << "\nстаж\tХэш таблица" << endl;
    for (int i = 0; i < count; i++)
    {
        if (begin[i].year == ask)
        {
            cout << begin[i].year << "\t\t" << H[res] << endl;
            cout << "-------------------------------------------------\n"
                 << "Название: " << begin[i].name 
                << "\nотдел: " << begin[i].Departament
                << "\nстаж: " << begin[i].year << endl 
                << "--------------------------------------------------\n";
        }
    }

    return 0;
}