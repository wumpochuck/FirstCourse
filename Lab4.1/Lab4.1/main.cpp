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
int** input_matrix(int m, int n);
int* input_massive(int n);
//int* input_vektor(int m);
int vektor_check(int m, int* vektor);
int** count_new_matrix(int m, int n, int** mas, int* vektor);
void output_matrix(int m, int n, int** new_mas);
void output_massive(int n, int* mas);
void** func_delete(int m, int** any_matrix);


int main() {
    setlocale(LC_ALL, "rus");
    int flag = 1;
    while (flag == 1) {
        int m, n;
        input_m_n(m, n);
        int** mas, **new_mas;
        cout << "Введите исходную матрицу:\n";
        mas = input_matrix(m, n);
        int* vektor;
        cout << "Введите вектор:\n";
        vektor = input_massive(m);
        cout << "\nИсходный массив:\n";
        output_matrix(m, n, mas);
        new_mas = count_new_matrix(m, n, mas, vektor);
        if (new_mas) {
            cout << "\nНовый массив:\n";
            output_matrix(m, n, new_mas);
        }
        else cout << "\nНовый массив не создан. ";
        func_delete(m, mas);
        func_delete(m, new_mas);
        cout << "\nПовторить программу? (1/0)\t"; cin >> flag;
    }
}


void input_m_n(int& m, int& n) {
    cout << "Введите числа M и N (Размеры массива):\n";
    cin >> m >> n;
}

int* input_massive(int n) {
    int* tempmassive;
    tempmassive = new int[n];
    for (int j = 0; j < n; j++) {
        cin >> *(tempmassive + j);
    }
    return tempmassive;
}

int** input_matrix(int m, int n) {
    //cout << "Введите массив размером " << m << " на " << n << endl;
    int** tempmatrix;
    tempmatrix = new int* [m]; // m =5 n = 4
    for (int i = 0; i < m; i++) {
        *(tempmatrix + i) = input_massive(n);
    }
    return tempmatrix;
}



int* input_vektor(int m) {
    int* tempvector;
    tempvector = new int[m];
    cout << "Введите вектор размером " << m << endl;
    for (int i = 0; i < m; i++) {
        cin >> *(tempvector + i);
    }
    return tempvector;
}

int vektor_check(int m, int* vektor) { // Проверка вектора на положительные и отрицательные
    int x = 0, y = 0, flag = 1;
    for (int i = 0; i < m; i++) {
        if (*(vektor + i) > 0) x++;
        if (*(vektor + i) < 0) y++;
    }
    if (x == 0 || y == 0) flag = 0;
    return flag;
}

//void func_yes(int i, int n, int** mas, int** new_mas) {
//    for (int j = 0; j < n; j++) {
//        if (*(*(mas + i) + j) > 0) *(*(new_mas + i) + j) = 1;
//        else if (*(*(mas + i) + j) < 0) *(*(new_mas + i) + j) = -1;
//        else  *(*(new_mas + i) + j) = *(*(mas + i) + j);
//    }
//}

//void func_no(int i, int n, int** mas, int** new_mas) {
//    for (int j = n - 1, k = 0; k < n; j--, k++) {
//        *(*(new_mas + i) + j) = *(*(mas + i) + j);
//    }
//}

int* func_yes(int n, int *mas) {
    int* new_mas = new int[n];
    for (int j = 0; j < n; j++) {
        if (*(mas + j) > 0) *(new_mas + j) = 1;
        else if (*(mas + j) < 0) *(new_mas + j) = -1;
        else *(new_mas + j) = *(mas + j);
    }
    return new_mas;
}

int* func_no(int n, int* mas) {
    int* new_mas = new int[n];
    for (int j = n - 1, k = 0; k < n; j--, k++) {
        *(new_mas + j) = *(mas + k);
    }
    return new_mas;
}

int** count_new_matrix(int m, int n, int **mas, int* vektor) {

    if (!vektor_check(m, vektor)) return 0; // Проверка вектора

    int** new_mas;
    new_mas = new int* [m];
    //for (int i = 0; i < m; i++) {
    //    *(new_mas + i) = new int[n];
    //}

    for (int i = 0; i < m; i++) {
        if (*(vektor + i) > 0) {
            *(new_mas+i) = func_yes(n, *(mas+i));
        }
        else {
            *(new_mas+i) = func_no(n, *(mas+i));
        }
    }
    return new_mas;
}

void output_massive(int n, int* mas) {
    for (int j = 0; j < n; j++) {
        cout << *(mas + j) << " ";
    }
}

void output_matrix(int m, int n, int** new_mas) {
    //cout << "\nНовый массив: \n";
    for (int i = 0; i < m; i++) {
        output_massive(n, *(new_mas + i));
        cout << endl;
    }
}


void func_delete2(int* any_massive){
    delete[] any_massive;
}

void func_delete(int m, int** any_matrix) {
    for (int i = 0; i < m; i++) {
        func_delete2(*(any_matrix + i));
    }
    delete any_matrix;
}



