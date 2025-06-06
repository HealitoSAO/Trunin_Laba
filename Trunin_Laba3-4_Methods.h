#ifndef METHODS_H
#define METHODS_H
#include <string>
#include <vector>
#include "Trunin_Laba3-4_Patient.h"

// глобальный вектор объектов Patient
extern std::vector<Patient> patients;

// функции проверки корректности ввода данных 
bool isValidAge(int age);

void inputPatient();

// функция для отобрадения всех объектов класса 
void displayAllPatients();

// функция для демонстрации функциональности всех конструкторов 
void demoConstructors();

void EnterNumber(int &varLink, const string &label);

void EnterString(string &varLink, const string &label);\

// Функция для демонстрации функциональности всех методов класса
void demoMethods();

// Функция для сортировки пациентов по возрсту 
void sortPatientsByAge();
#endif // METHODS_H

