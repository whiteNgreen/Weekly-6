#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
std::string search = "";
std::string input = "";
std::string temp = "";
int sCounter;
int printCounter;
int toupperCount;

void FindWord() {
    system("cls");
    std::cout << "Currently searching the file 'Story.txt' which you can read in task 3\n";
    std::cout << '\n';
    std::fstream FileToSearch("Story.txt", std::ios::in);
    printCounter = 0;
    std::cin >> input;

    while (!FileToSearch.eof()) {
        temp = input;
        sCounter = 0;
        toupperCount = 0;
        std::getline(FileToSearch, search);
        while (toupperCount < 3) {
            std::string::size_type found = search.find(temp);
            if (found != std::string::npos) {
                sCounter++;
                std::cout << sCounter << '\n';
            }
            if (toupperCount == 1) {
                temp[0] = toupper(temp[0]);
            }
            if (toupperCount == 2) {
                for (int i = 0; i < temp.size(); i++) {
                    temp[i] = toupper(temp[i]);
                }
            }
            toupperCount++;
        }
        /*found = search.find(temp);
        if (found != std::string::npos) {
            sCounter++;
            std::cout << sCounter << '\n';
        }*/

        //  Tried to use this in case there were multiple uses of the wanted word in the same sentence
        //   ,but i couldnt get the count to properly work as it seemed to double count everything. 
        //while (found != std::string::npos) {  
        //    sCounter++;
        //    std::cout << sCounter << '\n';
        //    found = search.find(input, found + sCounter);
        //    //std::cout << "Found at " << found << '\n';
        //    //std::cout << "test: " << sCounter << '\n';
        //}
        printCounter += sCounter;
    }
    std::cout << "Found '" << printCounter << "' counts of the word " << "'" << input << "'" << '\n';
    FileToSearch.close();
    std::cout << '\n';
    system("pause");
}
