/*
 Задача 1.14
 Составить функцию, которая для целого числа вычисляет знакочередующуюся сумму цифр этого числа. Первая (левая) цифра берется всегда со знаком  +.
 Функция main() организует ввод заранее неизвестного числа целых чисел и выводит на  экран введенное число и знакочередующуюся сумму его цифр.
 */
#include <iostream>
#include <cmath>

using namespace std;

int counter(int a);
int func(int a);

int main() {
    setlocale(LC_ALL, "russian");
    string flag = "yes";
    while ((flag == "yes") or (flag == "Yes") or (flag == "1")) { // Многократное решение задачи
        cout << "Введите целое число\t";
        int a; cin >> a; a = abs(a);
        cout << "Знакочередующаяся сумма цифр числа равна: " << func(a) << endl;
        cout << "Повторить программу?\t yes/no\n"; cin >> flag;
    }
}


int func(int a) {
    int sum = 0;
    int cnt = counter(a);
    int b = 10, temp, p = 1;
    if (cnt % 2 == 0)p = -p; // Для четного/нечетного
    for (int i = 0; i < cnt; i++) {
        temp = a % b; temp *= p;
        sum += temp;
        a /= 10;
        //cout << "\n" << temp << "\n";
        p = -p;
    }
    return sum;
}

int counter(int a) {
    int cnt = 0;
    while (a != 0) {
        cnt++;
        a /= 10;
    }
    return cnt;
}








