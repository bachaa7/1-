#include <iostream>
#include <algorithm>

using namespace std;


/* [0] [1] [2] [3] [4]
    1   2   3   2   1 
*/

bool isSymmetric(int* nums, int size) {
    for (int i = 0; i < size / 2; i++) {
        if (nums[i] != nums[size - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    int a;
    cout << "Введите размер 1-го массива (не больше 10): ";
    cin >> a;

    if (a > 10) {
        cout << "Размер массива не может быть больше 10." << endl;
        return 0;
    }

    int* nums = new int[a];

    cout << "Введите элементы массива: " << endl;
    for (int i = 0; i < a; i++) {
        cin >> nums[i];
    }

    cout << "Введенный массив: ";
    for (int i = 0; i < a; i++) {
        cout << nums[i] << " ";    }
    cout << endl;

    if (isSymmetric(nums, a)) {
        cout << "Массив является симметричным." << endl;
    }
    else {
        cout << "Массив не является симметричным." << endl;
    }

    delete[] nums;

    return 0;
}
