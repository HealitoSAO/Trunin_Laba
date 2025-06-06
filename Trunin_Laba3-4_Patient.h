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
    Patient() : name(""), age(0), height({}), weight({}) {}
    Patient(const string &name, int age = 0, const vector<double> &height = {}, const vector<double> &weight = {})
        : name(name), age(age), height(height), weight(weight) {}
    Patient(const string &name, int age, const std::initializer_list<double> &height, const std::initializer_list<double> &weight)
        : name(name), age(age), height(height), weight(weight) {}
    Patient(const Patient &other)
        : name(other.name), age(other.age), height(other.height), weight(other.weight) {}
    Patient(Patient &&other) noexcept
        : name(std::move(other.name)), age(other.age), height(std::move(other.height)), weight(std::move(other.weight)) {}
    ~Patient() {}

    Patient &operator=(const Patient &other);

    string getName() const { return name; }
    void setName(const string &name) { this->name = name; }
    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }
    vector<double> getHeight() const { return height; }
    void setHeight(const vector<double> &height) { this->height = height; }
    vector<double> getWeight() const { return weight; }
    void setWeight(const vector<double> &weight) { this->weight = weight; }

    void display();

    bool operator<(const Patient &other);
    Patient operator+(const Patient &other);

    Patient &operator++();
    Patient operator++(int);

    friend ostream &operator<<(ostream &os, const Patient &patient);
    friend istream &operator>>(istream &is, Patient &patient);
    int averageState() const;
};

#endif

