#include <iostream>
using namespace std;
bool chet(int number) {
    return number % 2 == 0;
}

int main() {
    setlocale(LC_ALL, "RU");

    int size;
      cout << "Введите размер строки(1 число -- 1 элемент): ";
      cin >> size;
      cin.ignore(); // Очищаем буфер ввода

    int* numbers = new int[size];

    cout << "Введите числа в строке: ";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }

    cout << "Четные числа в строке: ";
    for (int i = 0; i < size; i++) {
        if (chet(numbers[i])) {
            cout << numbers[i] << " ";
        }
    }

    delete[] numbers;

    return 0;
}