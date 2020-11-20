#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void FindPassword() {
    system("cls");
    std::string password = "013193pm";
    std::string Buffer = "";
    int counter = 0;
    std::fstream List("List.txt", std::ios::in);
    if (List) {
        while (!List.eof()) {
            counter++;
            std::getline(List, Buffer);
            if (Buffer == password) {
                std::cout << "Password is: " << Buffer << "\nFound on line: " << counter << '\n';
            }
        }
    }
    List.close();
    std::cout << '\n';
    system("pause");
}