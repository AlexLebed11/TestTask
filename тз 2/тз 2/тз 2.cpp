#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> numbers;  // Вектор для начальных чисел
    string str;            // Строка для ввода чисел
    vector<int> numbers1;   // Вектор для разницы чисел
    int x, y, f = 0, t = 0, num; //Переменные для расчета последних 3-х чисел, проверки и для заполнения

    while (f < 1) //Проверка правильности введенной строки чисел
    {
        numbers.clear();
        t = 0;

        cout << "Введите числа (не меньше трех и не больше 9), разделенные пробелами\n Каждое последующее число должно быть больше предыдущего: ";
        getline(cin, str); // Считываем всю строку
        istringstream ss(str); // Создаем поток для разбора строки             
        while (ss >> num) { numbers.push_back(num); }
        
        for (char c : str) { if ((c >= '0' && c <= '9') || c == ' ') { t++; } }        

        if ( numbers.size() >= 3 && numbers.size() <= 9 && t == str.size())
        {
            t = 0;
            for (int i = 0; i < numbers.size() - 1; i++)
            {
                if ((numbers.at(i) <= numbers.at(i + 1))) { t++; }               
            }
        }
        else { t = -100; }

        if (t == numbers.size() - 1) { f++; }
        else { cout << "Числа введены неверно!" << endl; }
    }

    if ((numbers.at(1) - numbers.at(0)) == (numbers.at(2) - numbers.at(1))) //проверка первой разницы
    {
        x = numbers.at(2) - numbers.at(1);
        for (int i = 1; i < 4; i++) { cout << numbers.back() + x * i << " "; }
    }
    else 
    {
        for (int i = 0; i < numbers.size() - 1; i++) // Заполнение числавми первой разницы если они не одинаковы
        {
            numbers1.push_back(numbers.at(i+1) - numbers.at(i));            
        } 

        if (numbers1.size() >= 3) // Проверка второй разницы
        {
            if ((numbers1.at(1) - numbers1.at(0)) == (numbers1.at(2) - numbers1.at(1)))  // Проверка второй разницы 
            {
                x = numbers1.at(1) - numbers1.at(0);
                y = numbers.back();
                for (int i = 1; i < 4; i++)
                {
                    if (y == numbers.back())
                    {
                        cout << y + numbers1.at(0) + x * (numbers1.size() - 1) + x * i << " ";
                        y = y + numbers1.at(0) + x * (numbers1.size() - 1) + x * i;
                    }
                    else
                    {
                        cout << y + numbers1.at(0) + x * (numbers1.size() - 1) + x * i << " ";
                        y = y + numbers1.at(0) + x * (numbers1.size() - 1) + x * i;
                    }
                }
            }
            else
            {
                cout << "\nВведены числа у которых одинаковая n-я разница больше 2" << endl;
                return 0;
            }
        }
        else
        {
            cout << "\nРазницу чисел не возможно измерить" << endl;
            return 0;
        }
    }    
    return 0;
}