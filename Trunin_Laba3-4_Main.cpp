#include "Trunin_Laba3-4_Methods.cpp"
#include <ctime>
#include <functional>
#include <iostream>
#include <map>

using namespace std;

// Структура для элемента меню
struct MenuItem {
  string title;
  function<void()> action;
};

int main() {
  // Генерация начального случайного значения
  srand(static_cast<unsigned>(time(NULL)));

  // Создание меню с использованием std::map
  map<int, MenuItem> menu = {
      {1, {"Input patient", []() { inputPatient(); }}},
      {2, {"Display all patients", []() {displayAllPatients();}}},
      {3, {"Demonstrate constructors", []() {demoConstructors();}}},
      {4, {"Demonstrate methods", []() {demoMethods();}}},
      {5, {"Sort patients by age", []() { sortPatientsByAge(); }}},
  };

  unsigned choice = 0; // Переменная для хранения выбора пользователя

  cout << "Menu: " << endl;
  // Вывод всех пунктов меню
  for (const auto &item : menu) {
    cout << "Task " << item.first << ". " << item.second.title << endl;
  }
  cout << "0. Exit" << endl; // Пункт для выхода из программы

  while (true) {
    int choice_signed;
    EnterNumber(choice_signed, "Enter the task number: ");
    choice = static_cast<unsigned>(choice_signed);
    // Выход из программы, если выбран пункт 0
    if (choice == 0) {
      cout << "2025 Your Name" << endl;
      break;
    }
    cout << endl << "=========Action:===========" << endl;

    // Проверка, существует ли выбранный пункт меню
    if (menu.find(choice) != menu.end()) {
      menu[choice].action(); // Выполнение действия, связанного с пунктом меню
    } else {
      cout << "Incorrect input."
           << endl; // Сообщение об ошибке, если пункт не найден
    }
    cout << endl; // Отступ для красоты
  }
  return 0; // Завершение программы
}