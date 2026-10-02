// =============================================================================
// Лабораторная работа, вариант 8 «Кафе». Задание 4.
// Заказ с учётом скидок и стоимости доставки.
//
// Входные данные:
//   code      - код блюда: M - основное, S - суп, D - десерт;
//   portions  - количество порций от 1 до 20;
//   isStudent - признак студента: 1 - да, 0 - нет;
//   delivery  - признак доставки: 1 - да, 0 - нет.
//
// Правила:
//   цена одной порции через switch: M = 9, S = 6, D = 4;
//   portions >= 5 - скидка 8 %;
//   студент      - скидка 10 %, применяется только большая из двух;
//   доставка добавляет 5, но при сумме блюд после скидки от 50 - бесплатно.
//
// Результат: стоимость блюд, скидка, стоимость доставки и итоговая сумма.
// =============================================================================

#include <iostream>
using namespace std;

int main() {
    char code;
    int portions;
    int isStudent;
    int delivery;

    cout << "Введите код блюда (M - основное, S - суп, D - десерт): ";
    cin >> code;

    cout << "Введите количество порций (1..20): ";
    cin >> portions;

    cout << "Студент (1 - да, 0 - нет): ";
    cin >> isStudent;

    cout << "Доставка (1 - да, 0 - нет): ";
    cin >> delivery;

    if (portions < 1 || portions > 20) {
        cout << "Ошибка: количество порций должно быть от 1 до 20." << endl;
        return 1;
    }

    if (isStudent != 0 && isStudent != 1) {
        cout << "Ошибка: признак студента должен быть 0 или 1." << endl;
        return 1;
    }

    if (delivery != 0 && delivery != 1) {
        cout << "Ошибка: признак доставки должен быть 0 или 1." << endl;
        return 1;
    }

    double price = 0.0;

    switch (code) {
        case 'M':
            price = 9.0;
            break;
        case 'S':
            price = 6.0;
            break;
        case 'D':
            price = 4.0;
            break;
        default:
            cout << "Ошибка: неизвестный код блюда." << endl;
            return 1;
    }

    double cost = price * portions;

    // Скидки не складываются - берём максимальную
    double discount = 0.0;

    if (portions >= 5) {
        discount = 8.0;
    }

    if (isStudent == 1 && 10.0 > discount) {
        discount = 10.0;
    }

    double dishSum = cost - cost * discount / 100.0;

    // Доставка бесплатна, если сумма блюд после скидки от 50
    double deliveryCost = 0.0;

    if (delivery == 1 && dishSum < 50.0) {
        deliveryCost = 5.0;
    }

    double total = dishSum + deliveryCost;

    cout << "Стоимость блюд: " << cost << endl;
    cout << "Скидка: " << discount << " %" << endl;
    cout << "Сумма блюд после скидки: " << dishSum << endl;
    cout << "Доставка: " << deliveryCost << endl;
    cout << "Итого: " << total << endl;

    return 0;
}