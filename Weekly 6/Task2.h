#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
std::string ExamBuffer = "";
char buffer1;
char buffer2;
double averageScore;

struct Student {
    std::string name;
    std::string answer;
    int score;
};
void ExamGrades() {
    system("cls");

    std::vector <Student> Stud;

    Stud.push_back(Student());
    Stud[0].name = "John";
    Stud[0].answer = "ABDCAB";

    Stud.push_back(Student());
    Stud[1].name = "Sara";
    Stud[1].answer = "ABCCAB";

    Stud.push_back(Student());
    Stud[2].name = "Laila";
    Stud[2].answer = "BACCAB";

    std::fstream Exam("ExamAnswers.txt", std::ios::in);
    std::getline(Exam, ExamBuffer);

    for (int i = 0; i < Stud.size(); i++) {
        for (int j = 0; j < ExamBuffer.size(); j++) {
            buffer1 = ExamBuffer[j];
            buffer2 = Stud[i].answer[j];
            if (buffer2 == buffer1) {
                Stud[i].score++;
            }
        }
    }
    Exam.close();
    for (int i = 0; i < Stud.size(); i++) {
        averageScore += Stud[i].score;
    }
    averageScore = averageScore / Stud.size();

    std::cout << "Student Name\t" << "Score\n";
    for (int i = 0; i < 3; i++) {
        std::cout << Stud[i].name << "\t\t  " << Stud[i].score << '\n';
    }
    std::cout << '\n';
    std::cout << "Number of students: " << Stud.size() << '\n';
    std::cout << "Average grade: " << averageScore << '\n';
    std::cout << "Max Score: " << Stud[0].score << '\n';
    std::cout << "Min Score: " << Stud[2].score << '\n';
    std::cout << '\n';
    system("pause");
}
