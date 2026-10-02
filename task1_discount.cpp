// Задание 1. Скидка на заказ.

#include <iostream>
using namespace std;

int main() {
    double cost;
    int isStudent;

    cout << "Введите стоимость заказа: ";
    cin >> cost;

    cout << "Студент (1 - да, 0 - нет): ";
    cin >> isStudent;

    if (cost < 0) {
        cout << "Ошибка: стоимость заказа не может быть отрицательной." << endl;
        return 1;
    }

    if (isStudent != 0 && isStudent != 1) {
        cout << "Ошибка: признак студента должен быть 0 или 1." << endl;
        return 1;
    }

    // Скидка по стоимости заказа
    double discount = 0.0;

    if (cost >= 60) {
        discount = 10.0;
    }
    else if (cost >= 30) {
        discount = 5.0;
    }

    // Студенческая скидка, если она больше
    if (isStudent == 1 && 7.0 > discount) {
        discount = 7.0;
    }

    double total = cost - cost * discount / 100.0;

    cout << "Стоимость заказа: " << cost << endl;
    cout << "Выбранная скидка: " << discount << " %" << endl;
    cout << "Итоговая сумма: " << total << endl;

    return 0;
}
