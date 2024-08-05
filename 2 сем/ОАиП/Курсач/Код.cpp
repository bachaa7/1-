#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <limits>
#include <fstream>
#include <ctime>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Sotrudn {
    string name;
    int departament;
    string dolshnost;
    Date date;
    int experience;
};

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int day, int month, int year) {
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }

    int maxDays = 31; // Максимальное количество дней в месяце

    if (month == 2) { // Февраль
        maxDays = isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }

    return day <= maxDays;
}

Date getValidDate() {
    Date date;
    string input;

    while (true) {
        cout << "Введите дату в формате дд.мм.гггг: ";
        getline(cin, input);

        stringstream ss(input);
        char dot1, dot2;
        ss >> date.day >> dot1 >> date.month >> dot2 >> date.year;

        if (ss.fail() || dot1 != '.' || dot2 != '.' || !isValidDate(date.day, date.month, date.year)) {
            cout << "Ошибка ввода! Повторите ввод.\n";
        }
        else {
            break;
        }
    }

    return date;
}




void printInfo(const Sotrudn& sotrudn) {
    cout << "ФИО: " << sotrudn.name << endl;
    cout << "Департамент: " << sotrudn.departament << endl;
    cout << "Должность: " << sotrudn.dolshnost << endl;
    cout << "Дата начала работы: " << sotrudn.date.day << "." 
        << sotrudn.date.month << "." << sotrudn.date.year << endl;
    cout << endl;
}





