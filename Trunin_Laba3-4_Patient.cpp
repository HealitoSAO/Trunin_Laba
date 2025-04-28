#include <iostream>
#include <numeric>
#include "Trunin_Laba3-4_Methods.cpp"
// конструктор по умолчанию
Patient::Patient() : name("Anonim"), age(0), height(0), weight(0) {}

// // параметризированный конструктор 
// // конструктор копирования
Patient::Patient(const Patient &other) : name(other.name), age(other.age), height(other.height), weight(other.weight) {}

// // конструктор перемещения 
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




// метод вывода информации о пациенте
// void Patient::display() const {
//     cout << "Name: " << name << ", Age: " << age << endl;
//     cout << "Height: ";
//     for (const auto &h : height) cout << h << " ";
//     cout << "\nWeight: ";
//     for (const auto &w  : weight) cout << w << " ";
//     cout << endl;
// }

// // перегруженные операторы 

bool Patient::operator<(const Patient &other) const { return age < other.age; } // сравнение по возрасту
// // метод для расчета среднего состояния пациента
int Patient::averageState() {
    int heightSum = std::accumulate(height.begin(), height.end(), 0);
    int weightSum = std::accumulate(weight.begin(), weight.end(), 0);
    int heightAvg = heightSum ;/// getHeight().size(); //прописать if
    int weightAvg = weightSum ;/// getWeight().size(); //прописать if
    return (heightAvg + weightAvg) / 2.0;
}
// создаём новый объект Patient с суммой параметров
Patient Patient::operator+(const Patient &other) const {
    return Patient(name + " & " + other.name, age + other.age,
                   vector<double>(height.size() > other.height.size() ? height : other.height),
                   vector<double>(weight.size() > other.weight.size() ? weight : other.weight));
}

// Префиксный инкремент: увеличиваем год на 1
// Patient Patient::operator++(int) {
//     Patient temp(*this);
//     // operator++();
//     return temp;
// }
Patient &Patient::operator++() {
    ++age;
    return *this;
}

Patient Patient::operator++(int) {
    Patient temp = *this;
    age++;
    return temp;
}

// перегруженный оператор ввода
istream &operator>>(istream &is, Patient &patient) {
    // cin.ignore();
// 
    EnterString(patient.name, "Enter name: ",is);
    EnterNumber(patient.age, "Enter age: ",is);
    int count1;
    EnterNumber(count1, "Enter number of height: ",is);
    std::size_t count = count1;
    patient.height.resize(count);
    for (std::size_t i = 0; i < count; ++i) {
        int height;
        EnterNumber(height, "Enter height " + std::to_string(i + 1) + ": ", is);
        patient.height[i] = height;
    }
    // EnterNumber(patient.height, "Enter height: ", is);
    EnterNumber(count1, "Enter number of weight: ", is);
    count = count1;
    patient.weight.resize(count);
    for (std::size_t i = 0; i < count; ++i) {
        int weight;
        EnterNumber(weight, "Enter weight " + std::to_string(i + 1) + ": ", is);
        patient.weight[i] = weight;
    }
    return is;
}

ostream &operator<<(ostream &os, const Patient &patient) {
    os << "Name: " << patient.name << ", Age: " << patient.age << ", Height: ";
    for (const auto &h : patient.height) os << h << " ";
    os << ", Weight: ";
    for (const auto &w : patient.weight) os << w << " ";
    return os;
}