#ifndef ARRAY_H
#define ARRAY_H

/*
Создайте класс Array (или используйте ранее созданный вами).
Класс Array – это класс динамического массива. Размер массива
может быть передан в качестве параметра или задан с помощью
вызова функции - члена. Класс должен позволять заполнять
массив значениями, отображать содержимое массива, изменять
размер массива, сортировать массив, определять минимальное
и максимальное значение. Класс должен содержать набор конструкторов
(конструктор копирования обязателен), деструктор
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <typeinfo>

template<typename dataType, const int _size_ = 0>
class _array_
{
    private:
        unsigned int size;
        dataType* array;
    public:
        // конструктор без параметров
        _array_()
        {
            size = _size_;
            if(size > 0)
                array = new dataType[size];
            else
                array = nullptr;
        }
        // конструктор с одним параметром
        _array_(const size_t& size)
        {
            if(array != nullptr)
                delete [] array;

            this->size = size;
            array = new dataType[this->size];
            if(size > 1)
            {
                for(size_t i = 0; i < size; ++i)
                    array[i] = 0;
            }
            else
                array[0] = 0;
        }
        // деструктор
        ~_array_()
        {
            if(array != nullptr)
                delete [] array;
        }
        // ************** //
        // *** методы *** //
        // ************** //
        // создание массива
        bool create()
        {
            bool success = false;
            int size = 0;
            std::string length;
            INPUTSIZE:
            std::cout << "enter the size of the array: ";
            std::cin >> length;

            try { size = std::stoi(length); }
            catch (std::invalid_argument exception)
            {
                std::cout << "error, please enter a valid value" << std::endl;
                goto INPUTSIZE;
            }

            if(size > 0)
            {
                this->size = size;
                array = new dataType[this->size];
                if(size > 1)
                {
                    for(size_t i = 0; i < size; ++i)
                        array[i] = 0;
                }
                else
                    array[0] = 0;

                success = true;
            }
            else
            {
                std::cout << "error, the size of the array must be greater than zero" << std::endl;
                goto INPUTSIZE;
            }

            system("cls");
            return success;
        }
        // заполнение массива
        bool infill()
        {
            // генерация случайного числа в заданном диапазоне
            // static_cast<int>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (max - min + 1) + min);
            const char* arrayDataType = typeid (dataType).name(); // тип данных массива
            // если тип данных массива int или float или double
            if(*arrayDataType == 'i' || *arrayDataType == 'f' || *arrayDataType == 'd')
            {
                bool success = false;
                bool choise = false;

                std::string random;
                std::string value;
                std::string min;
                std::string max;

                int MIN = 0;
                int MAX = 0;
                dataType VALUE = 0;

                RANDOMFILLING:
                std::cout << "filling array with random values(1.yes/0.no): ";
                std::cin >> random;

                try { choise = std::stoi(random); }
                catch (std::invalid_argument exception)
                {
                    std::cout << "error, please enter a valid value" << std::endl;
                    goto RANDOMFILLING;
                }
                // заполнение массива случайными числами
                if(choise)
                {
                    INPUTRANGE:
                    std::cout << "enter a range of values" << std::endl;
                    // ввод минимального значения(начала) диапазона
                    INPUTMIN:
                    std::cout << "from: ";
                    std::cin >> min;

                    try { MIN = std::stoi(min); }
                    catch (std::invalid_argument exception)
                    {
                        std::cout << "error, please enter a valid value" << std::endl;
                        goto INPUTMIN;
                    }
                    // ввод максимального значения(конца) диапазона
                    INPUTMAX:
                    std::cout << "to: ";
                    std::cin >> max;

                    try { MAX = std::stoi(max); }
                    catch (std::invalid_argument exception)
                    {
                        std::cout << "error, please enter a valid value" << std::endl;
                        goto INPUTMAX;
                    }
                    // проверка на допустимость диапазона(минимальное значение не должно быть больше максимального)
                    if(MIN > MAX)
                    {
                        std::cout << "the minimum value of the range exceeds the maximum, repeat the entry again" << std::endl;
                        goto INPUTRANGE;
                    }
                    // если размер массива больше одного элемента
                    if(size > 1)
                    {
                        for(size_t i = 0; i < size; ++i)
                        {
                            if(*arrayDataType == 'i')
                                array[i] = static_cast<int>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (MAX - MIN + 1) + MIN);
                            else if(*arrayDataType == 'f')
                                array[i] = static_cast<float>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (MAX - MIN + 1) + MIN);
                            else
                                array[i] = static_cast<double>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (MAX - MIN + 1) + MIN);
                        }
                        success = true;
                    }
                    else
                    {
                        if(*arrayDataType == 'i')
                            array[0] = static_cast<int>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (MAX - MIN + 1) + MIN);
                        else if(*arrayDataType == 'f')
                            array[0] = static_cast<float>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (MAX - MIN + 1) + MIN);
                        else
                            array[0] = static_cast<double>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (MAX - MIN + 1) + MIN);
                        success = true;
                    }
                }
                // заполнение массива пользовательскими числами
                else // if(choise == 0)
                {
                    if(size > 1)
                    {
                        for(size_t i = 0; i < size; ++i)
                        {
                            INPUTVALUE:
                            std::cout << "enter value number " << i + 1 << ": ";
                            std::cin >> value;

                            if(*arrayDataType == 'i')
                            {
                                try { VALUE = std::stoi(value); }
                                catch (std::invalid_argument exception)
                                {
                                    std::cout << "error, please enter a valid value" << std::endl;
                                    goto INPUTVALUE;
                                }
                            }
                            else if(*arrayDataType == 'f')
                            {
                                try { VALUE = std::stof(value); }
                                catch (std::invalid_argument exception)
                                {
                                    std::cout << "error, please enter a valid value" << std::endl;
                                    goto INPUTVALUE;
                                }
                            }
                            else
                            {
                                try { VALUE = std::stold(value); }
                                catch (std::invalid_argument exception)
                                {
                                    std::cout << "error, please enter a valid value" << std::endl;
                                    goto INPUTVALUE;
                                }
                            }

                            array[i] = VALUE;
                        }
                        success = true;
                    }
                    else
                    {
                        ENTERVALUE:
                        std::cout << "enter value: ";
                        std::cin >> value;

                        if(*arrayDataType == 'i')
                        {
                            try { VALUE = std::stoi(value); }
                            catch (std::invalid_argument exception)
                            {
                                std::cout << "error, please enter a valid value" << std::endl;
                                goto ENTERVALUE;
                            }
                        }
                        else if(*arrayDataType == 'f')
                        {
                            try { VALUE = std::stof(value); }
                            catch (std::invalid_argument exception)
                            {
                                std::cout << "error, please enter a valid value" << std::endl;
                                goto ENTERVALUE;
                            }
                        }
                        else
                        {
                            try { VALUE = std::stold(value); }
                            catch (std::invalid_argument exception)
                            {
                                std::cout << "error, please enter a valid value" << std::endl;
                                goto ENTERVALUE;
                            }
                        }

                        array[0] = VALUE;
                        success = true;
                    }
                }

                system("cls");
                return success;
            }
            // если тип данных массива char
            else if(*arrayDataType == 'c')
            {
                bool success = false;
                bool choise = false;

                std::string random;
                std::string value;

                const unsigned int MIN = 33;
                const unsigned int MAX = 126;

                RANDOMFILLINGCHAR:
                std::cout << "filling array with random values(1.yes/0.no): ";
                std::cin >> random;

                try { choise = std::stoi(random); }
                catch (std::invalid_argument exception)
                {
                    std::cout << "error, please enter a valid value" << std::endl;
                    goto RANDOMFILLINGCHAR;
                }
                // заполнение массива случайными числами
                if(choise)
                {
                    for(size_t i = 0; i < size; ++i)
                        array[i] = static_cast<char>(rand() * (1.0/ (static_cast<double>(RAND_MAX) + 1.0)) * (MAX - MIN + 1) + MIN);
                    success = true;
                }
                // заполнение массива пользовательскими числами
                else
                {
                    for(size_t i = 0; i < size; ++i)
                    {

                        std::cout << "enter a symbol " << i + 1 << ": ";
                        std::cin >> value[0];
                        // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
                        std::cin.clear();
                        while(std::cin.get() != '\n');
                        array[i] = value[0];
                    }
                    success = true;
                }

                return success;
            }

            return false;
        }
        // изменение размера массива
        bool resize()
        {
            bool success = false;

            int SIZE = 0;

            std::string newSize = nullptr;
            dataType* tempArray = nullptr;

            ENTERSIZE:
            std::cout << "enter new array size: ";
            std::cin >> newSize;

            try { SIZE = std::stoi(newSize); }
            catch (std::invalid_argument exception)
            {
                std::cout << "error, please enter a valid value" << std::endl;
                goto ENTERSIZE;
            }

            if(SIZE > 1)
            {
                tempArray = new dataType[size];

                if(SIZE >= size)
                {
                    for(size_t i = 0; i < size; ++i)
                        tempArray[i] = array[i];
                    delete [] array;

                    array = new dataType[SIZE];
                    for(size_t i = 0; i < size; ++i)
                        array[i] = tempArray[i];

                    for(size_t i = size - 1; i < SIZE; ++i)
                        array[i] = 0;
                    size = SIZE;

                    success = true;
                }
                else
                {
                    for(int i = 0; i < SIZE; ++i)
                        tempArray[i] = array[i];
                    delete [] array;

                    array = new dataType[SIZE];
                    for(int i = 0; i < SIZE; ++i)
                        array[i] = tempArray[i];
                    size = SIZE;

                    success = true;
                }

                delete [] tempArray;
            }
            else
            {
                std::cout << "error, the size of the array must be greater than zero" << std::endl;
                goto ENTERSIZE;
            }

            return success;
        }
        // сортировка массива
        bool sorting()
        {
            bool ascending = false;
            bool success = false;

            std::string choise;

            dataType value;
            CHOICEORDER:
            std::cout << "select sorting method(1.ascending/0.descending): ";
            std::cin >> choise;

            try { ascending = std::stoi(choise); }
            catch (std::invalid_argument exception)
            {
                std::cout << "error, please enter a valid value" << std::endl;
                goto CHOICEORDER;
            }
            // сортировка в порядке возрастания
            if(ascending)
            {
                for(size_t i = 0; i < size - 1; ++i)
                {
                    for(size_t j = i + 1; j < size; ++j)
                    {
                        if(array[j] < array[i])
                        {
                            value = array[i];
                            array[i] = array[j];
                            array[j] = value;
                        }
                    }
                }

                success = true;
            }
            // сортировка в порядке убывания
            else
            {
                for(size_t i = 0; i < size - 1; ++i)
                {
                    for(size_t j = i + 1; j < size; ++j)
                    {
                        if(array[j] > array[i])
                        {
                            value = array[i];
                            array[i] = array[j];
                            array[j] = value;
                        }
                    }
                }

                success = true;
            }

            return success;
        }
        // вывод данных массива
        void show()
        {
            const char* arrayDataType = typeid (dataType).name();
            unsigned int length = 0;
            std::string value;
            // тип данных integer(целочисленный)
            if(*arrayDataType == 'i')
            {
                // верх строки
                std::cout << '+';
                for(size_t i = 0; i < size; ++i)
                {
                    value = std::to_string(array[i]);
                    length = value.length();
                    for(size_t j = 0; j < length; ++j)
                        std::cout << '-';
                    std::cout << '+';
                }
                std::cout << std::endl;
                // середина строки
                std::cout << '|';
                for(size_t i = 0; i < size; ++i)
                    std::cout << array[i] << '|';
                std::cout << std::endl;
                // низ строки
                std::cout << '+';
                for(size_t i = 0; i < size; ++i)
                {
                    value = std::to_string(array[i]);
                    length = value.length();
                    for(size_t j = 0; j < length; ++j)
                        std::cout << '-';
                    std::cout << '+';
                }
                std::cout << std::endl;
            }
            // тип данных float или double(вещественный)
            else if(*arrayDataType == 'f' || *arrayDataType == 'd')
            {
                // верх строки
                std::cout << '+';
                for(size_t i = 0; i < size; ++i)
                {
                    value = std::to_string(array[i]);
                    for(size_t j = 0; j < value.length(); ++j)
                        std::cout << '-';
                    std::cout << '+';
                }
                std::cout << std::endl;
                // середина строки
                std::cout << '|';
                for(size_t i = 0; i < size; ++i)
                {
                    value = std::to_string(array[i]);
                    std::cout << value << '|';
                }
                std::cout << std::endl;
                // низ строки
                std::cout << '+';
                for(size_t i = 0; i < size; ++i)
                {
                    value = std::to_string(array[i]);
                    for(size_t j = 0; j < value.length(); ++j)
                        std::cout << '-';
                    std::cout << '+';
                }
                std::cout << std::endl;
            }
            // тип данных char(символьный)
            else
            {
                // верх строки
                std::cout << '+';
                for(size_t i = 0; i < size; ++i)
                {

                    std::cout << '-';
                    std::cout << '+';
                }
                std::cout << std::endl;
                // середина строки
                std::cout << '|';
                for(size_t i = 0; i < size; ++i)
                {
                    std::cout << array[i];
                    std::cout << '|';
                }
                std::cout << std::endl;
                // низ строки
                std::cout << '+';
                for(size_t i = 0; i < size; ++i)
                {

                    std::cout << '-';
                    std::cout << '+';
                }
                std::cout << std::endl;
            }
        }
        // ***************** //
        // *** аксессоры *** //
        // ***************** //
        // значение массива по индексу
        const dataType getValue(const unsigned int& position) const
            { return array[position - 1]; }
        // минимальное значение в массиве
        const dataType getMinValue() const
        {
           dataType value;

           value = array[0];
           for(size_t i = 0; i < size; ++i)
           {
               if(array[i] < value)
                   value = array[i];
           }

           return value;
        }
        // максимальное значение в массиве
        const dataType getMaxValue() const
        {
            dataType value;

            value = array[0];
            for(size_t i = 0; i < size; ++i)
            {
                if(array[i] > value)
                    value = array[i];
            }

            return value;
        }
        // получить размер массива
        size_t getSize() const
            { return size; }
        // ****************** //
        // **** мутаторы **** //
        // ****************** //
        // мутатор задает новый размер массива
        bool setSize(const int& size)
        {
            bool success = false;

            if(array != nullptr)
                delete [] array;

            this->size = size;
            array = new dataType[size];
            success = true;

            return success;
        }
        // мутатор копирует значения массив в исходный массив такого же размера
        bool setValues(const _array_* arrayFilled)
        {
            bool success = false;

            if(arrayFilled->size == this->size)
            {
                if(this->array != nullptr)
                    delete [] array;

                this->array = new dataType[this->size];
                for(size_t i = 0; i < size; ++i)
                    this->array[i] = arrayFilled->array[i];

                success = true;
            } else success = false;

            return success;
        }
};

#endif // ARRAY_H
/*
void show()
{
    if(size > 1)
    {
        for(size_t i = 0; i < size; ++i)
            std::cout << "| " << array[i] << " |";
        std::cout << std::endl;
    }
    else
        std::cout << "| " << array[0] << " |" << std::endl;
}
*/

// размер строки
//for(size_t i = 0; i < size; ++i)
//{
//    value = std::to_string(array[i]);
//    length += value.length();
//}
//length += size - 1;
