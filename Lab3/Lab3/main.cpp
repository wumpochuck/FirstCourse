/*
Задача 3.13
Функция char* poisrWord( char* str, int& len)  получает строку str (в ней могут быть пробелы), и ищет в этой строке первое «слово» (последовательность значащих символов, ограниченную пробелами). Функция через возвращаемое значение возвращает  адрес найденного «слова» и через параметр по ссылке его длину.  Если «слова» в строке нет, то возвращается длина «слова», равная 0 и адрес 0 .
Функция char* poisrWord Min( char* str, int& len)   получает строку с пробелами - фразу, состоящую из «слов»,  разделенных одним или  более  пробелами, и, с помощью функции poisrWord, определяет адрес первого самого короткого «слова» и его длину. Если в строке найдено всего одно «слово», то функция возвращает  адресный 0 и его длину.

Программа с клавиатуры вводит последовательно несколько фраз (строк с пробелами) и для каждой из фраз определяет первое слово, имеющее  минимальную длину. Если такое слово найдено, то оно выдается на экран, если же слово во фразе единственное, то об этом выдается сообщение и указывается его длина.
Для ввода строки с пробелами используйте стандартную потоковую функцию   istream&  get(char* str,   int len, char = '\n').
*/



#include <iostream>

using namespace std;

char* poisrWord(char* str, int& len);
char* poisrWordMin(char* str, int& len);

#include <iostream>

using namespace std;

int len = 0;

int main(){
    setlocale(LC_ALL, "russian");
    
    cout << "Введите количество строк: ";
    int count; cin >> count; cin.ignore();
    
    char** str = new char*[6];
    for(int i = 0; i < count; i++){
        
        // Ввод фраз
        *(str+i) = new char[100];
        cout << "Введите "<<i+1<<"ую строку:";
        cin.get(*(str+i), 100, '\n');
        cin.ignore();
    }
    
    // Проверка каждой фразы
    for(int i = 0; i < count; i++){
        cout << endl << "\nСтрока "<<i+1<<":\n";
        
        char* minimalword = poisrWordMin(*(str+i), len);
        // Проверка на то что слов в строке вообще нету????
        
        if(minimalword == 0){
            if(len != 0) {cout << "Слово в строке единственное, его длина:" << len << endl;}
            else cout << "Слов в строке нет (Строка состоит только из пробелов)" << endl;
        }
        else{
            *(minimalword+len) = '\0';
            cout << "Первое минимальное слово: " << minimalword << endl;
            cout << "Длина минимального: " << len << endl;
        }
        
    }
}

char* poisrWord(char* str, int& len){
    len = 0;
    char* word;
    
    // Пока пробел двигаю
    while(*str == ' ') str++;
    if(*str == '\0') return 0;
    // Запоминаю указатель на первое слово
    word = str;
    
    // Считаю длину
    while(*word != ' ' && *word != '\0') { word++; len++; }
        
    return str;
}


char* poisrWordMin(char* str, int& len){
    
    int minLen = 1000;
    char* minWord = 0;
    int countOfWords = 0;
    
    while (*str) {
        
        char* temp = poisrWord(str, len);
        if(temp == 0) {len = 0; return 0;}
        
        countOfWords++;
        //cout << "Количество слов - " << countOfWords << " \n";
        if (len < minLen) {
            minLen = len;
            minWord = temp;
        }
        str = temp+len+1;
    }
    
    len = minLen;
    
    if(countOfWords == 1) return 0;
    return minWord;
}
