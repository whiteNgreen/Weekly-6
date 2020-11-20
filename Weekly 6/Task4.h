#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <conio.h>

std::string copy = "";
char t4Input;

void ClearCopyFile() {
    std::fstream Clear("CopyFile.txt", std::ios::out);
    Clear.close();
}
void CopyToNewFile() {
    system("cls");
    std::fstream CopyFrom("Story.txt", std::ios::in);
    std::fstream CopyTo("CopyFile.txt", std::ios::out | std::ios::app);
    if (CopyFrom && CopyTo) {
        while (!CopyFrom.eof()) {
            std::getline(CopyFrom, copy);
            CopyTo << copy << '\n';
        }
    }
    copy = "";
    CopyFrom.close();
    CopyTo.close();
}
void ReadStory() {
    std::fstream ReadStory("CopyFile.txt", std::ios::in);
    if (ReadStory) {
        while (!ReadStory.eof()) {
            std::getline(ReadStory, copy);
            std::cout << copy << '\n';
        }
    }
    ReadStory.close();
    std::cout << '\n';
    system("pause");
}

void Task4() {

    do {
        system("cls");
        std::cout << "Task 3\n1. To clear the file\n2. Copy the story to the file\n3. Read the file\n";
        t4Input = _getch();
        switch (t4Input)
        {
        case'1':
            ClearCopyFile();
            break;
        case'2':
            CopyToNewFile();
            break;
        case'3':
            ReadStory();
        case'q':case'Q':
            return;
            break;
        default:
            break;
        }
    } while (true);
}