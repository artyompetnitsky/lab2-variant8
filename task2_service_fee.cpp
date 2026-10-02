// Задание 2. Сервисный сбор.

#include <iostream>
using namespace std;

int main() {
    double dishCost;
    int persons;
    int tableService;

    cout << "Введите стоимость блюд: ";
    cin >> dishCost;

    cout << "Введите количество персон: ";
    cin >> persons;

    cout << "Обслуживание за столиком (1 - да, 0 - навынос): ";
    cin >> tableService;

    if (dishCost < 0) {
        cout << "Ошибка: стоимость блюд не может быть отрицательной." << endl;
        return 1;
    }

    if (persons <= 0) {
        cout << "Ошибка: количество персон должно быть положительным." << endl;
        return 1;
    }

    if (tableService != 0 && tableService != 1) {
        cout << "Ошибка: признак обслуживания должен быть 0 или 1." << endl;
        return 1;
    }

    double fee = 0.0;

    if (tableService == 1) {
        fee = dishCost * 0.10;

        if (fee < 2.0) {
            fee = 2.0;
        }

        if (dishCost >= 100.0) {
            fee = fee / 2.0;
        }
    }

    double total = dishCost + fee;

    cout << "Стоимость блюд: " << dishCost << endl;
    cout << "Сервисный сбор: " << fee << endl;
    cout << "Итого: " << total << endl;
    cout << "На человека: " << total / persons << endl;

    return 0;
}
