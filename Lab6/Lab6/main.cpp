/*
  Задача 6.20
  Составить функцию, которая каждую  восьмеричную цифру, заданную кодом ASCII,
  шифрует, используя двоично-десятичный код «1 из 8».
  Используя разработанную функцию, составить функцию, которая кодирует и
  раскодирует строку, состоящую из восьмеричных цифр.
*/

#include <iostream>
#include <bitset>   // Для перевода и выводи битов
//#include <climits>
#include <string>
#include <cmath>
//#include <ostream>
//#include <algorithm>
//-------------------------------------//

using namespace std;
char fields_coder(int n);
int fields_decoder(char a);
int DecToOct(int dec);
void bitFields();
void logics();

//-------------------------------------//

struct bits {
    unsigned int n0 : 3;
    unsigned int n1 : 3;
    unsigned int n2 : 3;
    unsigned int n3 : 3;
    unsigned int n4 : 3;
    string s1, s2, s3, s4, bin;
    int x, i, j;
};

//const string alphabet[] = { "00000000","00000010","00000100","00001000",
//                           "00010000","00100000","01000000","10000000" };

//-------------------------------------//

int main() {
    setlocale(LC_ALL, "ru");
    int flag = -1;

    while (flag != 0) {
        cout << "Введите 1 для решения с помощью логических операций" << endl;
        cout << "Введите 2 для решения через структуру битовых полей" << endl;
        cout << "Введите 0 для прекращения работы" << endl;
        cin >> flag;
        switch (flag) {
        case 1: {logics(); break; }
        case 2: {bitFields(); break; }
        case 0: {cout << "Программа завершила работу!"; break; }
        }
    }
}

//-------------------------------------// АЛГОРИТМЫ

void logics() {
    // Ввод десятеричного, перевожу в восьмеричную, кодирую, раскодирую
    int x;
    cout << "Введите число меньше или равное 4095: ";
    cin >> x;

    while (x > 4095) {
        cout << "Введено неверное число, введи заново: ";
        cin >> x;
    }

    // Переделываю десятеричное в восьмеричное
    int number = DecToOct(x);

    //--------------------------------------------------// Закодировываю
    
    // {000000001, 000000001, 000000001, 000000001} - для того чтобы потом двигать единичку
    char coded_number[] = { 0x01, 0x01, 0x01, 0x01 };

    for (int i = 0; i < sizeof(number); i++) {
        
        // Проверка на 0 (Если 0 , то элемент массива 0х00
        if (number % 10 == 0) {
            coded_number[i] = 0x00;
        }
        // Если не ноль, двигаем единичку
        else {
            coded_number[i] = coded_number[i] << (number % 10);
            number /= 10;
        }
    }

    // Удаление лишних нулей (если таковы есть)
    // (В случае, когда в восьмеричной записи меньше 4х цифр)
    int i = 3;
    while (coded_number[i] == 0x00) {
        i--;
        if (i == -1) break;
    }
    // Индекс для будущего раскодировывания
    int j = i;

    cout << "Закодированная запись числа: ";
    for (i; i >= 0; i--) {
        // Строка, которая выводит биты данной штуки в массиве
        cout << bitset<sizeof(coded_number[i]) * CHAR_BIT>(coded_number[i]) << " ";
    }
    cout << endl;

    //--------------------------------------------------// Раскодировываю

    cout << "Раскодированная запись: ";
    for (j; j >= 0; j--) {
        cout << fields_decoder(coded_number[j]);
    }

    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
}

//-------------------------------------//

int DecToOct(int dec) {
    int i = 0; int bin = 0;
    while (dec > 1)
    {
        bin += (dec % 8)*pow(10, i);
        dec /= 8;
        i++;
    }
    bin += dec*pow(10, i);
    return bin;
}

//-------------------------------------// БИТОВЫЕ ПОЛЯ

void bitFields() {
    // Объявляю структурку.
    bits d;
    cout << "Введите число меньше или равное 4095: ";
    cin >> d.x;

    while (d.x > 4095) {
        cout << "Введено неверное число, введи заново: ";
        cin >> d.x;
    }

    // Переписываю число в двоичном виде
    d.bin = bitset<12>(d.x).to_string();

    // Беру по 3 цифры из двоичного вида и переписываю их в восьмеричный
    d.s1.push_back(d.bin[9]); d.s1.push_back(d.bin[10]); d.s1.push_back(d.bin[11]);
    d.n1 = stoi(d.s1);
    d.s2.push_back(d.bin[6]); d.s2.push_back(d.bin[7]); d.s2.push_back(d.bin[8]);
    d.n2 = stoi(d.s2);
    d.s3.push_back(d.bin[3]); d.s3.push_back(d.bin[4]); d.s3.push_back(d.bin[5]);
    d.n3 = stoi(d.s3);
    d.s4.push_back(d.bin[0]); d.s4.push_back(d.bin[1]); d.s4.push_back(d.bin[2]);
    d.n4 = stoi(d.s4);

    // Закодировавыю каждую восьмеричную цифру
    char* shifr = new char[4];
    shifr[0] = fields_coder(d.n1);
    shifr[1] = fields_coder(d.n2);
    shifr[2] = fields_coder(d.n3);
    shifr[3] = fields_coder(d.n4);

    // Удаление лишних нулей (если таковы есть)
    // (В случае, когда в восьмеричной записи меньше 4х цифр)
    d.i = 3;
    while (shifr[d.i] == 0x00) {
        d.i--;
        if (d.i == -1) break;
    }
    d.j = d.i;

    cout << "Закодированная запись числа: ";
    if (d.i == -1) {
        cout << "00000000";
    }
    else {
        for (d.i; d.i >= 0; d.i--) {
            cout << bitset<sizeof(shifr[d.i]) * CHAR_BIT>(shifr[d.i])          << " ";
        }
    }

    cout << endl << "Раскодированная запись: ";
    if (d.j == -1) {
        cout << 0;
    }
    else {
        for (d.j; d.j >= 0; d.j--) {
            cout << fields_decoder(shifr[d.j]);
        }
    }

    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
}

//-------------------------------------//

char fields_coder(int n) {
    switch (n) {
    case 0: return 0x00; // 0000 0000
    case 1: return 0x02; // 0000 0010
    case 2: return 0x04; // 0000 0100
    case 3: return 0x08; // 0000 1000
    case 4: return 0x10; // 0001 0000
    case 5: return 0x20; // 0010 0000
    case 6: return 0x40; // 0100 0000
    case 7: return 0x80; // 1000 0000
    }
    return 0;
}

//-------------------------------------//

int fields_decoder(char a) {
    switch (a) {
    case 0x00: return 0; // 0000 0000
    case 0x02: return 1; // 0000 0010
    case 0x04: return 2; // 0000 0100
    case 0x08: return 3; // 0000 1000
    case 0x10: return 4; // 0001 0000
    case 0x20: return 5; // 0010 0000
    case 0x40: return 6; // 0100 0000
    default: return 7;   // 1000 0000
    }
}
