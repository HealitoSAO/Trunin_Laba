#include <iostream>
#include <numeric>
#include "Trunin_Laba3-4_Methods.h"
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
void Patient::display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
    std::cout << "Height: ";
    for (const auto& h : height) {
        std::cout << h << " ";
    }
    std::cout << std::endl;
    std::cout << "Weight: ";
    for (const auto& w : weight) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
}

// перегруженные операторы 

bool Patient::operator<(const Patient &other) const { return age < other.age; }// сравнение по возрасту
// метод для расчета среднего состояния пациента
double averageState(const Patient &patient) {
    double heightAvg = averageHeight(patient);
    double weightAvg = averageWeight(patient);
    return (heightAvg + weightAvg) / 2.0;
}
// создаём новый объект Patient с суммой параметров
Patient Patient::operator+(const Patient &other) const {
    std::vector<double> combinedHeight = height;
    combinedHeight.reserve(combinedHeight.size() + other.height.size());
    combinedHeight.insert(combinedHeight.end(), other.height.begin(), other.height.end());

    std::vector<double> combinedWeight = weight;
    combinedWeight.reserve(combinedWeight.size() + other.weight.size());
    combinedWeight.insert(combinedWeight.end(), other.weight.begin(), other.weight.end());

    return Patient(name + " & " + other.name, age + other.age, combinedHeight, combinedWeight);
}

// Префиксный инкремент: увеличиваем год на 1
Patient &Patient::operator++() {
    age++;
    return *this;
}

Patient Patient::operator++(int postfix) {
    Patient temp = *this;
    ++(*this);
    return temp;
}

Patient &Patient::operator&=(const Patient &other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        height = other.height;
        weight = other.weight;
    }
    return *this;
}
// перегруженный оператор ввода
std::istream &operator>>(std::istream &is, Patient &patient) {
    is >> patient.name;
    is >> patient.age;
    std::copy(std::istream_iterator<double>(is), std::istream_iterator<double>(), std::back_inserter(patient.height));
    std::copy(std::istream_iterator<double>(is), std::istream_iterator<double>(), std::back_inserter(patient.weight));
    return is;
}

std::ostream &operator<<(std::ostream &os, const Patient &patient) {
    os << "Name: " << patient.name << ", Age: " << patient.age << std::endl;
    os << "Height: ";
    for (size_t i = 0; i < patient.getHeight().size(); i++) {
        os << patient.getHeight()[i];
        if (i < patient.getHeight().size() - 1) {
            os << ", ";
        }
    }
    os << std::endl;
    os << "Weight: ";
    for (size_t i = 0; i < patient.getWeight().size(); i++) {
        os << patient.getWeight()[i];
        if (i < patient.getWeight().size() - 1) {
            os << ", ";
        }
    }
    os << std::endl;
    return os;
}