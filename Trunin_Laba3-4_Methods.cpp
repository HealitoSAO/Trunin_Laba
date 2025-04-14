#include <algorithm>
#include <iostream>
#include "Trunin_Laba3-4_Methods.h"
#include "Trunin_Laba3-4_Patient.h"
using namespace std;

// инициализация глобального вектора
vector<Patient> patients;

bool isValidNumber(const string &input) {
    if (input.empty())
        return false; // Пустая строка не является корректным числом
    for (char c : input) {
        if (!isdigit(c))
            return false; // Разрешаем только положительные числа
    }

    return true;
}

// Функция для ввода числа
void EnterNumber(int &varLink, const string &label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    // Цикл для повторного запроса числа, пока не будет введено корректное значение
    while (!isValidNumber(raw_input)) {
        cout << "Invalid input. " << label;
        getline(cin, raw_input);
    }

    varLink = stoi(raw_input); // Преобразуем строку в целое число
}

bool isNotEmptyString(const string &input) { return !input.empty(); }

// функция для ввода строки
void EnterString(string &varLink, const string &label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);

    // Цикл для повторного запроса строка, пока не будет введено корректное значение
    while (!isNotEmptyString(raw_input)) {
        cout << "Invalid input. " << label;
        getline(cin, raw_input);
    }

    varLink = raw_input; // на выходе должна быть строка
}
// функция корректности ввода года 
bool isValidAge(int age) {
    return age > 0; // Год должен быть положительным
}

// функция ввода пациента
void inputPatient() {
    Patient p;
    cin>>p;
    patients.push_back(p);
}
// функция для отображения всех объектов класса 
void displayAllPatients() {
    if (patients.empty()) {
        cout << "No patients in the list." << endl;
        return;
    }
    for (const Patient &p : patients) {
        cout << p << endl;
    }
}
int getValidIndex() {
    int index;
    while (true) {
        cout << "Enter the index of a patient: ";
        string raw_input;
        cin >> raw_input;
        if (!isValidNumber(raw_input)) {
            cout << "Invalid input. Number expected." << endl;
            continue;
        }
        index = stoi(raw_input);
        if (index < 1 || index > patients.size()) {
            cout << "Invalid index." << endl;
            continue;
        }
        return index - 1;
    }
}

// Функция для демонстрации функциональности всех конструкторов 
void demoConstructors() {
    cout << "Demonstrating constructors:" << endl;
    // Создаём несколько объектов Patient 
    Patient p1; // конструктор по умолчанию
    Patient p2("John Doe", 25, {188.0, 195.0}, {70.0, 80.0}); // вызов параметризированного конструктора
    Patient p3 = p2; // конструктор копирования
    Patient p4("Transformers", 0, {}, {}); // конструктор преобразования 
    Patient p5("Transformers", 0, {0.0, 0.0}, {0.0, 0.0});// делигирующий конструктор

    // добавлем пациентов в вектор 
    patients.push_back(p1);
    patients.push_back(p2);
    patients.push_back(p3);
    patients.push_back(p4);
    patients.push_back(p5);

    // Отображаем всех пациентов 
    displayAllPatients();
}

// Функция для демонстрации функционалньости всех методов класса 
void demoMethods() {
    cout << "Demonstrating methods:" << endl;
    if (patients.empty()) {
        cout << "No patients in the list." << endl;
        return;
    }
    // сравнение по возрасту 
    int q3_index = getValidIndex();
    Patient q3 = patients[q3_index];
    int q4_index = getValidIndex();
    Patient q4 = patients[q4_index];
    cout << endl << "Comparison of patients by age: " << endl;
    if (q4 < q3) {
        cout << q3.getName() << " is older than " << q4.getName() << endl;
    }else if (q3 < q4) {
        cout << q4.getName() << " is older than " << q3.getName() << endl;
    } else {
        cout << q3.getName() << " and " << q4.getName() << " are of the same age." << endl;
    }
    cout << " Displaying patient " << endl;
    displayAllPatients();
    cout << endl;
    cout << endl << "Sum" << endl;
    int s1_index = getValidIndex();
    int s2_index = getValidIndex();
    Patient s1 = patients[s1_index];
    Patient s2 = patients[s2_index];
    Patient s4 = s1+s2;
    cout << "Sum of patients " << s1.getName() << " and " << s2.getName() << "is " << s4.getName() << endl;
    cout << s4;
    patients.push_back(s4);
    cout << endl << " Displaying all patients after adding the sum" << endl;
    displayAllPatients();
    cout << endl << endl << "Postfix increment:" << endl;
    int i5_index = getValidIndex();
    Patient i5 = patients[i5_index];
    Patient i6 = i5;
    ++i5;
    cout << i6.getAge() << " is the age of " << i5.getAge() << endl;
    patients.push_back(i6);
    cout << endl << " Displaying patient " << endl;
    displayAllPatients();
    cout << endl << endl << "Prefix increment:" << endl;
    int i7_index = getValidIndex();
    Patient i7 = patients[i7_index];
    Patient i8 = ++i7;
    cout << i8.getAge() << " is the age of " << i7.getAge() << endl;
    patients.push_back(i8);
    cout << endl << " Displaying patient " << endl;
    displayAllPatients();
    cout << endl << "averageCondition:" << endl;
    int p8_index = getValidIndex();
    Patient p8 = patients[p8_index];
    int avg = 0;
    for (const Patient& p : patients) {
       
        // avg += averageState(p8);
    }
    avg /= patients.size();
    cout << "The average condition of all patients is: " << avg << endl;
}
// функция сортировки пациентов по возрасту
void sortPatientsByAge() {
    cout << "Sorting patients by age" << endl;
    std::sort(patients.begin(), patients.end(), [](const Patient &a, const Patient &b) { return a.getAge() < b.getAge(); });
    displayAllPatients();
}
