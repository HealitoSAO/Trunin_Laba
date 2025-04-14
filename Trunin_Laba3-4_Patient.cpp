#include <iostream>
#include <numeric>
#include "Trunin_Laba3-4_Methods.h"
// конструктор по умолчанию
Patient::Patient() : name(""), age(0), height(0), weight(0) {}

// параметризованный конструктор
Patient::Patient(const std::string &name, int age, const std::vector<double> &height, const std::vector<double> &weight)
    : name(name), age(age), height(height), weight(weight) {}

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
std::vector<double> Patient::getDiseasesMarks() const { return diseasesMarks_; }
void Patient::setDiseasesMarks(const std::vector<double> &value) { diseasesMarks_ = value; }

// метод вывода информации о пациенте
void Patient::display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
    std::cout << "Diseases: ";
    for (size_t i = 0; i < getDiseases().size(); i++) {
        std::cout << getDiseases()[i] << " (Mark: " << getDiseasesMarks()[i] << ")";
        if (i < getDiseases().size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// перегруженные операторы 

bool Patient::operator<(const Patient &other) const { return age < other.age; }// сравнение по возрасту
double averageCondition(const Patient &patient) {
    if (patient.getDiseasesMarks().empty())
        return 0.0;
    return std::accumulate(patient.getDiseasesMarks().begin(), patient.getDiseasesMarks().end(), 0.0) /
           patient.getDiseasesMarks().size();
}// среднее значение оценок заболеваний
// создаём новый объект Patient с суммой параметров
Patient Patient::operator+(const Patient &other) const {
    std::vector<std::string> combinedDiseases = getDiseases();
    combinedDiseases.insert(combinedDiseases.end(), other.getDiseases().begin(), other.getDiseases().end());
    std::vector<double> combinedDiseasesMarks = getDiseasesMarks();
    combinedDiseasesMarks.insert(combinedDiseasesMarks.end(), other.getDiseasesMarks().begin(), other.getDiseasesMarks().end());
    return Patient(name + " & " + other.name, age + other.age, combinedDiseases, combinedDiseasesMarks);
}

// Префиксный инкремент: увеличиваем год на 1
Patient &Patient::operator++() {
    age++;
    return *this;
}

Patient Patient::operator++(int) {
    Patient temp = *this;
    ++(*this); // вызываем префиксный инкремент
    return temp;
}

Patient &Patient::operator&=(const Patient &other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        diseases_ = other.diseases_;
        diseasesMarks_ = other.diseasesMarks_;
    }
    return *this;
}
// перегруженный оператор ввода
std::istream &operator>>(std::istream &is, Patient &patient) {
    std::cout << "Enter name: "; is >> patient.name;
    std::cout << "Enter age: "; is >> patient.age;
    std::vector<std::string> diseases;
    std::cout << "Enter diseases: ";
    std::copy(std::istream_iterator<std::string>(is), std::istream_iterator<std::string>(), std::back_inserter(diseases));
    patient.setDiseases(diseases);
    std::cout << "Enter diseases marks: ";
    std::vector<double> diseasesMarks;
    std::copy(std::istream_iterator<double>(is), std::istream_iterator<double>(), std::back_inserter(diseasesMarks));
    patient.setDiseasesMarks(diseasesMarks);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Patient &patient) {
    os << "Name: " << patient.name << ", Age: " << patient.age << std::endl;
    os << "Diseases: ";
    for (size_t i = 0; i < patient.getDiseases().size(); i++) {
        os << patient.getDiseases()[i] << " (Mark: " << patient.getDiseasesMarks()[i] << ")";
        if (i < patient.getDiseases().size() - 1) {
            os << ", ";
        }
    }
    os << std::endl;
    return os;
}