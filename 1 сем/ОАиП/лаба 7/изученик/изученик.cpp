#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct mas {
    char fio[80];
    char numotd[10];
    char dolhnost[40];
    char date[11]; // Увеличил размер на 1 для учёта нулевого символа
    double sb;
};

bool compareByDate(const mas& emp1, const mas& emp2) {
    return strcmp(emp1.date, emp2.date) < 0;
}

int main() {
    setlocale(LC_ALL, "RU");

    int num, i, j;
    cout << "Введите количество работников: ";
    cin >> num;

    mas* mrabot = new mas[num];

    for (i = 0; i < num; i++) {
        cout << "Введите Фамилию: ";
        cin.ignore();
        cin.getline(mrabot[i].fio, 80);

        cout << "Введите номер отдела: ";
        cin >> mrabot[i].numotd;

        cout << "Введите должность: ";
        cin >> mrabot[i].dolhnost;

        cout << "Введите дату начала работы ДД.ММ.ГГГГ: ";
        cin >> mrabot[i].date;

        cout << endl;
    }
    
    char department[10];
    cout << "Введите номер отдела для вывода сотрудников: ";
    cin >> department;

    int count = 0; // Счётчик сотрудников выбранного отдела
    for (i = 0; i < num; i++) {
        if (strcmp(mrabot[i].numotd, department) == 0) {
            count++;
        }
    }

    cout << "Количество сотрудников в отделе " << department << ": " << count << endl;
    cout << endl;

    sort(mrabot, mrabot + num, compareByDate); // Сортировка по дате начала работы по убыванию

    cout << "Сотрудники в отделе " << department << " (в порядке убывания даты начала работы):" << endl;
    for (i = count - 1; i >= 0; i--) {
        if (strcmp(mrabot[i].numotd, department) == 0) {
            cout << "Фамилия: " << mrabot[i].fio << endl;
            cout << "Номер отдела: " << mrabot[i].numotd << endl;
            cout << "Должность: " << mrabot[i].dolhnost << endl;
            cout << "Дата начала работы: " << mrabot[i].date << endl;
            cout << endl;
        }
    }

    delete[] mrabot;

    return 0;
}