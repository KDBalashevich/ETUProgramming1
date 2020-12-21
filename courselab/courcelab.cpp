#include <iostream>
#include <climits>
#include <chrono>
#include <windows.h>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <fstream>
#define Stringlength 1000
#define N 100

using namespace std;
using namespace chrono;

int LAB1main ();
int LAB2main ();
int LAB3main ();
int LAB4main ();
int mainMenu ();
int LAB4readTextFromTerminal (char String[]);
int LAB4readTextFromFile (char String[]);
int LAB4mainMenu (char String[], char stringOriginal[]);
int LAB4isCharASpace (char Char);
int LAB4isCharASign (char Char);
int LAB4isCharACapital (char Char);
int LAB4isCharADot (char Char);
void LAB4stringRedactor (char String[]);
void LAB4StringCut (char String[], int position, int number);
int LAB4alphabeticalSort (char String[], char sortedString[51][11]);
void LAB4numberSymbols (char String[]);
void LAB4linearSearch (char String[]);
int LAB1menuMain (int request);
int LAB1menuAskQuestion ();
void LAB1printSizeof ();
void LAB1printBinInt ();
void LAB1printBinFloat ();
void LAB1printBinDouble ();
int LAB2mainMenu (int array[]);
void LAB2printArray (int array[]);  
void LAB2generateArray (int array[]);
int LAB2binarySearch (int array[], int n);
double LAB2bubbleSort (int array[]);
double LAB2shakerSort (int array[]);
double LAB2combSort (int array[]);
double LAB2insertionSort (int array[]);
double LAB2searchMinMax (int array[], int elements[2]);
double LAB2searchMinMaxSorted (int array[], int elements[2]);
void LAB2printMean (int array[]);
void LAB2numberElementsLeft(int array[]);
void LAB2numberElementsRight(int array[]);
int LAB2search (int array[], int n);
void LAB2changeElements (int array[]);
int LAB3mainMenu (int *matrixPointer, int matrixRank);
void LAB3generateZeroMatrix (int *matrixPointer, int matrixRank);
void LAB3generateMatrixA (int *matrixPointer, int matrixRank);
void LAB3generateMatrixB (int *matrixPointer, int matrixRank);
void LAB3printMatrix (int *matrixPointer, int matrixRank);
void LAB3changeMatrixA (int *matrixPointer, int matrixRank);
void LAB3changeMatrixB (int *matrixPointer, int matrixRank);
void LAB3changeMatrixC (int *matrixPointer, int matrixRank);
void LAB3changeMatrixD (int *matrixPointer, int matrixRank);
void LAB3sortMatrix (int *matrixPointer, int matrixRank);
int LAB3arithmeticMatrix (int *matrixPointer, int matrixRank);

int main ()
  {
    //ВНИМАНИЕ!!! В СЛУЧАЕ ПРОБЛЕМ С ОТОБРАЖЕНИЕМ МЕНЮ РАСКОММЕНТИРУЙТЕ ДРУГУЮ СТРОЧКУ SETLOCALE!!!
    setlocale(LC_ALL, "ru_RU.utf8");
    //setlocale (0, "");
    //setlocale (LC_ALL, "Russian");
    srand(time (0));
    int exit=1;
    while (exit) exit=mainMenu();
    return 0;
  }

int mainMenu ()
  {
    system("cls");
    cout << "Главное меню:" << endl << endl << "Выберете раздел:" <<endl << "1) Лабораторная работа 1." <<
            endl << "2) Лабораторная работа 2." << endl << "3) Лабораторная работа 3." << endl << 
            "4) Лабораторная работа 4." << endl << "0) Выход из программы." << endl << endl << 
            "Введите желаемый вариант: ";
    int choise;
    cin >> choise;
    cin.get();
    switch (choise)
      {
        case 0:
          return 0;
        case 1:
          {
            system ("cls");
            LAB1main();
            break;
          }
        case 2:
          {
            system ("cls");
            LAB2main();
            break;
          }
        case 3:
          {
            system ("cls");
            LAB3main();
            break;
          }
        case 4:
          {
            system ("cls");
            LAB4main();
            break;
          }
      }
    return 1;
  }

