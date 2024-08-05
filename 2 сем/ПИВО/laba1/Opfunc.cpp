#include "Header.h"
#include<iostream>

void deqqqq::addElfront(deque<char>& deq)
{
    
    int n;
    cout << "������� ���������� ��������� ��� ���������� � ������: " << endl;
    cin >> n;

    char x;
    cout << endl << "������� �������� ��� ���������� � ������ ���� : ";

    for (int i = 0; i < n; i++) {
        cin >> x;

        deq.resize(deq.size() + 1); // ����������� ������ ���������� �� 1
        for (size_t j = deq.size() - 1; j > 0; j--) {
            deq[j] = deq[j - 1]; // �������� �������� ������
        }
        deq[0] = x; // ��������� ����� ������� � ������
    }

    cout << endl << "��� ����� ���������� ��������� � ������: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }

}



void deqqqq::DelElfront(deque<char>& deq)
{
 
   
    
    cout << "�������  ���������� ��������� ��� �������� � ������: ";
    int k;
    cin >> k;

    if (k > deq.size()) {
        cout << "�������� �� ��������" << endl << "������� �������� ������: ";
        cin >> k;
    } 
    
   

        for (int i = 0; i < k; i++) {
            for (size_t i = 0; i < deq.size() - 1; i++) {
                deq[i] = deq[i + 1]; // �������� �������� ����� 
            }
            deq.resize(deq.size() - 1); // ��������� ������ ���������� �� 1 
        

    }


    cout << endl << "��� ����� �������� ��������� � ������: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }

}



void deqqqq::addElback(deque<char>& deq)
{

    int n;
    cout << "������� ���������� ��������� ��� ���������� � ����� ����: " << endl;
    cin >> n;

    cout << endl << "������� �������� ��� ���������� � ����� ���� : ";
    char z;
     for(int i = 0; i < n; i++) {
         cin >> z;
        deq.resize(deq.size() + 1); // ����������� ������ ���� �� 1 
        deq[deq.size() - 1] = z; // ��������� ����� ������� � ����� ���� 
    }

    cout << endl << "��� ����� ���������� ��������� � �����: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }
}



void deqqqq::DelElback(deque<char>& deq)
{
    cout << "�������  ���������� ��������� ��� �������� � �����: ";
    int v;
    cin >> v;

    if (deq.size() < v) {

        cout << "�������� ����������"<< endl << "������� �������� ������: ";
        cin >> v;
    }

    for (int i = 0; i < v; i++) {
        deq.resize(deq.size() - 1); // ��������� ������ ���������� �� 1 

    }

    cout << endl << "��� ����� �������� ��������� � �����: ";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i] << ' ';
    }

}

