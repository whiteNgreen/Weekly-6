// Weekly 6
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
#include <conio.h>

#include "Task1.h"
#include "Task2.h"
#include "Task4.h"
#include "Task3.h"

char menuInput;

int main()
{

    do {
        system("cls");
        std::cout << "Chose a task to see\n1. Find Password\n2. ExamGrades\n3. Find Word\n4. Copy story to file\n";
        menuInput = _getch();
        switch (menuInput)
        {
        case'1':
            FindPassword();
            break;
        case'2':
            ExamGrades();
            break;
        case'3':
            FindWord();
            break;
        case'4':
            Task4();
            break;
        default:
            break;
        }
    } while (true);

    return 0;
}

