#include <iostream>
#include <chrono>
#include <windows.h>
#include <ctime>
#define N 100

using namespace std;
using namespace chrono;


int mainMenu (int array[]);
void printArray (int array[]);  
void generateArray (int array[]);
int binarySearch (int array[], int n);
double bubbleSort (int array[]);
double shakerSort (int array[]);
double combSort (int array[]);
double insertionSort (int array[]);
double searchMinMax (int array[], int elements[2]);
double searchMinMaxSorted (int array[], int elements[2]);
void printMean (int array[]);
void numberElementsLeft(int array[]);
void numberElementsRight(int array[]);
int search (int array[], int n);
void changeElements (int array[]);

int main ()
  {
    //ВНИМАНИЕ!!! В СЛУЧАЕ ПРОБЛЕМ С ОТОБРАЖЕНИЕМ МЕНЮ РАСКОММЕНТИРУЙТЕ ДРУГУЮ СТРОЧКУ SETLOCALE!!!
    //setlocale(LC_ALL, "ru_RU.utf8");
    setlocale(0, "");
    //setlocale (LC_ALL, "Russian");
    srand(time (0));
    int array[N];
    generateArray(array);
    int exit=1;
    while (exit) exit=mainMenu (array);
    return 0;
  }
  
int mainMenu (int array[])
  {
    system("cls");
    cout << "Текущее состояние массива:" << endl << endl;
    printArray (array);
    cout << endl;
    cout << endl << "Главное меню:" << endl << "1) Отсортировать массив пузырьк"
            "овой сортировкой." << endl << "2) Отсортировать массив шейкер-сорт"
            "ировкой." << endl << "3) Отсортировать массив сортировкой расчёско"
            "й." << endl << "4) Отсортировать массив сортировкой вставками." << 
            endl << "5) Найти минимальный и максимальный элементы массива (1 с"
            "пособ)." << endl << "6) Найти минимальный и максимальный элементы"
            " массива (2 способ, только отсортированный массив)." << endl << "7"
            ") Вывести среднее значение минимального и максимального элементов"
            " массива." << endl << "8) Вывести число элементов в массиве, мень"
            "ших числа, вводимиго пользователем (только отсортированный массив)"
            "." << endl << "9) Вывести число элементов в массиве, меньших числ"
            "а, вводимиго пользователем (только отсортированный массив)." << 
            endl << "10) Проверить, есть ли введённое число в массиве с помощью"
            " бинарного поиска (только отсортированный массив)." << endl << "11"
            ") Проверить, есть ли введённое число в массиве с помощью перебора." 
            << endl << "12) Поменять местами элементы массива." << endl << "0)"
            " Выход из программы." << endl << "Введите желаемый вариант: ";
    int choise;
    cin >> choise;
    switch (choise)
      {
        case 0:
          return 0;
        case 1:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << bubbleSort(array) << ".";
            Sleep(2000);
            return 1;
          }
        case 2:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << shakerSort(array) << ".";
            Sleep(2000);
            return 1;
          }
        case 3:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << combSort(array) << ".";
            Sleep(2000);
            return 1;
          }
        case 4:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << insertionSort(array) << ".";
            Sleep(2000);
            return 1;          }
        case 5:
          {
            int elements[2];
            double searchTime=searchMinMax(array, elements);
            cout << endl << "Минимальный элемент равен: " << elements[0] <<
                    endl << "Максимальный элемент равен: " << elements[1] <<
                    endl << "На поиск потрачено времени: " << searchTime << ".";
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 6:
          {
            int elements[2];
            double searchTime=searchMinMaxSorted(array, elements);
            cout << endl << "Минимальный элемент равен: " << elements[0] <<
                    endl << "Максимальный элемент равен: " << elements[1] <<
                    endl << "На поиск потрачено времени: " << searchTime << ".";
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 7:
          {
            printMean(array);
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;

          }
        case 8:
          {
            numberElementsLeft(array);
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 9:
          {
            numberElementsRight(array);
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 10:
          {
            int n;
            cout << endl << "Введите число: ";
            cin >> n;
            auto begin = system_clock::now();
            int result=binarySearch(array, n);
            auto end = system_clock::now();
            duration<double> wastedTime = end - begin;
            cout << (result?"В массиве есть такое число.":"В массиве такого числа нет.") << endl;
            cout << "Время, затраченное на поиск: " << wastedTime.count() <<".";
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 11:
          {
            int n;
            cout << endl << "Введите число: ";
            cin >> n;
            auto begin = system_clock::now();
            int result=search(array, n);
            auto end = system_clock::now();
            duration<double> wastedTime = end - begin;
            cout << (result?"В массиве есть такое число.":"В массиве такого числа нет.") << endl;
            cout << "Время, затраченное на поиск: " << wastedTime.count() <<".";
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 12:
          {
            auto begin = system_clock::now();
            changeElements(array);
            auto end = system_clock::now();
            duration<double> wastedTime = end - begin;
            cout << "Время, затраченное на поиск: " << wastedTime.count() <<".";
            cout << endl << "Возврат в главное меню произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        default:
          {
            system("cls");
            cout << "Некоррекный ввод!";
            Sleep(1000);
            return 1;
          }
      }
  }
  
void printArray (int array[])
  {
    for (int i=0; i<N; i++)
      {
        if (!(i%10)) cout << endl;
        cout << array[i] << "\t";
      }
  }
  
void generateArray (int array[])
  {
    for (int i=0; i<N; i++)
      {
        array[i]=(rand()%199)-99;
      }
  }
  
double bubbleSort (int array[])
  {
    auto begin = system_clock::now();
    int sorted=0;
    int currentMaxUnsorted=N-1;
    while (!sorted)
      {
        sorted=1;
        for (int i=0; i<currentMaxUnsorted; i++)
          {
            if (array[i]-array[i+1]>0)
              {
                array[i] = array[i] + array[i+1];
                array[i+1] = array[i] - array[i+1];
                array[i] = array[i] - array[i+1];
                sorted=0;
              }
          }
        currentMaxUnsorted--;
        }
    auto end = system_clock::now();
    duration<double> wastedTime = end - begin;
    return wastedTime.count();
  }
  
double shakerSort (int array[])
  {
    auto begin = system_clock::now();
    int sorted=0;
    int currentMaxUnsorted=N-1;
    int currentMinUnsorted=0;
    while (!sorted)
      {
        sorted=1;
        for (int i=currentMinUnsorted; i<currentMaxUnsorted; i++)
          {
            if (array[i]-array[i+1]>0)
              {
                array[i] = array[i] + array[i+1];
                array[i+1] = array[i] - array[i+1];
                array[i] = array[i] - array[i+1];
                sorted=0;
              }
          }
        currentMaxUnsorted--;
        for (int i=currentMaxUnsorted; i>currentMinUnsorted; i--)
          {
            if (array[i]-array[i-1]<0)
              {
                array[i] = array[i] + array[i-1];
                array[i-1] = array[i] - array[i-1];
                array[i] = array[i] - array[i-1];
                sorted=0;
              }
          }
        currentMinUnsorted++;
        }      
    auto end = system_clock::now();
    duration<double> wastedTime = end - begin;
    return wastedTime.count();
  }

double combSort (int array[])
  {
    auto begin = system_clock::now();
    for (int step=N-1; step; step/=1.2473309)
      {
        for (int i=0; i+step-N; i++)
          {
            if (array[i]-array[i+step]>0)
              {
                array[i] = array[i] + array[i+step];
                array[i+step] = array[i] - array[i+step];
                array[i] = array[i] - array[i+step];
              }
          }
      }
    auto end = system_clock::now();
    duration<double> wastedTime = end - begin;
    return wastedTime.count();
  }
  
double insertionSort (int array[])
  {
    auto begin = system_clock::now();
    for(int i=1; i<N; i++)   
      {  
        int j= i;  
        int buffer = array[i];  
        while(j)  
          {
            if (buffer>array[j-1]) break;
            array[j] = array[j-1];   
            j = j-1;
          }  
        array[j] = buffer;  
      }  
    auto end = system_clock::now();
    duration<double> wastedTime = end - begin;
    return wastedTime.count();
  }

int binarySearch (int array[], int n)
  {
    int numberElements=0;
    int minRange=0;
    int maxRange=N-1;
    int half;
    while (1)
      {
        half=(minRange+maxRange)/2;
        if (array[half]==n)
          {
            break;
          }
        else
          {
            if (array[half]<n) minRange=half;
            if (array[half]>n) maxRange=half;
          }
        if ((maxRange-minRange)<=1) break;
      }
    if (array[half]-n)
      {
        return numberElements;
      }
    else
      {
        numberElements=1;
        return numberElements;
      }
  }

double searchMinMax (int array[], int elements[2])
  {
    auto begin = system_clock::now();
    elements[0]=array[0];
    elements[1]=array[N-1]; 
    for (int i=N-1; i>-1; i--)
      {
        if (elements[1]<array[i]) elements[1]=array[i];
      }
    for (int i=0; i<N; i++)
      {
        if (elements[0]>array[i]) elements[0]=array[i];
      }
    auto end = system_clock::now();
    duration<double> wastedTime = end - begin;
    return wastedTime.count();
  }

double searchMinMaxSorted (int array[], int elements[2])
  {
    auto begin = system_clock::now();
    elements[0]=array[0];
    elements[1]=array[N-1]; 
    auto end = system_clock::now();
    duration<double> wastedTime = end - begin;
    return wastedTime.count();
  }

void printMean (int array[])
  {
    int elements[2];
    searchMinMax(array, elements);
    int mean=(elements[0]+elements[1])/2;
    cout << endl << "Среднее значение: " << mean << endl << "Индексы элементов, равных этому значению: ";
    int isHere=0;
    for (int i=0; i<N; i++)
      {
        if (array[i]==mean) 
          {
            cout << i+1 << " ";
            isHere++;
          }
      }
    if (!(isHere)) 
      {
        cout << "такого элемента в массиве нет!" << endl;
      }
    else
      {
        cout << endl << "Всего в массиве таких элементов: " << isHere << "." << endl;
      }
  }

void numberElementsLeft(int array[])
  {
    cout << "Введите число: ";
    int n, result=0;
    cin >> n;
    int count=0;
    for (int i=0; i<N; i++)
      {
        if (array[i]<n)
          {
            count++;
            result=i+1;
          }
        else break;
      }
    cout << "Элементов меньше " << n << " в массиве: " << result << ".";
  }

void numberElementsRight(int array[])
  {
    cout << "Введите число: ";
    int n, result=0;
    cin >> n;
    int count=0;
    for (int i=N-1; i>-1; i--)
      {
        if (array[i]>n)
          {
            count++;
            result=N-i;
          }
        else break;
      }
    cout << "Элементов больше " << n << " в массиве: " << result << ".";
  }

int search (int array[], int n)
  {
    for (int i=0; i<N; i++)
      {
        if (array[i]==n) return 1;
      }
    return 0;
  }

void changeElements (int array[])
  {
    int a, b;
    cout << endl << "Введите индекс первого элемента: ";
    cin >> a;
    cout << endl << "Введите индекс второго элемента: ";
    cin >> b;
    array[a] = array[a] + array[b];
    array[b] = array[a] - array[b];
    array[a] = array[a] - array[b];
  }



