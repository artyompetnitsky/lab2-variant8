// =============================================================================
// Лабораторная работа, вариант 8 «Кафе». Задание 3.
// Меню: цена порции по коду блюда и скидка за объём.
//
// Входные данные:
//   code     - код блюда: M - основное, S - суп, D - десерт;
//   portions - количество порций от 1 до 20.
//
// Правила:
//   цена одной порции через switch: M = 9, S = 6, D = 4;
//   portions >= 5 - скидка 8 % на блюда.
//
// Результат: название категории, стоимость до скидки и итоговая сумма.
// =============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
    char code;
    int portions;

    cout << "Введите код блюда (M - основное, S - суп, D - десерт): ";
    cin >> code;

    cout << "Введите количество порций (1..20): ";
    cin >> portions;

    if (portions < 1 || portions > 20) {
        cout << "Ошибка: количество порций должно быть от 1 до 20." << endl;
        return 1;
    }

    double price = 0.0;
    string name;

    switch (code) {
        case 'M':
            price = 9.0;
            name = "Основное блюдо";
            break;
        case 'S':
            price = 6.0;
            name = "Суп";
            break;
        case 'D':
            price = 4.0;
            name = "Десерт";
            break;
        default:
            cout << "Ошибка: неизвестный код блюда." << endl;
            return 1;
    }

    double before = price * portions;
    double after = before;

    if (portions >= 5) {
        after = before - before * 0.08;
    }

    cout << "Категория: " << name << endl;
    cout << "Стоимость до скидки: " << before << endl;
    cout << "Итого: " << after << endl;

    return 0;
}