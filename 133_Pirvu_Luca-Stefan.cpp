/*
Proiect: Simulare LeetCode
Descriere:

Acest program simulează o versiune simplificată a unei platforme online de codare, precum LeetCode.
Definește trei clase principale:

    Person: Reprezintă un utilizator care rezolvă probleme.
    Problem: Reprezintă o problemă de programare cu un nivel de dificultate și soluții asociate.
    Submission: Reprezintă o trimitere a unui utilizator, 
    stocând liniile de cod și permițând executarea acestuia.

Date de intrare:

    Un set predefinit de utilizatori (obiecte Person) cu nume și ID-uri.
    Un set predefinit de probleme (obiecte Problem) cu ID-uri unice, niveluri de dificultate și descrieri.
    Trimiteri simulate care urmăresc soluțiile de cod.

Funcționalități implementate:
    Constructori cu parametri pentru fiecare clasă.
    Constructor de copiere, operator de atribuire prin copiere și destructor pentru fiecare clasă.
    Supraincarcarea operatorului << pentru afișare formatată.
    Atribute private și metode const, unde este aplicabil.
    Proiectul contine si 3 functii membre, dintre care una mai complexa
*/

#include "133_Pirvu_Luca-Stefan.h"

void Submission::runSubmission() const {
    std::ofstream file("submission.cpp");
    
    for (const auto& line : m_code) {
        file << line << "\n";
    }
    file.close();

    std::cout << std::endl << "Running the submission by " << m_user << ":" << std::endl;
    std::system("g++ submission.cpp -o submission.exe");
    std::system("./submission.exe");
}

void Problem::AddSubmission(const Submission& submission) {
    m_submissions.push_back(submission);
}

void Problem::DisplaySubmissions() const {
    std::cout << "Submissions for Problem " << m_problemID << ":\n";
    for (const auto& submission : m_submissions) {
        std::cout << submission << "\n";
    }
}

int main() {
    Person user1("Alice", 1);
    Person user2("Bob", 2);
    
    Problem problem1(101, "Easy", "Find the sum of two numbers.");
    Problem problem2(102, "Hard", "Implement a balanced binary search tree.");
    Problem problem3(103, "Medium", "Given an integer p, return 1 if p is prime, 0 otherwise");

    std::vector<std::string> code1 = {"#include <iostream>", "int main() {", "    std::cout << 2 + 2;", "    return 0;", "}"};
    std::vector<std::string> code2 = {"#include <iostream>", "int main() {", "    std::cout << 'Hello, world!';", "    return 0;", "}"};
    
    std::ifstream fin("Prime_Submission.txt");
    std::vector<std::string> code3;
    std::string line;
    while(std::getline(fin, line)) {
        code3.push_back(line);
    }
    fin.close();

    Submission sub1(user1, code1);
    Submission sub2(user2, code2);
    Submission sub3(user2, code3);
    
    problem1.AddSubmission(sub1);
    problem2.AddSubmission(sub2);
    problem3.AddSubmission(sub3);
    
    std::cout << problem1 << std::endl;
    problem1.DisplaySubmissions();
    
    std::cout << problem2 << std::endl;
    problem2.DisplaySubmissions();

    std::cout << problem3 << std::endl;
    problem3.DisplaySubmissions();
    
    sub1.runSubmission();
    sub3.runSubmission();
    
    return 0;
}
