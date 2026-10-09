// Задание 3. Меню и скидка за объем.

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
        return 0;
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
            return 0;
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
