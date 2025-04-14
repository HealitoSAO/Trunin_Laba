#ifndef _PATIENT_H
#define _PATIENT_H
#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

class Patient {
private:
    string name;
    int age;
    vector<double> height;
    vector<double> weight;

public:
    // конструкторы 
    Patient(); 
    Patient(const string &name, int age = 0, const vector<double> &height = {}, const vector<double> &weight = {})
        : name(name), age(age), height(height), weight(weight) {} // делигирующий конструктор
    Patient(const string &name, int age, const std::initializer_list<double> &height, const std::initializer_list<double> &weight); // параметризированный конструктор
    Patient(const Patient &other); // конструктор копирования
    // конструктор перемещения
    Patient(Patient &&other) noexcept : name(std::move(other.name)), age(other.age), height(std::move(other.height)), weight(std::move(other.weight)) {}
    Patient(const string &t) : name(t), age(0), height(0), weight(0) {} // конструктор преобразования 
    // Напиши оператор присваивания
    Patient &operator=(const Patient &other);
    ~Patient(); // деструктор
    // методы get и set
    string getName() const;
    void setName(const string &name);
    int getAge() const;
    void setAge(int age);
    vector<double> getHeight() const;
    void setHeight(const vector<double> &height);
    vector<double> getWeight() const;
    void setWeight(const vector<double> &weight);

    // методы вывода информации о пациенте 
    void display() const;

    // перегруженный операции 
    bool operator<(const Patient &other) const;//сравнение по возрасту
    Patient operator+(const Patient &other) const;//сложение
    Patient &operator++()//префиксный инкремент 
    Patient operator++(int) { Patient temp = *this; ++(*this); return temp; } // постфиксный инкремент
    Patient &operator&=(const Patient &other);//оператор присваивания 
    // перегруженный операторы ввода и вывода 
    friend ostream &operator<<(ostream &os, const Patient &patient);
    friend istream &operator>>(istream &is, Patient &patient);
}; 
#endif

