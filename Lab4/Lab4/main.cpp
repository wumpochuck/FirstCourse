/*

 Задача 4.21
  Составить программу, которая получает матрицу Х размером  m*n и вектор A, размером m.
  Если в векторе А  есть как положительные, так и отрицательные элементы, то программа
  создает новую матрицу. Строку с номером  i назовем отмеченной, если  соответствующий
  i элемент вектора  A больше 0, и неотмеченной – в противном случае. Программа формирует
  новую матрицу по следующему правилу: все  отрицательные  элементы в отмеченных строках
  исходной матрицы в формируемой матрице программа заменяет     отрицательной единицей,
  положительные заменяет положительной единицей, а нулевые остаются без изменений. Не
  отмеченные строки исходной матрицы копируются в новую  матрицу в обратном порядке.

 */


#include <iostream>

using namespace std;

void input_m_n(int& m, int& n);
void input_massive(int m, int n, int mas[][100]);
void input_massive_2(int n, int mas[]);
//void input_vektor(int m, int vektor[]);
int vektor_check(int m, int vektor[]);
int count_new_massive(int m, int n, int mas[][100], int new_mas[][100], int vektor[]);
void output_massive(int m, int n, int new_mas[][100]);
void output_massive_2(int n, int new_mas[]);

int main() {
    setlocale(LC_ALL, "rus");
    int flag = 1;
    while (flag == 1) {
        int m, n;
        input_m_n(m, n);
        int mas[100][100];
        input_massive(m, n, mas);
        int vektor[100];
        cout << "Введите вектор размером " << n << ": ";
        input_massive_2(n, vektor);
        //input_vektor(m, vektor);
        int new_mas[100][100];
        cout << "\nИсходный массив:\n";
        output_massive(m, n, mas);
        int flag1 = count_new_massive(m, n, mas, new_mas, vektor);
        if (flag1 == 1) {

            cout << "\nНовый массив:\n";
            output_massive(m, n, new_mas);
        }
        else cout << "\nНовый массив не создан. ";
        cout << "\nПовторить программу? (1/0)\t"; cin >> flag;
    }
}

void input_m_n(int& m, int& n) {
    cout << "Введите числа M и N (Размеры массива):\n";
    cin >> m >> n;
    while (((m <= 0) || (m > 100)) || ((m <= 0) || (m > 100))) {
        cout << "Введены неверные числа, введите повторно: ";
        cin >> m >> n;
    }
}

void input_massive_2(int n, int mas[]) {
    for (int j = 0; j < n; j++) {
        cin >> mas[j];
    }
}

void input_massive(int m, int n, int mas[][100]) {
    cout << "Введите массив размером " << m << " на " << n << endl;
    for (int i = 0; i < m; i++) {
        input_massive_2(n, mas[i]);
    }
}

//void input_vektor(int m, int vektor[]) {
//    cout << "Введите вектор размером " << m << endl;
//    for (int i = 0; i < m; i++) {
//        cin >> vektor[i];
//    }
//}

int vektor_check(int m, int vektor[]) { // Проверка вектора на положительные и отрицательные
    int x = 0, y = 0, flag = 1;
    for (int i = 0; i < m; i++) {
        if (vektor[i] > 0) x++;
        if (vektor[i] < 0) y++;
    }
    if (x == 0 || y == 0) flag = 0;
    return flag;
}

//void func_yes(int i,int n, int mas[][100], int new_mas[][100]) {
//    for (int j = 0; j < n; j++) {
//        if (mas[i][j] > 0) new_mas[i][j] = 1;
//        else if (mas[i][j] < 0) new_mas[i][j] = -1;
//        else  new_mas[i][j] = mas[i][j];
//    }
//}

void func_yes(int n, int mas[], int new_mas[]) {
    for (int j = 0; j < n; j++) {
        if (mas[j] > 0) new_mas[j] = 1;
        else if (mas[j] < 0) new_mas[j] = -1;
        else  new_mas[j] = mas[j];
    }
}

//void func_no(int i, int n, int mas[][100], int new_mas[][100]) {
//    for (int j = n - 1, k = 0; k < n; j--, k++) {
//        new_mas[i][j] = mas[i][k];
//    }
//}

void func_no(int n, int mas[], int new_mas[]) {
    for (int j = n - 1, k = 0; k < n; j--, k++) {
        new_mas[j] = mas[k];
    }
}


int count_new_massive(int m, int n, int mas[][100], int new_mas[][100], int vektor[]) {
    int flag = vektor_check(m, vektor); // Проверка вектора
    if (flag == 1)
    {
        for (int i = 0; i < m; i++) {
            if (vektor[i] > 0) {
                func_yes(n, mas[i], new_mas[i]);
            }
            else {
                func_no(n, mas[i], new_mas[i]);
            }
        }
    }
    return flag;
}



void output_massive_2(int n, int mas[]) {
    for (int j = 0; j < n; j++) {
        cout << mas[j] << " ";
    }
}

void output_massive(int m, int n, int mas[][100]) {
    //cout << "\nНовый массив: \n";
    for (int i = 0; i < m; i++) {
        output_massive_2(n, mas[i]);
        cout << endl;
    }
}
