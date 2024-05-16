﻿#include <iostream>
#include <cmath>

using namespace std;

class Cube {
private:
    double side; // Приватна змінна-член для довжини сторони куба
    string color; // Приватна змінна-член для кольору куба

public:
    // Конструктори
    Cube() : side(0), color("білий") {} // Конструктор за замовчуванням, ініціалізує сторону нулем і колір "білий"
    Cube(double s, const string& c) { // Параметризований конструктор з параметрами довжини сторони та кольору
        if (s > 0) { // Перевірка, чи довжина сторони є позитивною
            side = s; // Присвоєння заданої довжини сторони
        }
        else { // Якщо довжина сторони не є позитивною
            cout << "Помилка: Довжина сторони має бути позитивною. Встановлення значення за замовчуванням 0." << endl; // Виведення повідомлення про помилку
            side = 0; // Встановлення довжини сторони в значення за замовчуванням 0
        }
        color = c; // Присвоєння заданого кольору
    }

    // Функції-члени для обчислення властивостей куба
    double surfaceArea() const { // Метод для обчислення площі поверхні куба
        return 6 * side * side; // Формула для площі поверхні куба
    }

    double volume() const { // Метод для обчислення об'єму куба
        return side * side * side; // Формула для об'єму куба
    }

    double diagonalLength() const { // Метод для обчислення довжини діагоналі куба
        return sqrt(3) * side; // Формула для довжини діагоналі куба
    }

    double inscribedSphereVolume() const { // Метод для обчислення об'єму вписаної у куб сфери
        return (4.0 / 3.0) * 3.14 * pow(side / 2, 3); // Формула для об'єму сфери
    }

    // Методи-сеттери
    void setSide(double s) { // Метод для встановлення довжини сторони куба
        if (s > 0) { // Перевірка, чи довжина сторони є позитивною
            side = s; // Присвоєння заданої довжини сторони
        }
        else { // Якщо довжина сторони не є позитивною
            cout << "Помилка: Довжина сторони має бути позитивною." << endl; // Виведення повідомлення про помилку
        }
    }

    void setColor(const string& c) { // Метод для встановлення кольору куба
        color = c; // Присвоєння заданого кольору
    }

    // Методи-геттери
    double getSide() const { // Метод для отримання довжини сторони куба
        return side; // Повернення довжини сторони
    }

    string getColor() const { // Метод для отримання кольору куба
        return color; // Повернення кольору
    }

    // Метод для виведення властивостей куба
    void print() const {
        cout << "Властивості куба:" << endl; // Виведення заголовка для властивостей куба
        cout << "Довжина сторони: " << side << endl; // Виведення довжини сторони
        cout << "Колір: " << color << endl; // Виведення кольору
        cout << "Площа поверхні: " << surfaceArea() << endl; // Виведення площі поверхні
        cout << "Об'єм: " << volume() << endl; // Виведення об'єму
        cout << "Довжина діагоналі: " << diagonalLength() << endl; // Виведення довжини діагоналі
        cout << "Об'єм вписаної сфери: " << inscribedSphereVolume() << endl; // Виведення об'єму вписаної сфери
    }
};

int main() {
    Cube cube1(5, "синій"); // Створення об'єкту куба з довжиною сторони 5 та кольором синій
    cube1.print(); // Виведення властивостей куба

    cube1.setSide(7); // Встановлення довжини сторони куба на 7
    cube1.setColor("червоний"); // Встановлення кольору куба на червоний
    cube1.print(); // Виведення властивостей куба

    return 0; // Повернення успішного завершення програми
}
//Перше завдання