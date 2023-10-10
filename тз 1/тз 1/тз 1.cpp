#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> key; // Сохраненное значение кода
    vector<string> letter; // Сохраненное значение текста
    vector<char> lettercheck; // Переменная для проверки текста
    string str;   // Строка для ввода кода/текста
    string qqs;   // Строка для заполнения переменной letter в виде 2 буквы/1 буква
    int f = 0;  

    while (f < 1)                // Считывание и проверка кода со строки
    {
        key.clear();
        int t = 0, t1 = 0;
        cout << "Введите код : ";

        while (getline(cin, str) && !str.empty()) {
            for (int a : str) { key.push_back(a); }
        }

        for (int i = 0; i < key.size(); i++)
        { 
            if (key.at(i) == 0 || key.size() > 9) { t = -100; }
        }
        
        for (int i = 0; i < key.size(); i++)
        {            
           t1 = 0;
           for (int j = 0; j < key.size(); j++)
           {
              if (isdigit(key.at(j)))
              {
                 if (i != j)
                 {
                     if (key.at(i) != key.at(j)) { t1++; }
                 }
              }             
           }
           if (t1 == key.size() - 1) { t++; }          
        }      
        if (t == key.size()) { f++; }     
        else { cout << "Код неверный!" << endl; }                          
    }    

    f = 0; // Обнуление для новой проверки

    while (f < 1)    // Считывание и проверка текста со строки
    {
        letter.clear();
        lettercheck.clear();
        int t = 0, t1 = 0;

        cout << "Введите текст только в [A-Z] без знаков препинания\nДлина открытого текста ограничена 250: ";
        while (getline(cin, str) && !str.empty()) {
            for (char c : str) { lettercheck.push_back(c); }

            for (int i = 0; i < str.size(); i += 3) {
                if (i < str.size() && i + 1 < str.size())
                {
                    qqs = string(1, str[i]) + str[i + 1];
                    letter.push_back(qqs);
                }
                if (i + 2 < str.size())
                {
                    qqs = string(1, str[i + 2]);
                    letter.push_back(qqs);
                }
                if (i <= str.size() && i + 1 >= str.size())
                {
                    qqs = string(1, str[str.size() - 1]);
                    letter.push_back(qqs);
                }
            }
        }

        for (int i = 0; i < letter.size(); i++)
        {
           if (letter.size() > 250) { t = -100; }
        }

        for (int i = 0; i < lettercheck.size(); i++)
        {                    
           if (lettercheck.at(i) >= 'A' && lettercheck.at(i) <= 'Z') { t++; }                     
        }
        if (t == lettercheck.size()) { f++; }
        else { cout << "Текст введены не по правилам!" << endl; }        
    }

    //for (string c : letter) { cout << c << " "; }      // Вывод для проверки letter
    //cout << endl;

    int *queue = new int[key.size()];   // Переменная создана для того чтобы определять в какой последовательности будут выводится буквы из letter
    for (int i = 0; i < key.size(); i++)
    {
        if (i + 1 <= key.size())
        {
            for (int j = 0; j < key.size(); j++)
            {
                if (key.at(j) - 48 == i + 1) { queue[i] = j; }
            }
        }
    }
    
    for (int i = 0; i < key.size(); i++)                   // Вывод букв в зашифрованном виде
    {
        for (int j = 0; j < (letter.size() / key.size()) + 1; j++)
        {
            if ((queue[i] + key.size()*j) < letter.size()) {cout << letter.at(queue[i] + (key.size()) * j);}                   
        }
    }
    
    return 0;
}
