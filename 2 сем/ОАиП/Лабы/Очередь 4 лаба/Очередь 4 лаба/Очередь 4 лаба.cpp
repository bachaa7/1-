#include <iostream>

using namespace std;

struct Spis1 {
    int info;
    Spis1* prev, * next;
} *begin, * end, * t;

// Создание первого элемента
void Create_Spis1(Spis1** b, Spis1** e, int in) {
    t = new Spis1;
    t->info = in;
    t->next = t->prev = NULL;
    *b = *e = t;
}

void View(Spis1* p) {
    Spis1* t = p;
    while (t != NULL) {
        // Вывод на экран информационной части, например,
        cout << t->info << endl;
        t = t->next;
    }
}

void Del_All(Spis1** p) {

    Spis1* t;
    while (*p != NULL) {
        t = *p;
        *p = (*p)->next;
        delete t;
    }
}

void Add_Spis1(int kod, Spis1** b, Spis1** e, int in) {
    t = new Spis1;
    t->info = in;
    if (kod == 0) {
        t->prev = NULL;
        t->next = *b;
        if (*b != NULL) {
            (*b)->prev = t;
        }
        *b = t;
    }
    else {
        t->next = NULL;
        t->prev = *e;
        if (*e != NULL) {
            (*e)->next = t;
        }
        *e = t;
    }
}

void DelSr(Spis1** b, Spis1** e) {
    int sum = 0;
    int count = 0;
    Spis1* current = *b;
    while (current != NULL) {
        sum += current->info;
        count++;
        current = current->next;
    }

    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        cout << "Среднее значение: " << average << endl;

        current = *e;
        while (current != NULL) {
            Spis1* temp = current;
            current = current->prev;
            if (temp->info < average) {
                if (temp == *b) {
                    *b = temp->next;
                    if (*b != NULL) {
                        (*b)->prev = NULL;
                    }
                }
                else if (temp == *e) {
                    *e = temp->prev;
                    if (*e != NULL) {
                        (*e)->next = NULL;
                    }
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
            }
        }
    }
    else {
        cout << "Список пуст.\n";
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    Spis1* begin = NULL;
    Spis1* end = NULL;

    int in;
    cout << "Введите первый элемент списка: ";
    cin >> in;

    Create_Spis1(&begin, &end, in);

    cout << "Первый элемент: ";
    View(begin);

    int choice;
    do {
        cout << "1. Добавить элемент в начало списка\n";
        cout << "2. Добавить элемент в конец списка\n";
        cout << "3 Удалить элементы со значением меньше среднего\n";
        cout << "0. Завершить программу\n";
        cout << "Выберите действие: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            int value;
            cout << "Введите значение элемента: ";
            cin >> value;
            if (choice == 1) {
                Add_Spis1(0, &begin, &end, value);
            }
            else if (choice == 2) {
                Add_Spis1(1, &begin, &end, value);
            }
            cout << "Текущий список:\n";
            View(begin);
        }
        else if (choice == 3) {
            DelSr(&begin, &end);
            cout << "Текущий список:\n";
            View(begin);
        }
    } while (choice != 0);

    Del_All(&begin);
    return 0;
}