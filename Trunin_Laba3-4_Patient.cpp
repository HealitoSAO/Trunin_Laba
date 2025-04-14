#include <iostream>
#include <numeric>
#include "Trunin_Laba3-4_Methods.h"
// конструктор по умолчанию
Patient::Patient() : name(""), age(0), height(0), weight(0) {}

// параметризованный конструктор
Patient::Patient(const std::string &name, int age, const std::vector<double> &height, const std::vector<double> &weight) : name(name), age(age), height(height), weight(weight) {}

// конструктор копирования
Patient::Patient(const Patient &other) : name(other.name), age(other.age), height(other.height), weight(other.weight) {}

// конструктор перемещения
Patient::Patient(Patient &&other) noexcept : name(std::move(other.name)), age(std::move(other.age)), height(std::move(other.height)), weight(std::move(other.weight)) {}

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
std::vector<double> Patient::getDiseases() const { return diseases; }
void Patient::setDiseases(const std::vector<double> &value) { diseases = value; }
std::vector<double> Patient::getDiseasesMarks() const { return diseasesMarks; }
void Patient::setDiseasesMarks(const std::vector<double> &value) { diseasesMarks = value; }

// метод вывода информации о пациенте
void Patient::display() const {
    std::cout << "Name: " << name << ", Age: " << age << std::endl;
    std::cout << "Diseases: ";
    for (size_t i = 0; i < diseases.size(); i++) {
        std::cout << diseases[i] << " (Mark: " << diseasesMarks[i] << ")";
        if (i < diseases.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

// перегруженные операторы 

bool Patient::operator<(const Patient &other) const { return age < other.age; }// сравнение по возрасту
double Patient::averageCondition() const{
    if (diseasesMarks.empty())
        return 0.0;
    return std::accumulate(diseasesMarks.begin(), diseasesMarks.end(), 0.0) /
           diseasesMarks.size();
} // расчет среднего значения оценок заболеваний
// создаём новый объект Patient с суммой параметров
Patient Patient::operator+(const Patient &other) const {
    std::vector<double> combinedDiseases = diseases;
    combinedDiseases.insert(combinedDiseases.end(), other.diseases.begin(), other.diseases.end());
    std::vector<double> combinedDiseasesMarks = diseasesMarks;
    combinedDiseasesMarks.insert(combinedDiseasesMarks.end(), other.diseasesMarks.begin(), other.diseasesMarks.end());
    return Patient(name + " & " + other.name, age + other.age, combinedDiseases, combinedDiseasesMarks);
}

// Префиксный инкремент: увеличиваем год на 1
Patient &Patient::operator++() {
    age++;
    return *this;
}

// Постфиксный инкремент: возвращаем копию текущего объекта, затем увеличиваем год
Patient Patient::operator++(int) {
    Patient temp = *this;
    age++;
    return temp;
}

Patient &Patient::operator&=(const Patient &other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
        diseases = other.diseases;
        diseasesMarks = other.diseasesMarks;
    }
    return *this;
}
// перегруженный оператор ввода
std::istream &operator>>(std::istream &is, Patient &patient) {
    std::cout << "Enter name: "; is >> patient.name;
    std::cout << "Enter age: "; is >> patient.age;
    std::cout << "Enter diseases: "; is >> patient.diseases;
    std::cout << "Enter diseases marks: "; is >> patient.diseasesMarks;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Patient &patient) {
    os << "Name: " << patient.name << ", Age: " << patient.age << std::endl;
    os << "Diseases: ";
    for (size_t i = 0; i < patient.diseases.size(); i++) {
        os << patient.diseases[i] << " (Mark: " << patient.diseasesMarks[i] << ")";
        if (i < patient.diseases.size() - 1) {
            os << ", ";
        }
    }
    os << std::endl;
    return os;
}