int LAB1main ()
  {
    int i;
    i=LAB1menuMain (5);
    while (i)
      {
        i=LAB1menuMain (i);
      }
    return 0;
  }

void LAB1printSizeof ()
  {
    cout << endl <<"На данном компьютере под следующие типы данных (со специфик"
            "аторами и без) отводится память в размере (в байтах):" << endl <<
            endl << "int\t\t" << sizeof (int) << endl << "short int\t" <<
            sizeof (short int) << endl << "long int\t" << sizeof (long int) <<
            endl << "float\t\t" << sizeof (float) << endl << "double\t\t" <<
            sizeof (double) << endl << "long double\t" << sizeof (long double) 
            << endl << "char\t\t" << sizeof (char) << endl << "bool\t\t" <<
            sizeof (bool) << endl << endl;
  }

void LAB1printBinInt ()
  {
    int Int;
    int mask=(1<<((sizeof(int)*CHAR_BIT)-1));
    cout << endl << "Введите целое число: ";
    cin >> Int;
    cout << endl << "Двоичное представление в памяти введённого числа (знаковый"
            " разряд отделён пробелом):" << endl;
    cout << (Int & mask ? "1 " : "0 ");
    Int<<=1;
    for (int unsigned i=0; i<((sizeof(int)*CHAR_BIT)-1); i++)
      {
        cout << (Int & mask ? "1" : "0");
        Int<<=1;
      }
    cout << endl;
  }
  
void LAB1printBinFloat ()
  {
    union
      {
        float Float;
		    char Char[3];
      };
    char mask=1<<7;
    int bitCount=32;
    cout << endl << "Введите вещественное число: ";
    cin >> Float;
    cout << endl << "Двоичное представление в памяти введённого числа (знаковый"
            " разряд, порядок и мантисса разделены пробелами):" << endl;
    for (int i=3; i>=0; i--)
      {
        for (int j=0; j < CHAR_BIT; j++)
          {
            cout << (Char[i] & mask ? "1" : "0");
            Char[i]<<=1;
            if (bitCount==24||bitCount==32) cout << " ";
            bitCount--;
            if (!bitCount) break;
          }
        if (!bitCount) break;
      }
    cout << endl;
  }
  
void LAB1printBinDouble ()
  {
    union
      {
        double Double;
		    char Char[7];
      };
    char mask=1<<7;
    int bitCount=64;
    cout << endl << "Введите вещественное число: ";
    cin >> Double;
    cout << endl << "Двоичное представление в памяти введённого числа (знаковый"
            " разряд, порядок и мантисса разделены пробелами):" << endl;
    for (int i=7; i>=0; i--)
      {
        for (int j=0; j < CHAR_BIT; j++)
          {
            cout << (Char[i] & mask ? "1" : "0");
            Char[i]<<=1;
            if (bitCount==53||bitCount==64) cout << " ";
            bitCount--;
            if (!bitCount) break;
          }
        if (!bitCount) break;
      }
    cout << endl;
  }

int LAB1menuMain (int request)
  {
    int k;
    switch (request)
      {
        case 0:
          return 0;
          break;
        case 1:
          LAB1printSizeof ();
          return 5;
          break;
        case 2:
          LAB1printBinInt();
          k=LAB1menuAskQuestion();
          if (k==2||!k) return 5;
            else return 2;
          break;
        case 3:
          LAB1printBinFloat();
          k=LAB1menuAskQuestion();
          if (k==2||!k) return 5;
            else return 3;
          break;
        case 4:
          LAB1printBinDouble();
          k=LAB1menuAskQuestion();
          if (k==2||!k) return 5;
            else return 4;
          break;
        case 5:
          cout << "Меню 1 лабораторной:" << endl << "0) Выход в главное меню" << endl << 
                  "1) Вывод объёма памяти, отводимого под различные типы данных"
                  << endl << "2) Вывод на экран двоичного представления в памят"
                  "и целого числа" << endl << "3) Вывод на экран двоичного пред"
                  "ставления в памяти типа float" << endl << "4) Вывод на экран"
                  " двоичного представле ния в памяти типа double" << endl << 
                  endl << "Введите желаемый пункт: ";
          int k;
          cin >> k;
          return k;
          break;
        default:
          return 5;
          break;
      }
  }
  
