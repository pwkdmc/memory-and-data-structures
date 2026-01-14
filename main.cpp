#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>

// АНАЛИЗАТОР УСПЕВАЕМОСТИ ГРУППЫ

// Генерация массива случайных чисел
void GenerateArrayRating(int *student_grades, int size)
{
    for (int *current = student_grades; current < student_grades + size; ++current)
    {
        *current = rand() % 4 + 2;
    }
}

// Нахождение среднего арифметического элементов массива
double AverageScore(int *student_grades, int size)
{
    int sum = 0;
    for (int *current = student_grades; current < student_grades + size; ++current)
    {
        sum += *current;
    }
    return static_cast<double>(sum) / size;
}

// Подсчет элементов < 3
int NumberUnderachievers(int *student_grades, int size)
{
    int cnt = 0;
    for (int *current = student_grades; current < student_grades + size; ++current)
    {
        if (*current < 3)
            ++cnt;
    }
    return cnt;
}

// Нахождение процентного отношения количества элементов == 5 ко всем элементам
double PercentageExcellentStudents(int *student_grades, int size)
{
    int cnt = 0;
    for (int *current = student_grades; current < student_grades + size; ++current)
    {
        if (*current == 5)
            ++cnt;
    }
    return static_cast<double>(cnt) / size * 100;
}

// Нахождение моды элементов массива
int ModeSequences(int *student_grades, int size)
{
    // repeatability[i] - количество повторений оценки i + 2
    int repeatability[4] = {};
    for (int *current = student_grades; current < student_grades + size; ++current)
    {
        ++repeatability[*current - 2];
    }
    int max_repeat_grade = 2;
    for (int i = 3; i <= 5; ++i)
    {
        if (repeatability[max_repeat_grade - 2] < repeatability[i - 2])
            max_repeat_grade = i;
    }
    return max_repeat_grade;
}