int getValidChoice() {
    int choice;
    while (!(cin >> choice) || choice < 1 || choice > 11) {
        cout << "Некорректный выбор. Пожалуйста, выберите число от 1 до 11: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}

void ADD(vector<Sotrudn>& sotrVector) {
    Sotrudn newSotrudn;

    cout << "Введите ФИО: ";
    cin.ignore();
    getline(cin, newSotrudn.name);

    cout << "Введите номер департамента: ";
    cin >> newSotrudn.departament;

    cout << "Введите должность: ";
    cin.ignore();
    getline(cin, newSotrudn.dolshnost);

    cout << "Введите дату начала работы:\n";
    newSotrudn.date = getValidDate();

    cout << endl;
    // Остальная часть функции ADD
    sotrVector.push_back(newSotrudn);
}




void saveDataToFile(const vector<Sotrudn>& sotrVector) {
    string filename;
    cout << "Введите имя файла для сохранения данных: ";
    cin >> filename;

    ofstream file(filename);
    if (!file) {
        cout << "Ошибка открытия файла.\n";
        return;
    }

    for (const Sotrudn& sotrudn : sotrVector) {
        file << "ФИО: " << sotrudn.name << endl;
        file << "Департамент: " << sotrudn.departament << endl;
        file << "Должность: " << sotrudn.dolshnost << endl;
        file << "Дата начала работы: " << sotrudn.date.day << "." << sotrudn.date.month << "." << sotrudn.date.year << endl;
        file << endl;
    }

    file.close();
    cout << "\033[1;32mДанные сохранены в файл.\033[0m" << endl;
}



void readData(const string& , vector<Sotrudn>& sotrVector) {

    string r;
    cout << "Введите название файла: ";
    cin >> r;
    ifstream file(r);
    if (!file) {
        cerr << "\033[1;31mОшибка открытия файла\033[0m" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.find("ФИО:") != string::npos) {
            Sotrudn sotrudn;
            sotrudn.name = line.substr(5);

            getline(file, line); // Считываем следующую строку
            size_t pos = line.find(":");
            sotrudn.departament = stoi(line.substr(pos + 1));

            getline(file, line); // Считываем следующую строку
            pos = line.find(":");
            sotrudn.dolshnost = line.substr(pos + 1);

            getline(file, line); // Считываем следующую строку
            pos = line.find(":");
            string dateStr = line.substr(pos + 1);

            // Разбор даты
            size_t dot1 = dateStr.find('.');
            size_t dot2 = dateStr.rfind('.');
            sotrudn.date.day = stoi(dateStr.substr(0, dot1));
            sotrudn.date.month = stoi(dateStr.substr(dot1 + 1, dot2 - dot1 - 1));
            sotrudn.date.year = stoi(dateStr.substr(dot2 + 1));

            getline(file, line); // Считываем пустую строку

            sotrVector.push_back(sotrudn);
        }
    }

    file.close();
}


int calculateExperience(const Sotrudn& sotrudn) {
    // Получение текущей даты
    time_t currentTime;
    time(&currentTime);
    tm currentDate;
    localtime_s(&currentDate, &currentTime);
    int currentYear = currentDate.tm_year + 1900;
    int currentMonth = currentDate.tm_mon + 1;

    // Получение даты начала работы
    int startYear = sotrudn.date.year;
    int startMonth = sotrudn.date.month;

    // Вычисление стажа работы
    int experience = currentYear - startYear;
    if (currentMonth < startMonth)
        experience--;

    return experience;
}


// сортировки:



// линейный поиск
void searchDiapaz(const vector<Sotrudn>& sotrVector) {  
    int min, max;
    cout << "Минимальный стаж (в годах): ";
    cin >> min;
    cout << "Максимальный стаж (в годах): ";
    cin >> max;
    bool found = false;
    cout << "----------------------------------------------------------------------" << endl;
    for (const auto& sotrudn : sotrVector) {
        int experience = calculateExperience(sotrudn);
        if ((min <= experience) && (experience <= max)) {
            cout << "ФИО: " << sotrudn.name << endl;
            cout << "Отдел: " << sotrudn.departament << endl;
            cout << "Должность: " << sotrudn.dolshnost << endl;
            cout << "Дата: " << sotrudn.date.day << "." << sotrudn.date.month << "." << sotrudn.date.year << endl;
            cout << "----------------------------------------------------------------------" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\033[1;33mСотрудник не найден.\033[0m" << endl;
    }
}

//QuickSort
void sortVozrastanie(vector<Sotrudn>& sotrVector, int l, int r) {
    int i = l;
    int j = r;
    int x = sotrVector[(l + r) / 2].experience;
    Sotrudn rh;
    while (i <= j) {
        while (sotrVector[i].experience < x) i++;
        while (sotrVector[j].experience > x) j--;
        if (i <= j) {
            rh = sotrVector[i];
            sotrVector[i] = sotrVector[j];
            sotrVector[j] = rh;
            i++;
            j--;
        }
    }
    if (l < j) sortVozrastanie(sotrVector, l, j);
    if (i < r) sortVozrastanie(sotrVector, i, r);
}


//метод прямого выбора
void sortUb(vector<Sotrudn>& sotrVector, int l, int r) {
    int i = l;
    int j = r;
    int x = sotrVector[(l + r) / 2].experience;
    Sotrudn rh;
    while (i <= j) {
        while (sotrVector[i].experience > x) i++;
        while (sotrVector[j].experience < x) j--;
        if (i <= j) {
            rh = sotrVector[i];
            sotrVector[i] = sotrVector[j];
            sotrVector[j] = rh;
            i++;
            j--;
        }
    }
    if (l < j) sortVozrastanie(sotrVector, l, j);
    if (i < r) sortVozrastanie(sotrVector, i, r);
}


//двоичный поиск
void searchZnuch(vector<Sotrudn>& sotrVector) {
    sortVozrastanie(sotrVector, 0, (sotrVector.size() - 1));
    int x;
    cout << "Стаж работы: ";
    cin >> x;
    int i = 0, j = (sotrVector.size() - 1), m;
    int startIdx = -1, endIdx = -1; // Индексы начала и конца диапазона
    while (i <= j) {
        m = (i + j) / 2;
        if (calculateExperience(sotrVector[m]) < x)
            i = m + 1;
        else if (calculateExperience(sotrVector[m]) > x)
            j = m - 1;
        else {
            // Найден сотрудник с требуемым стажем, ищем начало и конец диапазона
            startIdx = m;
            endIdx = m;
            while (startIdx > 0 && calculateExperience(sotrVector[startIdx - 1]) == x)
                startIdx--;
            while (endIdx < sotrVector.size() - 1 && calculateExperience(sotrVector[endIdx + 1]) == x)
                endIdx++;
            break;
        }
    }
    if (startIdx != -1 && endIdx != -1) {
        cout << "----------------------------------------------------------------------" << endl;
        for (int k = startIdx; k <= endIdx; k++) {
            cout << sotrVector[k].name << ", " << sotrVector[k].dolshnost << ", " << sotrVector[k].departament << endl;
        }
        cout << "----------------------------------------------------------------------" << endl;
    }
    else {
        cout << "\033[1;33mСотрудник не найден.\033[0m" << endl;
    }
}





void REMOVE_BY_INDEX(vector<Sotrudn>& sotrVector) {
    int index;
    cout << "Введите номер добавления работника для удаления: ";
    cin >> index;

    if (index >= 1 && index <= sotrVector.size()) {
        sotrVector.erase(sotrVector.begin() + index - 1);
        cout << "\033[1;32mРаботник успешно удален.\033[0m" << endl;
    }
    else {
        cout << "\033[1;33mНедопустимый номер добавления работника.\033[0m" << endl;
    }
}

void menu(vector<Sotrudn>& sotrVector) {
    int choice = 0;
    Sotrudn sotrudn;
    while (choice != 11) {
        cout << "Меню:\n";
        cout << "------------------------------------------------\n"
             << "1. Добавить запись\n";
        cout << "2. Просмотреть записи\n";
        cout << "3. Расчет стажа работы(в годах)\n";
        cout << "4. Сохранить в файл \n";
        cout << "5. Загрузить данные из файла\n";
        cout << "6. Сортировка структуры ( По диапозону)\n";
        cout << "7. Сортировка по возрастанию\n";
        cout << "8. Сортировка по убыванию \n";
        cout << "9. Найти по опред значению \n";

        cout << "10. Удаление из списка \n";
        cout << "11 Выход\n"
            << "------------------------------------------------\n";

        cout << "Выберите пункт меню: ";

        choice = getValidChoice();
        Sotrudn sotrudn;

        switch (choice) {
        case 1:
            ADD(sotrVector);
            break;
        case 2:
            for (const Sotrudn& sotrudn : sotrVector) {
                printInfo(sotrudn);
            }
            break;
        case 3:
            for (const Sotrudn& sotrudn : sotrVector) {
                printInfo(sotrudn);

                int experience = calculateExperience(sotrudn);
                cout << "Стаж работы: " << experience << " лет" << endl;
               
            }
            break;
        case 4:
            saveDataToFile(sotrVector);
            break;

        case 5:
            readData("имя_файла.txt", sotrVector);

            // Вывод информации
            for (const auto& sotrudn : sotrVector) {
                cout << "ФИО: " << sotrudn.name << endl;
                cout << "Отдел: " << sotrudn.departament << endl;
                cout << "Должность: " << sotrudn.dolshnost << endl;
                cout << "Дата: " << sotrudn.date.day << "." << sotrudn.date.month << "." << sotrudn.date.year << endl;
                cout << endl;
            }       
            break;



        case 6:
            searchDiapaz(sotrVector);

            break;

        case 7:
            sortVozrastanie(sotrVector, 0, sotrVector.size() - 1);
            for (const auto& sotrudn : sotrVector) {
                cout << "Имя: " << sotrudn.name << ", Стаж работы: " << calculateExperience(sotrudn) << endl;
            }
            break;


        case 8:
            sortUb(sotrVector, 0, sotrVector.size() - 1);
            for (const auto& sotrudn : sotrVector) {
                cout << "Имя: " << sotrudn.name << ", Стаж работы: " << calculateExperience(sotrudn) << endl;
            }
            break;

        case 9:
            searchZnuch(sotrVector);

            break;


        case 10:
            REMOVE_BY_INDEX(sotrVector);
            break;


        case 11:
            cout << "Конец";
            break;

        default:
            cout << "Некорректный выбор. Повторите ввод.\n";
            break;
        }
    }
}





 


int main() {

    setlocale(LC_ALL, "RU");


    vector<Sotrudn> sotrVector;
    menu(sotrVector);

    return 0;
}