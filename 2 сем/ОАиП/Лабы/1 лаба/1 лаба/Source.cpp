#include <iostream>

using namespace std;

int findMax(int* mas, int low, int high) {
    if (low == high) {
        return mas[low];
    }

    int mid = (low + high) / 2;

    int max1 = findMax(mas, low, mid);
    int max2 = findMax(mas, mid + 1, high);

    return max(max1, max2);
}

int main() {

    setlocale(LC_ALL, "RU");

    int n;
    cout << "������� ������ �������: ";
    cin >> n;

    int* mas = new int[n];

    cout << "������� �������� �������: ";
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    int maxElement = findMax(mas, 0, n - 1);

    cout << "������������ �������: " << maxElement << endl;

    delete[] mas;

    return 0;
}  