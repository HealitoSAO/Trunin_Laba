#include "Trunin_Laba3-4_Methods.h"
#include <iostream>
#include <numeric>
// конструктор по умолчанию
Patient::Patient() : name(""), age(0), height(0), weight(0) {}

// параметризированный конструктор 
// конструктор копирования
Patient::Patient(const Patient &other) : name(other.name), age(other.age), height(other.height), weight(other.weight) {}

// конструктор перемещения 
// оператор присваивания
Patient &Patient::operator=(const Patient &other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        height = other.height;
        weight = other.weight;
    }
    return *this;
}

// деструктор
Patient::~Patient() {}

// методы get и set
std::string Patient::getName() const { return name; }
void Patient::setName(const std::string &value) { name = value; }
int Patient::getAge() const { return age; }
void Patient::setAge(int value) { age = value; }
std::vector<double> Patient::getHeight() const { return height; }
void Patient::setHeight(const std::vector<double> &value) { height = value; }
std::vector<double> Patient::getWeight() const { return weight; }
void Patient::setWeight(const std::vector<double> &value) { weight = value; }

// метод вывода информации о пациенте
void display() const {
    cout << "Name: " << name << ", Age: " << age << endl;
    cout << "Height: ";
    for (const auto &h : height) cout << h << " ";
    cout << "\nWeight: ";
    for (const auto &w : weight) cout << w << " ";
    cout << endl;
}

// перегруженные операторы 

bool operator<(const Patient &other) const { return age < other.age; }// сравнение по возрасту
// метод для расчета среднего состояния пациента
int averageState(const Patient &patient) {
    int heightSum = std::accumulate(patient.getHeight().begin(), patient.getHeight().end(), 0);
    int weightSum = std::accumulate(patient.getWeight().begin(), patient.getWeight().end(), 0);
    int heightAvg = heightSum / patient.getHeight().size();
    int weightAvg = weightSum / patient.getWeight().size();
    return (heightAvg + weightAvg) / 2.0;
}
// создаём новый объект Patient с суммой параметров
Patient operator+(const Patient &other) const {
    return Patient(name + " & " + other.name, age + other.age,
                   vector<double>(height.size() > other.height.size() ? height : other.height),
                   vector<double>(weight.size() > other.weight.size() ? weight : other.weight));
}

// Префиксный инкремент: увеличиваем год на 1
Patient operator++(int) {
    Patient temp(*this);
    operator++();
    return temp;
}

Patient Patient::operator++(int) {
    Patient temp = *this;
    age++;
    return temp;
}
Patient &operator=(const Patient &other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        height = other.height;
        weight = other.weight;
    }
    return *this;
}
// перегруженный оператор ввода
friend istream &operator>>(istream &is, Patient &patient) {
    is >> patient.name >> patient.age;
    return is;
}

friend ostream &operator<<(ostream &os, const Patient &patient) {
    os << "Name: " << patient.name << ", Age: " << patient.age;
    return os;
}
int averageState() const {
    return (accumulate(height.begin(), height.end(), 0.0) / height.size() +
            accumulate(weight.begin(), weight.end(), 0.0) / weight.size()) / 2;
}