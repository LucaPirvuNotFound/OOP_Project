/*
    Project: LeetCode Simulation
    
    Description:
    This program simulates a simplified version of an online coding platform like LeetCode.
    It defines three main classes:
    - Person: Represents a user who solves problems.
    - Problem: Represents a coding problem with a difficulty level and associated submissions.
    - Submission: Represents a user's submission, storing code lines and allowing execution.
    
    Input Data:
    - A predefined set of users (Person objects) with names and IDs.
    - A predefined set of problems (Problem objects) with unique IDs, difficulty levels, and descriptions.
    - Simulated submissions that track code solutions.
    
    Operations:
    - Create and manipulate objects of each class.
    - Simulate users solving problems and making submissions.
    - Store and display submission details.
    - Execute C++ code from submissions by writing to a file, compiling, and running it.
    
    Implemented Features:
    - Constructors with parameters for each class.
    - Copy constructor, copy assignment operator, and destructor for each class.
    - Operator << overload for formatted output.
    - Private attributes and const methods where applicable.
    - At least three non-trivial member functions, including problem-solving simulation.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

class Person {
private:
    std::string name;
    int userID;
public:
    Person(const std::string& name, int userID) : name(name), userID(userID) {}
    Person(const Person& other) : name(other.name), userID(other.userID) {}
    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            userID = other.userID;
        }
        return *this;
    }
    ~Person() {}
    
    friend std::ostream& operator<<(std::ostream& os, const Person& p) {
        os << "User: " << p.name << " (ID: " << p.userID << ")";
        return os;
    }
};

class Submission {
private:
    Person user;
    std::vector<std::string> code;
public:
    Submission(const Person& user, const std::vector<std::string>& code)
        : user(user), code(code) {}
    Submission(const Submission& other)
        : user(other.user), code(other.code) {}
    Submission& operator=(const Submission& other) {
        if (this != &other) {
            user = other.user;
            code = other.code;
        }
        return *this;
    }
    ~Submission() {}
    
    friend std::ostream& operator<<(std::ostream& os, const Submission& s) {
        os << s.user << " submitted code:\n";
        for (const auto& line : s.code) {
            os << line << "\n";
        }
        return os;
    }

    void run_submission() const {
        std::ofstream file("submission.cpp");
        
        for (const auto& line : code) {
            file << line << "\n";
        }
        file.close();

        std::cout << "Running the submission by " << user << ":" << std::endl;
        std::system("g++ submission.cpp -o submission");
        std::system(".\\submission.exe");
    }
};

class Problem {
private:
    int problemID;
    std::string difficulty;
    std::string description;
    std::vector<Submission> submissions;
public:
    Problem(int id, const std::string& difficulty, const std::string& description)
        : problemID(id), difficulty(difficulty), description(description) {}
    Problem(const Problem& other) 
        : problemID(other.problemID), difficulty(other.difficulty), description(other.description), submissions(other.submissions) {}
    Problem& operator=(const Problem& other) {
        if (this != &other) {
            problemID = other.problemID;
            difficulty = other.difficulty;
            description = other.description;
            submissions = other.submissions;
        }
        return *this;
    }
    ~Problem() {}
    
    void AddSubmission(const Submission& submission) {
        submissions.push_back(submission);
    }
    
    void DisplaySubmissions() const {
        std::cout << "Submissions for Problem " << problemID << ":\n";
        for (const auto& submission : submissions) {
            std::cout << submission << "\n";
        }
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Problem& p) {
        os << "Problem " << p.problemID << " (" << p.difficulty << "): " << p.description;
        return os;
    }
};

int main() {
    Person user1("Alice", 1);
    Person user2("Bob", 2);
    
    Problem problem1(101, "Easy", "Find the sum of two numbers.");
    Problem problem2(102, "Hard", "Implement a balanced binary search tree.");
    
    std::vector<std::string> code1 = {"#include <iostream>", "int main() {", "    std::cout << 2 + 2;", "    return 0;", "}"};
    std::vector<std::string> code2 = {"#include <iostream>", "int main() {", "    std::cout << 'Hello, world!';", "    return 0;", "}"};
    
    Submission sub1(user1, code1);
    Submission sub2(user2, code2);
    
    problem1.AddSubmission(sub1);
    problem2.AddSubmission(sub2);
    
    std::cout << problem1 << std::endl;
    problem1.DisplaySubmissions();
    
    std::cout << problem2 << std::endl;
    problem2.DisplaySubmissions();
    
    sub1.run_submission();
    
    return 0;
}