// Интерактивный цикл для анализатора успеваемости группы
void GroupPerformanceAnalyzer()
{
    const int SIZE = 15;
    int student_grades[SIZE] = {};
    int issue_number;
    do
    {
        std::cout << std::endl
                  << "== АНАЛИЗАТОР УСПЕВАЕМОСТИ ГРУППЫ ==" << std::endl;
        std::cout << "Оценки группы студентов:" << std::endl;
        GenerateArrayRating(student_grades, SIZE);
        for (int i = 0; i < SIZE; ++i)
        {
            std::cout << student_grades[i] << " ";
        }
        std::cout << std::endl
                  << "Средний балл группы:" << std::endl;
        std::cout << AverageScore(student_grades, SIZE) << std::endl;
        std::cout << "Количество неуспевающих:" << std::endl;
        std::cout << NumberUnderachievers(student_grades, SIZE) << std::endl;
        std::cout << "Процент отличников:" << std::endl;
        std::cout << PercentageExcellentStudents(student_grades, SIZE) << "%" << std::endl;
        std::cout << "Самая частая оценка:" << std::endl;
        std::cout << ModeSequences(student_grades, SIZE) << std::endl;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// УМНЫЙ КАЛЬКУЛЯТОР С ИСТОРИЕЙ ОПЕРАЦИЙ

// Структура для хранения одной операции в истории
struct Calculation
{
    double first_number;
    double second_number;
    char operation;
    double result;
};

// Сложение через указатели
double Addition(double *first_number, double *second_number)
{
    return *first_number + *second_number;
}

// Вычитание через указатели
double Subtraction(double *first_number, double *second_number)
{
    return *first_number - *second_number;
}

// Деление через указатели
double Division(double *first_number, double *second_number)
{
    return *first_number / *second_number;
}

// Умножение через указатели
double Multiplication(double *first_number, double *second_number)
{
    return *first_number * *second_number;
}

// Остаток от деления через указатели
double Remainder(double *first_number, double *second_number)
{
    return static_cast<int>(*first_number) % static_cast<int>(*second_number);
}

// Обработка задачи для арифметических операций с числами
void ArithmeticOperationsWithNumbers(int *number_saved_operations, Calculation *history)
{
    int issue_number = 1;
    double first_number;
    double second_number;
    char operation;
    do
    {
        std::cout << std::endl
                  << "= АРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ С ЧИСЛАМИ =" << std::endl;
        std::cout << "Введите первое число:" << std::endl;
        std::cin >> first_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            first_number = -1;
        }
        std::cout << "Введите второе число:" << std::endl;
        std::cin >> second_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            second_number = -1;
        }
        std::cout << "Введите операцию (+, -, *, /, %):" << std::endl;
        std::cin >> operation;
        std::cin.ignore(10000, '\n');
        if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%')
        {
            std::cout << "ОШИБКА: Введен некорректный символ" << std::endl;
            continue;
        }
        if ((operation == '/' || operation == '%') && second_number == 0)
        {
            std::cout << "ОШИБКА: Деление на 0" << std::endl;
            continue;
        }
        if (operation == '%' && ((static_cast<int>(first_number) != first_number) || (static_cast<int>(second_number) != second_number)))
        {
            std::cout << "ОШИБКА: Остаток от деления нецелочисленных типов" << std::endl;
            continue;
        }
        std::cout << "Результат:" << std::endl;
        double result;
        if (operation == '+')
        {
            result = Addition(&first_number, &second_number);
        }
        else if (operation == '-')
        {
            result = Subtraction(&first_number, &second_number);
        }
        else if (operation == '/')
        {
            result = Division(&first_number, &second_number);
        }
        else if (operation == '*')
        {
            result = Multiplication(&first_number, &second_number);
        }
        else if (operation == '%')
        {
            result = Remainder(&first_number, &second_number);
        }
        std::cout << result << std::endl;
        if (*number_saved_operations < 5)
            ++*number_saved_operations;
        // Сдвиг операций в истории на 1
        // Нулевой элемент остается свободным для новой операции, последний не сохраняется
        for (Calculation *current = history + 4; current > history; --current)
        {
            (*current).first_number = (*(current - 1)).first_number;
            (*current).second_number = (*(current - 1)).second_number;
            (*current).operation = (*(current - 1)).operation;
            (*current).result = (*(current - 1)).result;
        }
        // Запись текущей операции в историю
        (*history).first_number = first_number;
        (*history).second_number = second_number;
        (*history).operation = operation;
        (*history).result = result;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Вывод истории операций
void HistoryOperations(int *number_saved_operations, Calculation *history)
{
    int issue_number;
    do
    {
        std::cout << std::endl
                  << "= ИСТОРИЯ ОПЕРАЦИЙ =" << std::endl;
        for (Calculation *current = history; current < history + *number_saved_operations; ++current)
        {
            std::cout << current - history + 1 << ". " << (*current).first_number << " " << (*current).operation << " " << (*current).second_number << " = " << (*current).result << std::endl;
        }
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Обмен значений переменных через указатели
void ExchangeValues(double *var_a, double *var_b)
{
    double temp = *var_a;
    *var_a = *var_b;
    *var_b = temp;
}

// Обработка задачи для обмена значений переменных
void ExchangeVariableValues()
{
    int issue_number;
    do
    {
        std::cout << std::endl
                  << "= ОБМЕН ЗНАЧЕНИЙ ПЕРЕМЕННЫХ =" << std::endl;
        double var_a;
        double var_b;
        std::cout << "Введите значение первой переменной (var_a):" << std::endl;
        std::cin >> var_a;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            var_a = -1;
        }
        std::cout << "Введите значение второй переменной (var_b):" << std::endl;
        std::cin >> var_b;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            var_b = -1;
        }
        std::cout << "var_a = " << var_a << ", var_b = " << var_b << std::endl;
        ExchangeValues(&var_a, &var_b);
        std::cout << "Результат:" << std::endl;
        std::cout << "var_a = " << var_a << ", var_b = " << var_b << std::endl;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Поиск минимума в последовательности чисел через указатели
double FindMin(double *numbers, int size)
{
    double min = *numbers;
    for (double *current = numbers; current < numbers + size; ++current)
    {
        if (*current < min)
            min = *current;
    }
    return min;
}

// Поиск максимума в последовательности чисел через указатели
double FindMax(double *numbers, int size)
{
    double max = *numbers;
    for (double *current = numbers; current < numbers + size; ++current)
    {
        if (*current > max)
            max = *current;
    }
    return max;
}

// Обработка задачи для поиска минимального и максимального из чисел
void FindMaxMin()
{
    int size;
    int issue_number = 1;
    do
    {
        std::cout << std::endl
                  << "= ПОИСК МИНИМАЛЬНОГО И МАКСИМАЛЬНОГО ИЗ ЧИСЕЛ =" << std::endl;
        std::cout << "Введите количество чисел:" << std::endl;
        std::cin >> size;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            size = -1;
        }
        if (size <= 0)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            continue;
        }
        double *numbers = new double[size];
        std::cout << "Введите " << size << " чисел:" << std::endl;
        for (double *current = numbers; current < numbers + size; ++current)
        {
            std::cin >> *current;
            if (std::cin.fail())
            {
                std::cin.clear();
                *current = -1;
            }
        }
        std::cin.ignore(10000, '\n');
        std::cout << "Минимальное число:" << std::endl;
        std::cout << FindMin(numbers, size) << std::endl;
        std::cout << "Максимальное число:" << std::endl;
        std::cout << FindMax(numbers, size) << std::endl;
        delete[] numbers;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Интерактивный цикл для умного калькулятора с историей операций
void SmartCalculatorWithTransactionHistory()
{
    int issue_number;
    int number_saved_operations = 0;
    Calculation history[5] = {};
    do
    {
        std::cout << std::endl
                  << "== УМНЫЙ КАЛЬКУЛЯТОР С ИСТОРИЕЙ ОПЕРАЦИЙ ==" << std::endl;
        std::cout << "1. Арифметические операции с числами" << std::endl;
        std::cout << "2. История операций" << std::endl;
        std::cout << "3. Обмен значений переменных" << std::endl;
        std::cout << "4. Поиск минимального и максимального из чисел" << std::endl;
        std::cout << "0. Выход" << std::endl
                  << std::endl;
        std::cout << "Выберите действие: " << std::endl;
        std::cin >> issue_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            issue_number = -1;
        }
        if (issue_number == 1)
        {
            ArithmeticOperationsWithNumbers(&number_saved_operations, history);
        }
        else if (issue_number == 2)
        {
            HistoryOperations(&number_saved_operations, history);
        }
        else if (issue_number == 3)
        {
            ExchangeVariableValues();
        }
        else if (issue_number == 4)
        {
            FindMaxMin();
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
        }
    } while (issue_number != 0);
}

// ДЕТЕКТОР ПАЛИНДРОМОВ И АНАГРАММ

// Проверка строки на палиндром
bool CheckPalindrome(char *string)
{
    bool is_palindrome = true;
    // Левый указатель на начало массива, правый - на конец
    char *left = string;
    char *right = string + std::strlen(string) - 1;
    // Сравнение символов, пока указатели не встретятся
    while (right > left)
    {
        // Пропуск пробелов
        if (*right == ' ')
        {
            --right;
            continue;
        }
        if (*left == ' ')
        {
            ++left;
            continue;
        }
        if (*right == *left)
        {
            --right;
            ++left;
            continue;
        }
        // Если одна из букв в верхнем регистре, приведение к нижнему и сравнение
        if (*right >= 'А' && *right <= 'Я' && (*right - ('А' - 'а') == *left))
        {
            --right;
            ++left;
            continue;
        }
        if (*left >= 'А' && *left <= 'Я' && (*left - ('А' - 'а') == *right))
        {
            --right;
            ++left;
            continue;
        }
        if (*right <= 'Z' && *right >= 'A' && (*right - ('A' - 'a') == *left))
        {
            --right;
            ++left;
            continue;
        }
        if (*left <= 'Z' && *left >= 'A' && (*left - ('A' - 'a') == *right))
        {
            --right;
            ++left;
            continue;
        }
        is_palindrome = false;
        break;
    }
    return is_palindrome;
}

// Обработка задачи для проверки строки на палиндром
void CheckingPalindrome()
{
    int issue_number;
    do
    {
        char string[21];
        std::cout << std::endl
                  << "= ПРОВЕРКА СТРОКИ НА ПАЛИНДРОМ =" << std::endl;
        std::cout << "Введите строку (не более 20 символов): " << std::endl;
        std::cin.getline(string, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        bool is_palindrome = CheckPalindrome(string);
        if (is_palindrome)
        {
            std::cout << "Строка \"" << string << "\" является палиндромом" << std::endl;
        }
        else
        {
            std::cout << "Строка \"" << string << "\" не является палиндромом" << std::endl;
        }
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Проверка строк на анаграммы
bool CheckAnagrams(char *first_string, char *second_string)
{
    if (std::strlen(first_string) != std::strlen(second_string))
        return false;
    bool is_anagram = true;
    for (char *current = first_string; current < first_string + std::strlen(first_string); ++current)
    {
        // Подсчет и сравнение количества повторений текущего символа в первой строке и во второй
        int cnt_first = 0;
        for (char *current_first = first_string; current_first < first_string + std::strlen(first_string); ++current_first)
        {
            if (*current == *current_first)
            {
                ++cnt_first;
            }
        }
        int cnt_second = 0;
        for (char *current_second = second_string; current_second < second_string + std::strlen(second_string); ++current_second)
        {
            if (*current == *current_second)
            {
                ++cnt_second;
            }
        }
        if (cnt_first != cnt_second)
        {
            is_anagram = false;
            break;
        }
    }
    return is_anagram;
}

// Обработка задачи для проверки двух строк на анаграммы
void СheckingAnagrams()
{
    int issue_number;
    do
    {
        char first_string[21];
        char second_string[21];
        std::cout << std::endl
                  << "= ПРОВЕРКА ДВУХ СТРОК НА АНАГРАММЫ =" << std::endl;
        std::cout << "Введите первую строку (не более 20 символов): " << std::endl;
        std::cin.getline(first_string, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << "Введите вторую строку (не более 20 символов): " << std::endl;
        std::cin.getline(second_string, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        bool is_anagram = CheckAnagrams(first_string, second_string);
        if (is_anagram)
        {
            std::cout << "Строки \"" << first_string << "\" и \"" << second_string << "\" являются анаграммами" << std::endl;
        }
        else
        {
            std::cout << "Строки \"" << first_string << "\" и \"" << second_string << "\" не являются анаграммами" << std::endl;
        }
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Обмен символов
void Swap(char *first_sym, char *second_sym)
{
    char temp = *first_sym;
    *first_sym = *second_sym;
    *second_sym = temp;
}

// Реверс строки
void Reverse(char *string)
{
    char *left = string;
    char *right = string + std::strlen(string) - 1;
    while (left < right)
    {
        Swap(left, right);
        ++left;
        --right;
    }
}

// Обработка задачи для реверса строки
void LineReversal()
{
    int issue_number;
    do
    {
        char string[21];
        std::cout << std::endl
                  << "= РЕВЕРС СТРОКИ =" << std::endl;
        std::cout << "Введите строку (не более 20 символов): " << std::endl;
        std::cin.getline(string, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << "Результат для строки \"" << string << "\":" << std::endl;
        Reverse(string);
        std::cout << string << std::endl;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Подсчет количества слов в строке
int NumberWords(char *string)
{
    int cnt = 0;
    bool word = false;
    for (char *current = string; current < string + std::strlen(string); ++current)
    {
        if (*current != ' ' && !word)
        {
            word = true;
            ++cnt;
        }
        else if (*current == ' ' && word)
        {
            word = false;
        }
    }
    return cnt;
}

// Обработка задачи для подсчета количества слов в строке
void CountingNumberWords()
{
    int issue_number;
    do
    {
        char string[21];
        std::cout << std::endl
                  << "= ПОДСЧЕТ КОЛИЧЕСТВА СЛОВ В СТРОКЕ =" << std::endl;
        std::cout << "Введите строку (не более 20 символов): " << std::endl;
        std::cin.getline(string, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << "Количество слов в строке \"" << string << "\":" << std::endl;
        std::cout << NumberWords(string) << std::endl;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Поиск самого длинного слова
void LongestWord(char *string, char *result)
{
    bool word = false;
    char current_word[21];
    int max_len = 0;
    int current_len = 0;
    for (char *current = string; current < string + std::strlen(string); ++current)
    {
        if (*current != ' ' && !word)
        {
            word = true;
            ++current_len;
            current_word[0] = *current;
            current_word[1] = '\0';
        }
        else if (*current == ' ' && word)
        {
            word = false;
            if (current_len > max_len)
            {
                max_len = current_len;
                std::strcpy(result, current_word);
            }
            current_len = 0;
            current_word[0] = '\0';
        }
        else if (*current != ' ')
        {
            ++current_len;
            current_word[current_len - 1] = *current;
            current_word[current_len] = '\0';
        }
    }
    if (current_len > max_len)
    {
        max_len = current_len;
        std::strcpy(result, current_word);
    }
}

// Обработка задачи для поиска самого длинного слова
void SearchLongestWord()
{
    int issue_number;
    do
    {
        char string[21];
        std::cout << std::endl
                  << "= ПОИСК САМОГО ДЛИННОГО СЛОВА =" << std::endl;
        std::cout << "Введите строку (не более 20 символов): " << std::endl;
        std::cin.getline(string, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        char result[21];
        LongestWord(string, result);
        std::cout << "Самое длинное слово в строке \"" << string << "\":" << std::endl;
        std::cout << result << std::endl;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Очистка строки от не-буквенных символов
void ClearNonAlphabeticCharacters(char *string, char *result)
{
    int size = 0;
    for (char *current = string; current < string + std::strlen(string); ++current)
    {
        if ((*current >= 'A' && *current <= 'Z') ||
            (*current >= 'А' && *current <= 'Я') ||
            (*current >= 'a' && *current <= 'z') ||
            (*current >= 'а' && *current <= 'я'))
        {
            *(result + size) = *current;
            ++size;
        }
    }
    *(result + size) = '\0';
}

// Обработка задачи для очистки строки от не-буквенных символов
void ClearingNonAlphabeticCharacters()
{
    int issue_number;
    do
    {
        char string[21];
        std::cout << std::endl
                  << "= ОЧИСТКА СТРОКИ ОТ НЕ-БУКВЕННЫХ СИМВОЛОВ =" << std::endl;
        std::cout << "Введите строку (не более 20 символов): " << std::endl;
        std::cin.getline(string, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        char result[21];
        ClearNonAlphabeticCharacters(string, result);
        std::cout << "Результат для строки \"" << string << "\":" << std::endl;
        std::cout << result << std::endl;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Интерактивный цикл для детектора палиндромов и анаграмм
void PalindromeAnagramDetector()
{
    int issue_number;
    do
    {
        std::cout << std::endl
                  << "== ДЕТЕКТОР ПАЛИНДРОМОВ И АНАГРАММ ==" << std::endl;
        std::cout << "1. Проверка строки на палиндром" << std::endl;
        std::cout << "2. Проверка двух строк на анаграммы" << std::endl;
        std::cout << "3. Реверс строки" << std::endl;
        std::cout << "4. Подсчет количества слов в строке" << std::endl;
        std::cout << "5. Поиск самого длинного слова" << std::endl;
        std::cout << "6. Очистка строки от не-буквенных символов" << std::endl;
        std::cout << "0. Выход" << std::endl
                  << std::endl;
        std::cout << "Выберите действие: " << std::endl;
        std::cin >> issue_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            issue_number = -1;
        }
        if (issue_number == 1)
        {
            CheckingPalindrome();
        }
        else if (issue_number == 2)
        {
            СheckingAnagrams();
        }
        else if (issue_number == 3)
        {
            LineReversal();
        }
        else if (issue_number == 4)
        {
            CountingNumberWords();
        }
        else if (issue_number == 5)
        {
            SearchLongestWord();
        }
        else if (issue_number == 6)
        {
            ClearingNonAlphabeticCharacters();
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
        }
    } while (issue_number != 0);
}

// ТРАНСПОНИРОВАНИЕ МАТРИЦЫ ПРОИЗВОЛЬНОГО РАЗМЕРА

// Заполнение матрицы случайными числами от 1 до 10
void FillingMatrix(int **matrix, int rows, int cols)
{
    for (int **current_row = matrix; current_row < matrix + rows; ++current_row)
    {
        for (int *current_el = *current_row; current_el < *current_row + cols; ++current_el)
        {
            *current_el = rand() % 10 + 1;
        }
    }
}

// Транспонирование матрицы
void MatrixTransposition(int **matrix, int **transposed_matrix, int rows, int cols)
{
    for (int **current_row = transposed_matrix; current_row < transposed_matrix + cols; ++current_row)
    {
        for (int *current_el = *current_row; current_el < *current_row + rows; ++current_el)
        {
            *current_el = *(*(matrix + (current_el - *current_row)) + (current_row - transposed_matrix));
        }
    }
}

// Поиск суммы элементов в каждом столбце и строке
void MatrixSum(int **matrix, int **sum_matrix, int rows, int cols)
{
    for (int **current_row = sum_matrix; current_row < sum_matrix + rows; ++current_row)
    {
        for (int *current_el = *current_row; current_el < *current_row + cols; ++current_el)
        {
            *current_el = 0;
            for (int *current = *(matrix + (current_row - sum_matrix)); current < *(matrix + (current_row - sum_matrix)) + cols; ++current)
            {
                *current_el += *current;
            }
            for (int **current = matrix; current < matrix + rows; ++current)
            {
                *current_el += *(*current + (current_el - *current_row));
            }
            *current_el -= *(*(matrix + (current_row - sum_matrix)) + (current_el - *current_row));
        }
    }
}

// Интерактивный цикл для транспонирования матрицы произвольного размера
void TransposingMatrixArbitrarySize()
{
    int issue_number = 1;
    do
    {
        int rows;
        int cols;
        std::cout << std::endl
                  << "== ТРАНСПОНИРОВАНИЕ МАТРИЦЫ ПРОИЗВОЛЬНОГО РАЗМЕРА ==" << std::endl;
        std::cout << "Введите количество строк:" << std::endl;
        std::cin >> rows;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            rows = -1;
        }
        if (rows < 1)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            continue;
        }
        std::cout << "Введите количество столбцов:" << std::endl;
        std::cin >> cols;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            cols = -1;
        }
        if (cols < 1)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            continue;
        }
        int **matrix = new int *[rows];
        for (int i = 0; i < rows; ++i)
            matrix[i] = new int[cols];
        FillingMatrix(matrix, rows, cols);
        std::cout << "Исходная матрица:" << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                std::cout << std::setw(3) << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        int **transposed_matrix = new int *[cols];
        for (int i = 0; i < cols; ++i)
            transposed_matrix[i] = new int[rows];
        MatrixTransposition(matrix, transposed_matrix, rows, cols);
        std::cout << "Транспонированная матрица:" << std::endl;
        for (int i = 0; i < cols; ++i)
        {
            for (int j = 0; j < rows; ++j)
            {
                std::cout << std::setw(3) << transposed_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        int **sum_matrix = new int *[rows];
        for (int i = 0; i < rows; ++i)
            sum_matrix[i] = new int[cols];
        MatrixSum(matrix, sum_matrix, rows, cols);
        std::cout << "Матрица с суммами элементов в каждой строке и стобце:" << std::endl;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                std::cout << std::setw(static_cast<int>(std::log10(rows * 10 + cols * 10 - 10)) + 2) << sum_matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < rows; ++i)
            delete[] matrix[i];
        delete[] matrix;
        for (int i = 0; i < rows; ++i)
            delete[] sum_matrix[i];
        delete[] sum_matrix;
        for (int i = 0; i < cols; ++i)
            delete[] transposed_matrix[i];
        delete[] transposed_matrix;
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// СИСТЕМА УПРАВЛЕНИЯ БИБЛИОТЕКОЙ КНИГ

// Структура для хранения одной книги
struct Book
{
    char title[21];
    char author[21];
    int year;
};

// Добавление книги в динамический массив
Book *Add(Book *books, int *size, char *title, char *author, int *year)
{
    Book *temp_books = new Book[*size + 1];
    bool check_add = false;
    for (Book *book = books; book < books + *size; ++book)
    {
        if (!check_add && book->year > *year)
        {
            for (char *current = title; current < (title + 21); ++current)
            {
                *((temp_books + (book - books))->title + (current - title)) = *current;
            }
            for (char *current = author; current < (author + 21); ++current)
            {
                *((temp_books + (book - books))->author + (current - author)) = *current;
            }
            (temp_books + (book - books))->year = *year;
            *(temp_books + (book - books) + 1) = *book;
            check_add = true;
        }
        else if (!check_add)
        {
            *(temp_books + (book - books)) = *book;
        }
        else
        {
            *(temp_books + (book - books) + 1) = *book;
        }
    }
    if (!check_add)
    {
        for (char *current = title; current < (title + 21); ++current)
        {
            *((temp_books + *size)->title + (current - title)) = *current;
        }
        for (char *current = author; current < (author + 21); ++current)
        {
            *((temp_books + *size)->author + (current - author)) = *current;
        }
        (temp_books + *size)->year = *year;
    }
    delete[] books;
    *size += 1;
    return temp_books;
}

// Обработка задачи для добавления книги
Book *AddBook(Book *books, int *size)
{
    int issue_number = 1;
    do
    {
        char title[21];
        char author[21];
        int year;
        std::cout << std::endl
                  << "= ДОБАВЛЕНИЕ НОВОЙ КНИГИ =" << std::endl;
        std::cout << "Введите название книги (не более 20 символов): " << std::endl;
        std::cin.getline(title, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << "Введите автора книги (не более 20 символов): " << std::endl;
        std::cin.getline(author, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        std::cout << "Введите год издания: " << std::endl;
        std::cin >> year;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            year = -1;
        }
        if (year <= 0)
        {
            std::cout << "ОШИБКА: Введено некорректное число" << std::endl;
            continue;
        }
        books = Add(books, size, title, author, &year);
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
    return books;
}

// Поиск книг по названию
void FindBook(Book *books, int *size, char *title)
{
    bool find = false;
    for (Book *book = books; book < (books + *size); ++book)
    {
        if (std::strcmp(book->title, title) == 0)
        {
            if (!find)
            {
                find = true;
                std::cout << "Найденные книги:" << std::endl;
            }
            std::cout << book->author << " \"" << book->title << "\" " << book->year << std::endl;
        }
    }
    if (!find)
    {
        std::cout << "Книги не найдены" << std::endl;
    }
}

// Обработка задачи для поиска книги по названию
void SearchBookByName(Book *books, int *size)
{
    int issue_number = 1;
    do
    {
        char title[21];
        std::cout << std::endl
                  << "= ПОИСК КНИГИ ПО НАЗВАНИИЮ =" << std::endl;
        std::cout << "Введите название книги (не более 20 символов): " << std::endl;
        std::cin.getline(title, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        FindBook(books, size, title);
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Вывод книг определенного автора
void OutputBooks(Book *books, int *size, char *author)
{
    bool find = false;
    for (Book *book = books; book < (books + *size); ++book)
    {
        if (std::strcmp(book->author, author) == 0)
        {
            if (!find)
            {
                find = true;
                std::cout << "Найденные книги:" << std::endl;
            }
            std::cout << book->author << " \"" << book->title << "\" " << book->year << std::endl;
        }
    }
    if (!find)
    {
        std::cout << "Книги не найдены" << std::endl;
    }
}

// Обработка задачи для вывода всех книг определенного автора
void OutputAllBooksCertainAuthor(Book *books, int *size)
{
    int issue_number = 1;
    do
    {
        char author[21];
        std::cout << std::endl
                  << "= ВЫВОД ВСЕХ КНИГ ОПРЕДЕЛЕННОГО АВТОРА =" << std::endl;
        std::cout << "Введите автора книг (не более 20 символов): " << std::endl;
        std::cin.getline(author, 20);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        OutputBooks(books, size, author);
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Удаление книги из системы
Book *DeleteBook(Book *books, int *size, int *index_book)
{
    Book *temp_books = new Book[*size - 1];
    bool del = false;
    for (Book *book = books; book < (books + *size); ++book)
    {
        if ((book - books) != *index_book - 1)
        {
            if (del)
            {
                *(temp_books + (book - books) - 1) = *book;
            }
            else
            {
                *(temp_books + (book - books)) = *book;
            }
        }
        else
        {
            del = true;
        }
    }
    delete[] books;
    *size -= 1;
    return temp_books;
}

// Обработка задачи для удаления книги из системы
Book *DeleteBookFromSystem(Book *books, int *size)
{
    int issue_number = 1;
    do
    {
        int index_book;
        std::cout << std::endl
                  << "= УДАЛЕНИЕ КНИГИ ИЗ СИСТЕМЫ =" << std::endl;
        for (Book *book = books; book < (books + *size); ++book)
        {
            std::cout << book - books + 1 << ". " << book->author << " \"" << book->title << "\" " << book->year << std::endl;
        }
        std::cout << "Введите номер книги: " << std::endl;
        std::cin >> index_book;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        if (index_book < 1 || index_book > *size)
        {
            std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            continue;
        }
        books = DeleteBook(books, size, &index_book);
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
    return books;
}

// Обработка задачи для вывода всех книг
void OutputAllBooks(Book *books, int *size)
{
    int issue_number = 1;
    do
    {
        int index_book;
        std::cout << std::endl
                  << "= ВЫВОД КНИГ, ОТСОРТИРОВАННЫХ ПО ГОДУ ИЗДАНИЯ =" << std::endl;
        for (Book *book = books; book < (books + *size); ++book)
        {
            std::cout << book - books + 1 << ". " << book->author << " \"" << book->title << "\" " << book->year << std::endl;
        }
        do
        {
            std::cout << std::endl
                      << "Задача завершена" << std::endl;
            std::cout << "1. Выполнить задачу еще раз" << std::endl;
            std::cout << "0. Выход" << std::endl
                      << std::endl;
            std::cout << "Выберите действие:" << std::endl;
            std::cin >> issue_number;
            std::cin.ignore(10000, '\n');
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                issue_number = -1;
            }
            if (issue_number != 1 && issue_number != 0)
            {
                std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
            }
        } while (issue_number != 1 && issue_number != 0);
    } while (issue_number != 0);
}

// Интерактивный цикл для системы управления библиотекой книг
void BookLibraryManagementSystem()
{
    int issue_number;
    Book *books = new Book[0];
    int size = 0;
    do
    {
        std::cout << std::endl
                  << "== СИСТЕМА УПРАВЛЕНИЯ БИБЛИОТЕКОЙ КНИГ ==" << std::endl;
        std::cout << "1. Добавление новой книги" << std::endl;
        std::cout << "2. Поиск книги по названию" << std::endl;
        std::cout << "3. Вывод всех книг определенного автора" << std::endl;
        std::cout << "4. Удаление книги из системы" << std::endl;
        std::cout << "5. Вывести все книги, отсортированные по году издания" << std::endl;
        std::cout << "0. Выход" << std::endl
                  << std::endl;
        std::cout << "Выберите действие: " << std::endl;
        std::cin >> issue_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            issue_number = -1;
        }
        if (issue_number == 1)
        {
            books = AddBook(books, &size);
        }
        else if (issue_number == 2)
        {
            if (size == 0)
            {
                std::cout << "ОШИБКА: Нет книг в системе" << std::endl;
            }
            else
            {
                SearchBookByName(books, &size);
            }
        }
        else if (issue_number == 3)
        {
            if (size == 0)
            {
                std::cout << "ОШИБКА: Нет книг в системе" << std::endl;
            }
            else
            {
                OutputAllBooksCertainAuthor(books, &size);
            }
        }
        else if (issue_number == 4)
        {
            if (size == 0)
            {
                std::cout << "ОШИБКА: Нет книг в системе" << std::endl;
            }
            else
            {
                books = DeleteBookFromSystem(books, &size);
            }
        }
        else if (issue_number == 5)
        {
            OutputAllBooks(books, &size);
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
        }
    } while (issue_number != 0);
    delete[] books;
}

int main()
{
    setlocale(LC_ALL, "rus");
    srand(time(0));
    int issue_number;
    do
    {
        std::cout << std::endl
                  << "=== ЛАБОРАТОРНАЯ РАБОТА 3 ===" << std::endl;
        std::cout << "1. Анализатор успеваемости группы" << std::endl;
        std::cout << "2. Умный калькулятор с историей операций" << std::endl;
        std::cout << "3. Детектор палиндромов и анаграмм" << std::endl;
        std::cout << "4. Транспонирование матрицы произвольного размера" << std::endl;
        std::cout << "5. Система управления библиотекой книг" << std::endl;
        std::cout << "0. Выход" << std::endl
                  << std::endl;
        std::cout << "Выберите действие: " << std::endl;
        std::cin >> issue_number;
        std::cin.ignore(10000, '\n');
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            issue_number = -1;
        }
        if (issue_number == 1)
        {
            GroupPerformanceAnalyzer();
        }
        else if (issue_number == 2)
        {
            SmartCalculatorWithTransactionHistory();
        }
        else if (issue_number == 3)
        {
            PalindromeAnagramDetector();
        }
        else if (issue_number == 4)
        {
            TransposingMatrixArbitrarySize();
        }
        else if (issue_number == 5)
        {
            BookLibraryManagementSystem();
        }
        else if (issue_number != 0)
        {
            std::cout << "ОШИБКА: Введено недопустимое число" << std::endl;
        }
    } while (issue_number != 0);
    return 0;
}
