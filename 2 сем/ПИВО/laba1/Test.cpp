#include<iostream>
#include"Header.h"
#include <assert.h>
#include <cassert>


using namespace std;

void test2(const deque<char>& deq)
{
    deqqqq dq;

    assert(deq[0] == 's');
    cout << "����1 ������� �������" << endl;
    

}
void test1(const deque<char>& deq){

assert(deq.size() >= 1);
cout << "Test1 complete" << endl;
}

void test3(const deque<char>& deq)
{
    deqqqq dq;


    assert(deq[1] == 'a' || 'A');
    cout << "����3 ������� �������" << endl;


}


int main() {

	setlocale(LC_ALL, "RU");


    
    int n;
    cout << " ������� ������ ����: ";
    cin >> n;

    while (n < 0) {
        
            cout << "E�� ���: ";
            cin >> n;
        
    }



    deque<char> deq(n);

    test1(deq);


    if (!deq.empty()) {

        cout << " ������� �������� ����:\n";

        for (int i = 0; i < n; i++) {
            cin >> deq[i];
        }



        cout << " �������� ���: ";
        for (int i = 0; i < n; i++) {
            cout << deq[i] << ' ';
        }

        cout << endl;

        test2(deq);


        deqqqq operations;




        char choice;
        do {
            char num;
            cout << "�������� ��������:\n"
                << "���������� ��������� � ������ ���� ----- 1\n"
                << "�������� ��������� � ������ ����    ----- 2\n"
                << "���������� ��������� � ����� ����  ----- 3\n"
                << "�������� ��������� � ����� ����     ----- 4\n";
            cin >> num;

            switch (num) {



                // ������ ���� 

            case '1':

                operations.addElfront(deq);
                break;

                // ������ ���� 

            case '2':


                operations.DelElfront(deq);
                break;



                // ������ ���� 

            case '3':

                operations.addElback(deq);
                break;



                // ��������� ����    

            case '4':

                operations.DelElback(deq);
                break;


            }

            cout << endl << "������� ����������? (1 - ��  |  0 - ���): ";
            cin >> choice;

            if (choice != '1' && choice != '0') {

                cout << "�������� ���������� ��������� � ������� ��������� �����: ";
                cin >> choice;
               

            }

            test3(deq);



        } while (choice == '1' && choice != '0');

        


    }


    else {
        cout << " ��� ������ ";
    }


	return 0;
}
