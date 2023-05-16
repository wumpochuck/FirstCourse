/*
 Задача 2.16
 Составить функцию, которая получив  массив действительных чисел размером N и целое число К,  выполняет кольцевой сдвиг его элементов так, чтобы первый элемент этого массива оказался на  K-ом месте. Кольцевой сдвиг массива выполняется всеми его элементами так, что элементы “выталкиваемые” из массива в одну сторону занимают освободившиеся место с другой стороны.

 */



#include <iostream>

using namespace std;

void func_vvod_massive(float mas[], int n);
void func_vivod_massive(float mas[], int n);
//void func_static(int n,int k, float new_mas[], float mas[]);
void func_static(int n,int k, float mas[]);

int main() {
    setlocale(LC_ALL, "ru");
    int flag = 1;
    while(flag == 1){
        cout << "Введите числа N и K:\n";
        int n,k; cin >> n >> k;
        k %= n;
        cout << "Введите массив действительных чисел";
        float mas[100];
        func_vvod_massive(mas, n);
                                            //float new_mas[100];
                                            //func_static(n, k, new_mas, mas);
        func_static(n,k,mas);
        func_vivod_massive(mas, n);
        cout << "\nПовторить программу? (Yes - 1 / No - 0)\n";
        cin >> flag;
    }
}

void func_vvod_massive(float mas[], int n){
    for(int i = 0; i<n; i++){ // Ввод
        cin >> mas[i];
    }
}

void func_vivod_massive(float mas[], int n){
    for(int i = 0; i<n; i++){ // Вывод
        cout << mas[i] << " ";
    }
}
/*
void func_static(int n,int k, float new_mas[], float mas[]){
    int j = 0;
    for(int i = k-1; i < n; i++, j++){
        new_mas[i] = mas[j];
    }
    for(int i = 0; i < k-1; i++, j++){
        new_mas[i] = mas[j];
    }
}
*/
void func_static(int n,int k, float mas[]){
    for(int i = 0; i< k-1; i++){
        int temp = mas[n-1];
        for(int j = n-1; j > 0; j--){
            mas[j] = mas[j-1];
        }
        mas[0] = temp;
    }
}



