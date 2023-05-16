/*
 Задача 2.16
 Составить функцию, которая получив  массив действительных чисел размером N и целое число К,  выполняет кольцевой сдвиг его элементов так, чтобы первый элемент этого массива оказался на  K-ом месте. Кольцевой сдвиг массива выполняется всеми его элементами так, что элементы “выталкиваемые” из массива в одну сторону занимают освободившиеся место с другой стороны.

 */



#include <iostream>

using namespace std;

float *func_vvod_massive(int n);
void func_vivod_massive(float *mas, int n);
void func_dynamic(int n,int k, float *mas);

int main() {
    setlocale(LC_ALL, "ru");
    int flag = 1;
    while(flag == 1){
        cout << "Введите числа N и K:\n";
        int n,k; cin >> n >> k;
        k %= n; // В случае если k-тое место превышает кол-во чисел в массиве
        cout << "Введите массив действительных чисел";
        float *mas;
        mas = func_vvod_massive(n);
        func_dynamic(n, k, mas);
        func_vivod_massive(mas, n);
        delete [] mas;  // Оператор очищения памяти
        cout << "\nПовторить программу? (Yes - 1 / No - 0)\n";
        cin >> flag;
    }
}

float *func_vvod_massive(int n){
    float *a = new float[n];
    for(int i = 0; i<n; i++){ // Ввод
        cin >> a[i];
    }
    return a;
}

void func_vivod_massive(float *mas, int n){
    for(int i = 0; i<n; i++){ // Вывод
        cout << mas[i] << " ";
    }
}

void func_dynamic(int n,int k, float *mas){
    for(int i = 0; i< k-1; i++){
        int temp = *(mas + n - 1);
        for(int j = n-1; j > 0; j--){
            *(mas + j) = *(mas + j - 1);
        }
        *(mas) = temp;
    }
}


