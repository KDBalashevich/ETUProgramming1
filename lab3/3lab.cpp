#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

int mainMenu (int *matrixPointer, int matrixRank);
void generateZeroMatrix (int *matrixPointer, int matrixRank);
void generateMatrixA (int *matrixPointer, int matrixRank);
void generateMatrixB (int *matrixPointer, int matrixRank);
void printMatrix (int *matrixPointer, int matrixRank);
void changeMatrixA (int *matrixPointer, int matrixRank);
void changeMatrixB (int *matrixPointer, int matrixRank);
void changeMatrixC (int *matrixPointer, int matrixRank);
void changeMatrixD (int *matrixPointer, int matrixRank);
void sortMatrix (int *matrixPointer, int matrixRank);
int arithmeticMatrix (int *matrixPointer, int matrixRank);

int main ()
  {
    int matrixRank;
    int *matrixPointer;
    
    setlocale(LC_ALL, "ru_RU.utf8");
    //setlocale(0, "");
    srand(time(0));
    
    cout << "Введите ранг матрицы: ";
    cin >> matrixRank;
    int Matrix[10][10];
    matrixPointer=&Matrix[0][0];
    generateZeroMatrix(matrixPointer, matrixRank);
    int exit=1;
    while (exit) exit=mainMenu (matrixPointer, matrixRank);
    return 0;
  }

int mainMenu (int *matrixPointer, int matrixRank)
  {
    system("cls");
    cout << "Текущее состояние матрицы:" << endl << endl;
    printMatrix(matrixPointer, matrixRank);
    cout << endl << "Главное меню:" << endl << "1) Заполнить матрицу случайными"
            " числами по схеме a." << endl << "2) Заполнить матрицу случайными "
            "числами по схеме b." << endl << "3) Преобразовать матрицу в соотве"
            "тствии со схемой a." << endl << "4) Преобразовать матрицу в соотве"
            "тствии со схемой b." << endl << "5) Преобразовать матрицу в соотве"
            "тствии со схемой c." << endl << "6) Преобразовать матрицу в соотве"
            "тствии со схемой d." << endl << "7) Отсортировать матрицу." << endl
            << "8) Произвести арифметические действия над матрицей." << endl <<
            "0) Выход из программы." << endl << "Введите желаемый вариант: ";
    int choise;
    cin >> choise;
    switch (choise)
      {
        case 0:
          return 0;
        case 1:
          {
            generateMatrixA(matrixPointer, matrixRank);
            return 1;
          }
        case 2:
          {
            generateMatrixB(matrixPointer, matrixRank);
            return 1;
          }
        case 3:
          {
            changeMatrixA(matrixPointer, matrixRank);
            return 1;
          }
        case 4:
          {
            changeMatrixB(matrixPointer, matrixRank);
            return 1;
          }
        case 5:
          {
            changeMatrixC(matrixPointer, matrixRank);
            return 1;
          }
        case 6:
          {
            changeMatrixD(matrixPointer, matrixRank);
            return 1;
          }
        case 7:
          {
            sortMatrix(matrixPointer, matrixRank);
            return 1;
          }
        case 8:
          {
            int choise=1;
            while (choise) choise=arithmeticMatrix(matrixPointer, matrixRank);
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

void generateZeroMatrix (int *matrixPointer, int matrixRank)
  {
    for (int i=0; i<matrixRank*matrixRank; i++) *(matrixPointer+i)=0;
  }
  
void generateMatrixA (int *matrixPointer, int matrixRank)
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
            printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
        for (int i=1+stop; i<matrixRank-stop; i++)
          {
            *(matrixPointer+(i+1)*matrixRank-stop-1)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
        for (int i=matrixRank-1; i>2*stop; i--)
          {
            *(matrixPointer+(matrixRank-1-stop)*matrixRank+i-stop-1)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            printMatrix(matrixPointer, matrixRank); 
            cout << endl;
          }
        for (int i=matrixRank-2-stop; i>stop; i--)
          {
            *(matrixPointer+matrixRank*i+stop)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
      }
    system("cls");
    cout << "Выполнено!";
    Sleep(1000);
  }
  
void generateMatrixB (int *matrixPointer, int matrixRank)
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
            printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
        column++;
        for (int i=matrixRank-1; i>-1; i--)
          {
            *(matrixPointer+matrixRank*i+column)=rand()%(matrixRank*matrixRank)+1;
            Sleep(500);
            system("cls");
            cout << "Матрица заполняется:" << endl;
            printMatrix(matrixPointer, matrixRank);
            cout << endl;
          }
      }
    system("cls");
    cout << "Выполнено!";
    Sleep(1000);
  }
  
void printMatrix (int *matrixPointer, int matrixRank)
  {
    for (int i=0; i<matrixRank*matrixRank; i++)
      {
        cout << *(matrixPointer+i) << "\t";
        if (i%matrixRank==matrixRank-1) cout << endl;
      }
  }

void changeMatrixA (int *matrixPointer, int matrixRank)
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

void changeMatrixB  (int *matrixPointer, int matrixRank)
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

void changeMatrixC  (int *matrixPointer, int matrixRank)
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
  
void changeMatrixD  (int *matrixPointer, int matrixRank)
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

void sortMatrix (int *matrixPointer, int matrixRank)
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

int arithmeticMatrix (int *matrixPointer, int matrixRank)
  {
    system("cls");
    cout << "Текущее состояние матрицы:" << endl << endl;
    printMatrix(matrixPointer, matrixRank);
    cout << "Доступные действия:" << endl << "1) Вычитание." << endl << "2) Сло"
            "жение." << endl << "3) Умножение." << endl << "4) Деление." << endl
            << "Чтобы выйти в главное меню введите 0." << endl << endl << "Введ"
            "ите номер желаемоо действия: ";
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