int LAB1menuAskQuestion ()
  {
    int k;
    cout << endl << "Меню:" << endl << "1) Продолжить" << endl << "2) Вернуться"
            " в меню лабораторной" << endl << endl << "Введите желаемый пункт: ";
    cin >> k;
    return k;
  }

int LAB2main ()
  {
    int array[N];
    LAB2generateArray(array);
    int exit=1;
    while (exit) exit=LAB2mainMenu (array);
    return 0;
  }
  
int LAB2mainMenu (int array[])
  {
    system("cls");
    cout << "Текущее состояние массива:" << endl << endl;
    LAB2printArray (array);
    cout << endl;
    cout << endl << "Меню 2 лабораторной:" << endl << "1) Отсортировать массив пузырьк"
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
            " Выход в главное меню." << endl << "Введите желаемый вариант: ";
    int choise;
    cin >> choise;
    switch (choise)
      {
        case 0:
          return 0;
        case 1:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << LAB2bubbleSort(array) << ".";
            Sleep(2000);
            return 1;
          }
        case 2:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << LAB2shakerSort(array) << ".";
            Sleep(2000);
            return 1;
          }
        case 3:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << LAB2combSort(array) << ".";
            Sleep(2000);
            return 1;
          }
        case 4:
          {
            system ("cls");
            cout << "Время, затраченное на сортировку: " << LAB2insertionSort(array) << ".";
            Sleep(2000);
            return 1;          }
        case 5:
          {
            int elements[2];
            double searchTime=LAB2searchMinMax(array, elements);
            cout << endl << "Минимальный элемент равен: " << elements[0] <<
                    endl << "Максимальный элемент равен: " << elements[1] <<
                    endl << "На поиск потрачено времени: " << searchTime << ".";
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 6:
          {
            int elements[2];
            double searchTime=LAB2searchMinMaxSorted(array, elements);
            cout << endl << "Минимальный элемент равен: " << elements[0] <<
                    endl << "Максимальный элемент равен: " << elements[1] <<
                    endl << "На поиск потрачено времени: " << searchTime << ".";
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 7:
          {
            LAB2printMean(array);
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;

          }
        case 8:
          {
            LAB2numberElementsLeft(array);
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 9:
          {
            LAB2numberElementsRight(array);
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 10:
          {
            int n;
            cout << endl << "Введите число: ";
            cin >> n;
            auto begin = system_clock::now();
            int result=LAB2binarySearch(array, n);
            auto end = system_clock::now();
            duration<double> wastedTime = end - begin;
            cout << (result?"В массиве есть такое число.":"В массиве такого числа нет.") << endl;
            cout << "Время, затраченное на поиск: " << wastedTime.count() <<".";
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 11:
          {
            int n;
            cout << endl << "Введите число: ";
            cin >> n;
            auto begin = system_clock::now();
            int result=LAB2search(array, n);
            auto end = system_clock::now();
            duration<double> wastedTime = end - begin;
            cout << (result?"В массиве есть такое число.":"В массиве такого числа нет.") << endl;
            cout << "Время, затраченное на поиск: " << wastedTime.count() <<".";
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
            Sleep(10000);
            return 1;
          }
        case 12:
          {
            auto begin = system_clock::now();
            LAB2changeElements(array);
            auto end = system_clock::now();
            duration<double> wastedTime = end - begin;
            cout << "Время, затраченное на поиск: " << wastedTime.count() <<".";
            cout << endl << "Возврат в меню лаборатоной произойдёт в течении 10 секунд.";
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
  
void LAB2printArray (int array[])
  {
    for (int i=0; i<N; i++)
      {
        if (!(i%10)) cout << endl;
        cout << array[i] << "\t";
      }
  }
  
void LAB2generateArray (int array[])
  {
    for (int i=0; i<N; i++)
      {
        array[i]=(rand()%199)-99;
      }
  }
  
double LAB2bubbleSort (int array[])
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
  
double LAB2shakerSort (int array[])
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

double LAB2combSort (int array[])
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
  
double LAB2insertionSort (int array[])
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

int LAB2binarySearch (int array[], int n)
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

double LAB2searchMinMax (int array[], int elements[2])
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

double LAB2searchMinMaxSorted (int array[], int elements[2])
  {
    auto begin = system_clock::now();
    elements[0]=array[0];
    elements[1]=array[N-1]; 
    auto end = system_clock::now();
    duration<double> wastedTime = end - begin;
    return wastedTime.count();
  }

void LAB2printMean (int array[])
  {
    int elements[2];
    LAB2searchMinMax(array, elements);
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

void LAB2numberElementsLeft(int array[])
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

void LAB2numberElementsRight(int array[])
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

int LAB2search (int array[], int n)
  {
    for (int i=0; i<N; i++)
      {
        if (array[i]==n) return 1;
      }
    return 0;
  }

void LAB2changeElements (int array[])
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

int LAB3main ()
  {
    int matrixRank;
    int *matrixPointer;
    cout << "Введите ранг матрицы: ";
    cin >> matrixRank;
    int Matrix[10][10];
    matrixPointer=&Matrix[0][0];
    LAB3generateZeroMatrix(matrixPointer, matrixRank);
    int exit=1;
    while (exit) exit=LAB3mainMenu (matrixPointer, matrixRank);
    return 0;
  }

int LAB3mainMenu (int *matrixPointer, int matrixRank)
  {
    system("cls");
    cout << "Текущее состояние матрицы:" << endl << endl;
    LAB3printMatrix(matrixPointer, matrixRank);
    cout << endl << "Меню 3 лабораторной:" << endl << "1) Заполнить матрицу случайными"
            " числами по схеме a." << endl << "2) Заполнить матрицу случайными "
            "числами по схеме b." << endl << "3) Преобразовать матрицу в соотве"
            "тствии со схемой a." << endl << "4) Преобразовать матрицу в соотве"
            "тствии со схемой b." << endl << "5) Преобразовать матрицу в соотве"
            "тствии со схемой c." << endl << "6) Преобразовать матрицу в соотве"
            "тствии со схемой d." << endl << "7) Отсортировать матрицу." << endl
            << "8) Произвести арифметические действия над матрицей." << endl <<
            "0) Выход в главное меню." << endl << "Введите желаемый вариант: ";
    int choise;
    cin >> choise;
    switch (choise)
      {
        case 0:
          return 0;
        case 1:
          {
            LAB3generateMatrixA(matrixPointer, matrixRank);
            return 1;
          }
        case 2:
          {
            LAB3generateMatrixB(matrixPointer, matrixRank);
            return 1;
          }
        case 3:
          {
            LAB3changeMatrixA(matrixPointer, matrixRank);
            return 1;
          }
        case 4:
          {
            LAB3changeMatrixB(matrixPointer, matrixRank);
            return 1;
          }
        case 5:
          {
            LAB3changeMatrixC(matrixPointer, matrixRank);
            return 1;
          }
        case 6:
          {
            LAB3changeMatrixD(matrixPointer, matrixRank);
            return 1;
          }
        case 7:
          {
            LAB3sortMatrix(matrixPointer, matrixRank);
            return 1;
          }
        case 8:
          {
            int choise=1;
            while (choise) choise=LAB3arithmeticMatrix(matrixPointer, matrixRank);
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

void LAB3generateZeroMatrix (int *matrixPointer, int matrixRank)
  {
    for (int i=0; i<matrixRank*matrixRank; i++) *(matrixPointer+i)=0;
  }
  
void LAB3generateMatrixA (int *matrixPointer, int matrixRank)
  {
    system("cls");
    for (int stop=0; stop<matrixRank/2; stop++)
      {
        for (int i=0; i<matrixRank-2*stop; i++)
          {
            *(matrixPointer+((matrixRank+1)*stop)+i)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            LAB3printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
        for (int i=1+stop; i<matrixRank-stop; i++)
          {
            *(matrixPointer+(i+1)*matrixRank-stop-1)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            LAB3printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
        for (int i=matrixRank-1; i>2*stop; i--)
          {
            *(matrixPointer+(matrixRank-1-stop)*matrixRank+i-stop-1)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            LAB3printMatrix(matrixPointer, matrixRank); 
            cout << endl;
          }
        for (int i=matrixRank-2-stop; i>stop; i--)
          {
            *(matrixPointer+matrixRank*i+stop)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            LAB3printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
      }
    system("cls");
    cout << "Выполнено!";
    Sleep(1000);
  }
  
void LAB3generateMatrixB (int *matrixPointer, int matrixRank)
  {
    system("cls");
    for (int column=0; column<matrixRank; column++)
      {
        for (int i=0; i<matrixRank; i++)
          {
            *(matrixPointer+matrixRank*i+column)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            LAB3printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
        column++;
        for (int i=matrixRank-1; i>-1; i--)
          {
            *(matrixPointer+matrixRank*i+column)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            LAB3printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
      }
    system("cls");
    cout << "Выполнено!";
    Sleep(1000);
  }
  
void LAB3printMatrix (int *matrixPointer, int matrixRank)
  {
    for (int i=0; i<matrixRank*matrixRank; i++)
      {
        cout << *(matrixPointer+i) << "\t";
        if (i%matrixRank==matrixRank-1) cout << endl;
      }
  }

void LAB3changeMatrixA (int *matrixPointer, int matrixRank)
  {
    for (int i=0; i<matrixRank/2; i++)
      {
        for (int j=0; j<matrixRank/2; j++)
          {
            *(matrixPointer+i+matrixRank*j) = *(matrixPointer+i+matrixRank*j) + *(matrixPointer+i+matrixRank/2+matrixRank*j);
            *(matrixPointer+i+matrixRank/2+matrixRank*j) = *(matrixPointer+i+matrixRank*j) - *(matrixPointer+i+matrixRank/2+matrixRank*j);
            *(matrixPointer+i+matrixRank*j) = *(matrixPointer+i+matrixRank*j) - *(matrixPointer+i+matrixRank/2+matrixRank*j);
          }
      }
    for (int i=0; i<matrixRank/2; i++)
      {
        for (int j=0; j<matrixRank/2; j++)
          {
            *(matrixPointer+i+matrixRank*j) = *(matrixPointer+i+matrixRank*j) + *(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j);
            *(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j) = *(matrixPointer+i+matrixRank*j) - *(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j);
            *(matrixPointer+i+matrixRank*j) = *(matrixPointer+i+matrixRank*j) - *(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j);
          }
      }
    for (int i=0; i<matrixRank/2; i++)
      {
        for (int j=matrixRank/2; j<matrixRank; j++)
          {
            *(matrixPointer+i+matrixRank*j) = *(matrixPointer+i+matrixRank*j) + *(matrixPointer+i+matrixRank/2+matrixRank*j);
            *(matrixPointer+i+matrixRank/2+matrixRank*j) = *(matrixPointer+i+matrixRank*j) - *(matrixPointer+i+matrixRank/2+matrixRank*j);
            *(matrixPointer+i+matrixRank*j) = *(matrixPointer+i+matrixRank*j) - *(matrixPointer+i+matrixRank/2+matrixRank*j);
          }
      }
  }

void LAB3changeMatrixB  (int *matrixPointer, int matrixRank)
  {
    int buffer;
    for (int i=0; i<matrixRank/2; i++)
      {
        for (int j=0; j<matrixRank/2; j++)
          {
            buffer=*(matrixPointer+i+matrixRank*j);
            *(matrixPointer+i+matrixRank*j)=*(matrixPointer+i+matrixRank*j+matrixRank/2*matrixRank+matrixRank/2);
            *(matrixPointer+i+matrixRank*j+matrixRank/2*matrixRank+matrixRank/2)=buffer;
          }
      }
    for (int i=matrixRank/2; i<matrixRank; i++)
      {
        for (int j=0; j<matrixRank/2; j++)
          {
            buffer=*(matrixPointer+i+matrixRank*j);
            *(matrixPointer+i+matrixRank*j)=*(matrixPointer+i+matrixRank*j+matrixRank/2*matrixRank-matrixRank/2);
            *(matrixPointer+i+matrixRank*j+matrixRank/2*matrixRank-matrixRank/2)=buffer;
          }
      }
  }

void LAB3changeMatrixC  (int *matrixPointer, int matrixRank)
  {
    for (int i=0; i<matrixRank/2; i++)
      {
        for (int j=0; j<matrixRank/2; j++)
          {
            int buffer;
            buffer=*(matrixPointer+i+matrixRank*j);
            *(matrixPointer+i+matrixRank*j)=*(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j);
            *(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j)=buffer;
          }
      }
    for (int i=matrixRank/2; i<matrixRank; i++)
      {
        for (int j=0; j<matrixRank/2; j++)
          {
            int buffer;
            buffer=*(matrixPointer+i+matrixRank*j);
            *(matrixPointer+i+matrixRank*j)=*(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j);
            *(matrixPointer+i+matrixRank/2*matrixRank+matrixRank*j)=buffer;
          }
      }
  }
  
void LAB3changeMatrixD  (int *matrixPointer, int matrixRank)
  {
    for (int i=0; i<matrixRank/2; i++)
      {
        for (int j=0; j<matrixRank/2; j++)
          {
            int buffer;
            buffer=*(matrixPointer+i+matrixRank*j);
            *(matrixPointer+i+matrixRank*j)=*(matrixPointer+i+matrixRank/2+matrixRank*j);
            *(matrixPointer+i+matrixRank/2+matrixRank*j)=buffer;
          }
      }
    for (int i=0; i<matrixRank/2; i++)
      {
        for (int j=matrixRank/2; j<matrixRank; j++)
          {
            int buffer;
            buffer=*(matrixPointer+i+matrixRank*j);
            *(matrixPointer+i+matrixRank*j)=*(matrixPointer+i+matrixRank/2+matrixRank*j);
            *(matrixPointer+i+matrixRank/2+matrixRank*j)=buffer;
          }
      }
  }

void LAB3sortMatrix (int *matrixPointer, int matrixRank)
  {
    int sorted=0;
    int currentMaxUnsorted=matrixRank*matrixRank-1;
    while (!sorted)
      {
        sorted=1;
        for (int i=0; i<currentMaxUnsorted; i++)
          {
            if (*(matrixPointer+i)-*(matrixPointer+i+1)>0)
              {
                *(matrixPointer+i) = *(matrixPointer+i) + *(matrixPointer+i+1);
                *(matrixPointer+i+1) = *(matrixPointer+i) - *(matrixPointer+i+1);
                *(matrixPointer+i) = *(matrixPointer+i) - *(matrixPointer+i+1);
                sorted=0;
              }
          }
        currentMaxUnsorted--;
      }
  }

int LAB3arithmeticMatrix (int *matrixPointer, int matrixRank)
  {
    system("cls");
    cout << "Текущее состояние матрицы:" << endl << endl;
    LAB3printMatrix(matrixPointer, matrixRank);
    cout << "Доступные действия:" << endl << "1) Вычитание." << endl << "2) Сло"
            "жение." << endl << "3) Умножение." << endl << "4) Деление." << endl
            << "Чтобы выйти в меню лабораторной введите 0." << endl << endl << "Введ"
            "ите номер желаемого действия: ";
    int choise;
    cin >> choise;
    switch (choise)
      {
        case 1:
          {
            cout << "Введите число, которое вы хотите вычесть из матрицы: ";
            int number;
            cin >> number;
            for (int i=0; i<matrixRank*matrixRank; i++)
              {
                *(matrixPointer+i)=*(matrixPointer+i)-number;
              }
            return 1;
          }
        case 2:
          {
            cout << "Введите число, которое вы хотите прибавить к матрице: ";
            int number;
            cin >> number;
            for (int i=0; i<matrixRank*matrixRank; i++)
              {
                *(matrixPointer+i)=*(matrixPointer+i)+number;
              }
            return 1;
          }
        case 3:
          {
            cout << "Введите число, на которое вы хотите умножить матрицу: ";
            int number;
            cin >> number;
            for (int i=0; i<matrixRank*matrixRank; i++)
              {
                *(matrixPointer+i)=*(matrixPointer+i)*number;
              }
            return 1;
          }
        case 4:
          {
            cout << "Введите число, на которое вы хотите разделить матрицу: ";
            int number;
            cin >> number;
            for (int i=0; i<matrixRank*matrixRank; i++)
              {
                *(matrixPointer+i)=*(matrixPointer+i)/number;
              }
            return 1;
          }
        default:
          {
            return 0;
          }
      }
  }

int LAB4main ()
  {
    char String[Stringlength];
    char stringOriginal[Stringlength];
    int exit=1;
    system("cls");
    cout << "Откуда прочитать строку:" << endl << "1) из терминала." << endl <<
            "2) из файла." << endl << endl << "Введите желаемый вариант: ";
    int choise;
    cin >> choise;
    cin.get();
    switch (choise)
      {
        case 1:
          {
            LAB4readTextFromTerminal(String);
            break;
          }
        case 2:
          {
            int result=LAB4readTextFromFile(String);
            if (!result)
              {
                system ("cls");
                cout << "Ошибка чтения файла!";
                Sleep (1000);
                return 1;
              }
            break;
          }
      }
    strcpy(stringOriginal, String);
    while (exit) exit=LAB4mainMenu(String, stringOriginal);
    return 0;
  }

int LAB4mainMenu (char String[], char stringOriginal[])
  {
    int choise;
    cout << "Текущее состояние строки:" << endl << endl;
    cout << String;
    cout << endl;
    cout << endl << "Главное меню работы со строкой:" << endl << "1) Атоматичес"
            "ки отредактировать строку." << endl << "2) Восстановить исходную с"
            "троку." << endl << "3) Вывести на экран слова последовательности в"
            " алфавитном порядке." << endl << "4) Вывести на экран количество с"
            "имволов в каждом слове исходной последовательности." << endl << 
            "5) Найти подстроки с помощью линейного поиска." << endl << "0) Вых"
            "од в главное меню программы." << endl << "Введите желаемый вариант: ";
    cin >> choise;
    switch (choise)
      {
        case 0:
          return 0;
        case 1:
          {
            LAB4stringRedactor(String);
            return 1;
          }
        case 2:
          {
            strcpy(String, stringOriginal);
            return 1;
          }
        case 3:
          {
            system ("cls");
            char sortedString[51][11];
            int sortedStringElements=LAB4alphabeticalSort(String, sortedString);
            cout << "Отсортрованные в алфавитном порядке слова:" << endl;
            for (int i=0; i<sortedStringElements+1; i++) cout << sortedString[i] << " ";
            cout << endl << endl;
            return 1;
          }
        case 4:
          {
            system ("cls");
            cout << "Число символов в каждом слове:" << endl;
            LAB4numberSymbols(String);
            cout << endl << endl;
            return 1;          }
        case 5:
          {
            system ("cls");
            LAB4linearSearch(String);
            cout << endl << endl;
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

int LAB4readTextFromTerminal (char String[])
  {
    cin.getline (String, 1000);
    cin.sync();
    return 1;
  } 
  
int LAB4readTextFromFile (char String[])
  {
    char Name[Stringlength];
    cout << endl << "Введите имя (или путь) файла: ";
    cin.clear();
    cin.sync();
    cin.getline (Name, Stringlength);
    ifstream File;
    File.open (Name);
    if (!File) return 0;
    File.getline (String, Stringlength);
    File.close();
    return 1;
  }
  
int LAB4isCharASpace (char Char)
  {
    if (((int)Char)-32) return 0;
    return 1;
  }
  
int LAB4isCharASign (char Char)
  {
    if (((((int)Char>32)&&((int)Char<48))&&((int)Char-46))||(((int)Char>57)&&((int)Char<65))||(((int)Char>90)&&((int)Char<97))||(((int)Char>122)&&((int)Char<128))) return 1;
    return 0;
  }
  
int LAB4isCharACapital (char Char)
  {
    if (((int)Char>64)&&((int)Char<91)) return 1;
    return 0;
  }
  
int LAB4isCharADot (char Char)
  {
    if (((int)Char)-46) return 0;
    return 1;
  }

void LAB4stringRedactor (char String[])
  {
    int isFirst=1;
    int Length=strlen(String);
    for (int i=0; i < Length; i++)
      {
        if (!(isFirst))
          if (LAB4isCharACapital(String[i])) 
            {
              String[i]=(int)String[i]+32;
            };
        isFirst=0;
        if (LAB4isCharASpace(String[i]))
          {
            int number=0;
            while (LAB4isCharASpace(String[i+1+number])) number++;
            if (number) LAB4StringCut (String, i+1, number);
            isFirst=1;
          }
        if (LAB4isCharASign(String[i]))
          {
            int number=0;
            while (LAB4isCharASign(String[i+1+number])||LAB4isCharADot(String[i+1+number])) number++;
            if (number) LAB4StringCut (String, i+1, number);
            isFirst=1;
          }
        if (LAB4isCharADot(String[i]))
          {
            int ellipsis=0;
            for (int j=i+1; j<i+3; j++)
              {
                if (LAB4isCharADot(String[j])) ellipsis++;
              }
            if (ellipsis==2)
              {
                i=i+1;
              }
            else
              {
                int number=0;
                while (LAB4isCharASign(String[i+1+number])||LAB4isCharADot(String[i+1+number])) number++;
                if (number) LAB4StringCut (String, i+1, number);
              }
            isFirst=1;
          }
      }
  }
  
void LAB4StringCut (char String[], int position, int number)
  {
    int i;
    for (i=position; i<strlen(String); i++) String[i]=String[i+number];
  }
  
int LAB4alphabeticalSort (char String[], char sortedString[51][11])
  {
    char stringMod[Stringlength];
    strcpy(stringMod, String);
    int Length=strlen(stringMod);
    for (int i=0; i < Length; i++)
      {
        if ((LAB4isCharASign(stringMod[i]))||(LAB4isCharADot(stringMod[i]))) stringMod[i]=' ';
      }
    for (int i=0; i < Length; i++)
      if (LAB4isCharASpace(stringMod[i]))
          {
            int number=0;
            while (LAB4isCharASpace(stringMod[i+1+number])) number++;
            if (number) LAB4StringCut (stringMod, i+1, number);
          };
    if (LAB4isCharASpace(stringMod[0])) LAB4StringCut (stringMod, 0, 1);
    int sortedStringElements=0, k=0;
    for (int i=0; i<strlen(stringMod); i++)
      {
        if (LAB4isCharASpace(stringMod[i]))
          {
            sortedString[sortedStringElements][k]='\0';
            sortedStringElements++;
            k=0;
          }
        else 
          {
            sortedString[sortedStringElements][k]=stringMod[i];
            k++;
          }
      }
    sortedString[sortedStringElements][k]='\0';
    int sorted=0;
    int currentMaxUnsorted=sortedStringElements-1;
    while (!sorted)
      {
        sorted=1;
        for (int i=0; i<currentMaxUnsorted; i++)
          {
            if (strcmp(sortedString[i], sortedString[i+1])>0)
              {
                char buffer[11];
                strcpy(buffer, sortedString[i]);
                strcpy(sortedString[i], sortedString[i+1]);
                strcpy(sortedString[i+1], buffer);
                sorted=0;
              }
          }
        currentMaxUnsorted--;
        }
    return sortedStringElements;
  }  
  
void LAB4numberSymbols (char String[])
  {
    char sortedString[51][11];
    int sortedStringElements=LAB4alphabeticalSort (String, sortedString);
    cout << endl;
    for (int i=0; i<sortedStringElements+1;i++) cout << strlen(sortedString[i]) << "\t" << sortedString[i] << endl;
    cout << endl;
  }
  
void LAB4linearSearch (char String[])
  {
    char searchString[Stringlength];
    cin.get();
    cout << endl << "Введите подстроку для поиска: ";
    cin.getline(searchString, Stringlength);
    int result=-1;
    cout << endl << "Искомая подстрока содержится на следующих диапозонах символов: ";
    for (int i=0; String[i] ; i++)
      for (int j=0; ; j++)
        {
          if (!searchString[j]) 
            {
              result=i;
              cout << i+1 << "-" << i+j << " ";
              break;
            }
          if(String[i+j]!=searchString[j]) break;
        };
	  if (result<0) cout << endl << "Таких подстрок нет!";
  }



