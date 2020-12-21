#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <ctime>
#define Stringlength 1000

using namespace std;

int readTextFromTerminal (char String[]);
int readTextFromFile (char String[]);
int mainMenu (char String[], char stringOriginal[]);
int isCharASpace (char Char);
int isCharASign (char Char);
int isCharACapital (char Char);
int isCharADot (char Char);
void stringRedactor (char String[]);
void StringCut (char String[], int position, int number);
int alphabeticalSort (char String[], char sortedString[51][11]);
void numberSymbols (char String[]);
void linearSearch (char String[]);

int main ()
  {
    //ВНИМАНИЕ!!! В СЛУЧАЕ ПРОБЛЕМ С ОТОБРАЖЕНИЕМ МЕНЮ РАСКОММЕНТИРУЙТЕ ДРУГУЮ СТРОЧКУ SETLOCALE!!!
    setlocale(LC_ALL, "ru_RU.utf8");
    //setlocale (0, "");
    //setlocale (LC_ALL, "Russian");
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
            readTextFromTerminal(String);
            break;
          }
        case 2:
          {
            int result=readTextFromFile(String);
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
    while (exit) exit=mainMenu(String, stringOriginal);
    return 0;
  }

int mainMenu (char String[], char stringOriginal[])
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
            "од из программы." << endl << "Введите желаемый вариант: ";
    cin >> choise;
    switch (choise)
      {
        case 0:
          return 0;
        case 1:
          {
            stringRedactor(String);
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
            int sortedStringElements=alphabeticalSort(String, sortedString);
            cout << "Отсортрованные в алфавитном порядке слова:" << endl;
            for (int i=0; i<sortedStringElements; i++) cout << sortedString[i] << " ";
            cout << endl << endl;
            return 1;
          }
        case 4:
          {
            system ("cls");
            cout << "Число символов в каждом слове:" << endl;
            numberSymbols(String);
            cout << endl << endl;
            return 1;          }
        case 5:
          {
            system ("cls");
            linearSearch(String);
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

int readTextFromTerminal (char String[])
  {
    cin.getline (String, 1000);
    cin.sync();
    return 1;
  } 
  
int readTextFromFile (char String[])
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
  
int isCharASpace (char Char)
  {
    if (((int)Char)-32) return 0;
    return 1;
  }
  
int isCharASign (char Char)
  {
    if (((((int)Char>32)&&((int)Char<48))&&((int)Char-46))||(((int)Char>57)&&((int)Char<65))||(((int)Char>90)&&((int)Char<97))||(((int)Char>122)&&((int)Char<128))) return 1;
    return 0;
  }
  
int isCharACapital (char Char)
  {
    if (((int)Char>64)&&((int)Char<91)) return 1;
    return 0;
  }
  
int isCharADot (char Char)
  {
    if (((int)Char)-46) return 0;
    return 1;
  }

void stringRedactor (char String[])
  {
    int isFirst=1;
    int Length=strlen(String);
    for (int i=0; i < Length; i++)
      {
        if (!(isFirst))
          if (isCharACapital(String[i])) 
            {
              String[i]=(int)String[i]+32;
            };
        isFirst=0;
        if (isCharASpace(String[i]))
          {
            int number=0;
            while (isCharASpace(String[i+1+number])) number++;
            if (number) StringCut (String, i+1, number);
            isFirst=1;
          }
        if (isCharASign(String[i]))
          {
            int number=0;
            while (isCharASign(String[i+1+number])||isCharADot(String[i+1+number])) number++;
            if (number) StringCut (String, i+1, number);
            isFirst=1;
          }
        if (isCharADot(String[i]))
          {
            int ellipsis=0;
            for (int j=i+1; j<i+3; j++)
              {
                if (isCharADot(String[j])) ellipsis++;
              }
            if (ellipsis==2)
              {
                i=i+1;
              }
            else
              {
                int number=0;
                while (isCharASign(String[i+1+number])||isCharADot(String[i+1+number])) number++;
                if (number) StringCut (String, i+1, number);
              }
            isFirst=1;
          }
      }
  }
  
void StringCut (char String[], int position, int number)
  {
    int i;
    for (i=position; i<strlen(String); i++) String[i]=String[i+number];
  }
  
int alphabeticalSort (char String[], char sortedString[51][11])
  {
    char stringMod[Stringlength];
    strcpy(stringMod, String);
    int Length=strlen(stringMod);
    for (int i=0; i < Length; i++)
      {
        if ((isCharASign(stringMod[i]))||(isCharADot(stringMod[i]))) stringMod[i]=' ';
      }
    for (int i=0; i < Length; i++)
      if (isCharASpace(stringMod[i]))
          {
            int number=0;
            while (isCharASpace(stringMod[i+1+number])) number++;
            if (number) StringCut (stringMod, i+1, number);
          };
    if (isCharASpace(stringMod[0])) StringCut (stringMod, 0, 1);
    int sortedStringElements=0;
    for (int i=0, k=0; i<strlen(stringMod); i++)
      {
        if (isCharASpace(stringMod[i]))
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
  
void numberSymbols (char String[])
  {
    char sortedString[51][11];
    int sortedStringElements=alphabeticalSort (String, sortedString);
    cout << endl;
    for (int i=0; i<sortedStringElements;i++) cout << strlen(sortedString[i]) << "\t" << sortedString[i] << endl;
    cout << endl;
  }
  
void linearSearch (char String[])
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
