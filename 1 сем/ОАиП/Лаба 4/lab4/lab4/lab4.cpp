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
    cout << "������� ������ 1-�� ������� (�� ������ 10): ";
    cin >> a;

    if (a > 10) {
        cout << "������ ������� �� ����� ���� ������ 10." << endl;
        return 0;
    }

    int* nums = new int[a];

    cout << "������� �������� �������: " << endl;
    for (int i = 0; i < a; i++) {
        cin >> nums[i];
    }

    cout << "��������� ������: ";
    for (int i = 0; i < a; i++) {
        cout << nums[i] << " ";    }
    cout << endl;

    if (isSymmetric(nums, a)) {
        cout << "������ �������� ������������." << endl;
    }
    else {
        cout << "������ �� �������� ������������." << endl;
    }

    delete[] nums;

    return 0;
}
