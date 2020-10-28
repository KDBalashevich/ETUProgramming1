#include <iostream>
#include <climits>

using namespace std;

int menuMain (int request);
int menuAskQuestion ();
void printSizeof ();
void printBinInt ();
void printBinFloat ();
void printBinDouble ();

int main ()
  {
    setlocale(LC_ALL, "ru_RU.utf8");
    int i;
    i=menuMain (5);
    while (i)
      {
        i=menuMain (i);
      }
    return 0;
  }

void printSizeof ()
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

void printBinInt ()
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
  
void printBinFloat ()
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
  
void printBinDouble ()
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

int menuMain (int request)
  {
    int k;
    switch (request)
      {
        case 0:
          return 0;
          break;
        case 1:
          printSizeof ();
          return 5;
          break;
        case 2:
          printBinInt();
          k=menuAskQuestion();
          if (k==2||!k) return 5;
            else return 2;
          break;
        case 3:
          printBinFloat();
          k=menuAskQuestion();
          if (k==2||!k) return 5;
            else return 3;
          break;
        case 4:
          printBinDouble();
          k=menuAskQuestion();
          if (k==2||!k) return 5;
            else return 4;
          break;
        case 5:
          cout << "Главное меню:" << endl << "0) Вызод из программы" << endl << 
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
  
int menuAskQuestion ()
  {
    int k;
    cout << endl << "Меню:" << endl << "1) Продолжить" << endl << "2) Вернуться"
            " в главное меню" << endl << endl << "Введите желаемый пункт: ";
    cin >> k;
    return k;
  }
