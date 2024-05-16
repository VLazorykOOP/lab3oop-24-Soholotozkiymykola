#include <iostream>
#include <cstring>

using namespace std;

class Multiset {
private:
    unsigned int* set; // Масив для збереження елементів мультисету
    unsigned int beg; // Початкове значення діапазону
    unsigned int end; // Кінцеве значення діапазону

public:
    // Конструктор за замовчуванням
    Multiset() : set(nullptr), beg(0), end(100) {
        allocateMemory();
        initializeSet(0);
    }

    // Конструктор з одним параметром (тільки кінцеве значення діапазону)
    Multiset(unsigned int e) : set(nullptr), beg(0), end(e) {
        allocateMemory();
        initializeSet(0);
    }

    // Конструктор з двома параметрами (початкове і кінцеве значення діапазону)
    Multiset(unsigned int b, unsigned int e) : set(nullptr), beg(b), end(e) {
        allocateMemory();
        initializeSet(0);
    }

    // Конструктор з трьома параметрами (початкове, кінцеве значення діапазону і початкове значення елементів)
    Multiset(unsigned int b, unsigned int e, unsigned int value) : set(nullptr), beg(b), end(e) {
        allocateMemory();
        initializeSet(value);
    }

    // Конструктор копіювання
    Multiset(const Multiset& other) : set(nullptr), beg(other.beg), end(other.end) {
        allocateMemory();
        copySet(other.set);
    }

    // Оператор присвоювання
    Multiset& operator=(const Multiset& other) {
        if (this != &other) { // Перевірка на самоприсвоювання
            delete[] set;
            beg = other.beg;
            end = other.end;
            allocateMemory();
            copySet(other.set);
        }
        return *this;
    }

    // Деструктор
    ~Multiset() {
        delete[] set;
    }

    // Встановлення значення елемента за індексом
    void setValue(unsigned int index, unsigned int value = 0) {
        if (index < end - beg) {
            set[index] = value;
        }
    }

    // Отримання значення елемента за індексом
    unsigned int getCount(unsigned int index) const {
        if (index < end - beg) {
            return set[index];
        }
        return 0; // Додано значення за замовчуванням у разі неправильного індексу
    }

    // Вивід елементів мультисету
    void print() const {
        cout << "Multiset: [ ";
        for (unsigned int i = 0; i < end - beg; ++i) {
            cout << set[i] << " ";
        }
        cout << "]" << endl;
    }

    // Об'єднання двох мультисетів
    Multiset merge(const Multiset& other) const {
        unsigned int newBeg = min(beg, other.beg);
        unsigned int newEnd = max(end, other.end);
        Multiset result(newBeg, newEnd);

        // Копіювання елементів з першого мультисету
        for (unsigned int i = 0; i < end - beg; ++i) {
            result.setValue(i + (beg - newBeg), set[i]);
        }

        // Додавання елементів з другого мультисету
        for (unsigned int i = 0; i < other.end - other.beg; ++i) {
            result.setValue(i + (other.beg - newBeg), result.getCount(i + (other.beg - newBeg)) + other.getCount(i));
        }

        return result;
    }

    // Перетин двох мультисетів
    Multiset intersection(const Multiset& other) const {
        unsigned int newEnd = min(end, other.end);
        Multiset result(beg, newEnd);

        // Обчислення мінімального значення для кожного елемента
        for (unsigned int i = 0; i < newEnd - beg; ++i) {
            result.setValue(i, min(set[i], other.getCount(i)));
        }

        return result;
    }

    // Порівняння мультисетів за загальною сумою елементів
    bool greaterThan(const Multiset& other) const {
        return countTotal() > other.countTotal();
    }
    bool lessThan(const Multiset& other) const {
        return countTotal() < other.countTotal();
    }

    // Перевірка на рівність
    bool equalTo(const Multiset& other) const {
        if (end - beg != other.end - other.beg) {
            return false;
        }
        for (unsigned int i = 0; i < end - beg; ++i) {
            if (set[i] != other.set[i]) {
                return false;
            }
        }
        return true;
    }

    // Перевірка на нерівність
    bool notEqualTo(const Multiset& other) const {
        return !equalTo(other);
    }

private:
    // Виділення пам'яті для зберігання елементів
    void allocateMemory() {
        set = new unsigned int[end - beg];
    }

    // Ініціалізація елементів початковим значенням
    void initializeSet(unsigned int value) {
        for (unsigned int i = 0; i < end - beg; ++i) {
            set[i] = value;
        }
    }

    // Копіювання елементів з іншого мультисету
    void copySet(const unsigned int* otherSet) {
        memcpy(set, otherSet, (end - beg) * sizeof(unsigned int));
    }

    // Обчислення загальної суми елементів мультисету
    unsigned int countTotal() const {
        unsigned int total = 0;
        for (unsigned int i = 0; i < end - beg; ++i) {
            total += set[i];
        }
        return total;
    }
};

int main() {
    Multiset set1(0, 10, 2); // Створення мультисету з початковим значенням 2 для кожного елемента
    Multiset set2(5, 15, 3); // Створення мультисету з початковим значенням 3 для кожного елемента

    // Вивід першого мультисету
    cout << "Set 1:" << endl;
    set1.print();

    // Вивід другого мультисету
    cout << "\nSet 2:" << endl;
    set2.print();

    // Об'єднання двох мультисетів
    Multiset mergedSet = set1.merge(set2);
    cout << "\nMerged Set:" << endl;
    mergedSet.print();

    // Перетин двох мультисетів
    Multiset intersectionSet = set1.intersection(set2);
    cout << "\nIntersection Set:" << endl;
    intersectionSet.print();

    // Порівняння мультисетів
    cout << "\nSet 1 > Set 2: " << (set1.greaterThan(set2) ? "true" : "false") << endl;
    cout << "Set 1 < Set 2: " << (set1.lessThan(set2) ? "true" : "false") << endl;
    cout << "Set 1 == Set 2: " << (set1.equalTo(set2) ? "true" : "false") << endl;
    cout << "Set 1 != Set 2: " << (set1.notEqualTo(set2) ? "true" : "false") << endl;
    return 0;
}
//Друге завдання