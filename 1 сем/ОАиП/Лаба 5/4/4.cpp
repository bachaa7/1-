#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n;
    cout << "Введите размерность матрицы: ";
    cin >> n;

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
       matrix[i] = new int[n];
       cout << "Введите элементы строки " << i + 1 << ": " << endl;
       for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
       }
    }

    bool check = true;


    if (matrix[0][n - 1] != matrix[n - 1][0]) {
        check = false;

    }



    else  if (n % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i - 1][j - 2] != matrix[i - 2][j - 1]) {
                    cout << "ELD";
                }
                else {
                    cout << "ffsfs";
                }

            }
        }
    }
     /*  for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j - 1] != matrix[i - 1][j - 2]) {
                    check = false;
                }
               
            }
            
        } */
       
    
    

        if (check) {
            cout << "Матрица симметрична" << endl;
        }
        else {
            cout << "Не симметрична" << endl;
        }
        
        

   





   /*  1 2 3 2   [0][0]   [0][1]   [0][2]    
       3 2 2 1   [1][0]   [1][1]   [1][2]    
       3 2 1 5   [2][0]   [2][1]   [2][2]    
       2 3 2 6
   */ 

    
    // Проверка на симметрию относительно побочной диагонали
  /*  bool  sim = true;
    for (int i = 0; i < n/2; i++) {
        for (int j = 0 j < n; j++) {
            if (matrix[i][j] != matrix[n-i-1][n-j-1]) {
                sim = false;
                break;
            }
          
        }
        if (!sim) {
            break;
        }
    }

   if (sim) {
        cout << "Матрица является симметричной относительно побочной диагонали." << endl;
    }
    else {
        cout << "Матрица не является симметричной относительно побочной диагонали." << endl;
   }*/

  /*  bool sim = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                sim = false;
               
                cout << "матрица не является симметричной";
            }

            break;

        }
        break;
    }

*/



    // Вывод матрицы
    cout << "Матрица:\n";
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
       cout << endl;
    }

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
       delete[] matrix[i];
    }
    delete[] matrix;

  return 0;
}
