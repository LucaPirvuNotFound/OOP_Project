#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

class Person {
    private:
        std::string m_name;
        int m_userID;
    public:
        Person(const std::string& m_name, int m_userID) : m_name(m_name), m_userID(m_userID) {}
        Person(const Person& other) : m_name(other.m_name), m_userID(other.m_userID) {}
        Person& operator=(const Person& other) {
            if (this != &other) {
                m_name = other.m_name;
                m_userID = other.m_userID;
            }
            return *this;
        }
        ~Person() {}
        
        friend std::ostream& operator<<(std::ostream& os, const Person& p) {
            os << "User: " << p.m_name << " (ID: " << p.m_userID << ")";
            return os;
        }
    };
    
    class Submission {
    private:
        Person m_user;
        std::vector<std::string> m_code;
    public:
        Submission(const Person& m_user, const std::vector<std::string>& m_code)
            : m_user(m_user), m_code(m_code) {}
        Submission(const Submission& other)
            : m_user(other.m_user), m_code(other.m_code) {}
        Submission& operator=(const Submission& other) {
            if (this != &other) {
                m_user = other.m_user;
                m_code = other.m_code;
            }
            return *this;
        }
        ~Submission() {}
        
        friend std::ostream& operator<<(std::ostream& os, const Submission& s) {
            os << s.m_user << " submitted m_code:\n";
            for (const auto& line : s.m_code) {
                os << line << "\n";
            }
            return os;
        }
    
        void runSubmission() const; 
    };
    
    class Problem {
    private:
        int m_problemID;
        std::string m_difficulty;
        std::string m_description;
        std::vector<Submission> m_submissions;
    public:
        Problem(int id, const std::string& m_difficulty, const std::string& m_description)
            : m_problemID(id), m_difficulty(m_difficulty), m_description(m_description) {}
        Problem(const Problem& other) 
            : m_problemID(other.m_problemID), m_difficulty(other.m_difficulty), m_description(other.m_description), m_submissions(other.m_submissions) {}
        Problem& operator=(const Problem& other) {
            if (this != &other) {
                m_problemID = other.m_problemID;
                m_difficulty = other.m_difficulty;
                m_description = other.m_description;
                m_submissions = other.m_submissions;
            }
            return *this;
        }
        ~Problem() {}
        
        void AddSubmission(const Submission& submission);
        
        void DisplaySubmissions() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Problem& p) {
            os << "Problem " << p.m_problemID << " (" << p.m_difficulty << "): " << p.m_description;
            return os;
        }
    };