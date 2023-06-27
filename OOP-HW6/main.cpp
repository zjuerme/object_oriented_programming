#include <iostream>
#include <string>
#include "Vector.h"

class Student {
    public:
        Student(const std::string& name = "", int score = 0)
            : name_(name), score_(score) {}

        friend std::ostream& operator<<(std::ostream& os, const Student& student) {
            os << "Student Name: " << student.name_ << ", Score: " << student.score_;
            return os;
        }
    private:
        std::string name_;
        int score_;
};

int main() {
    Vector<int> v1;
    int num;
    std::cout << "Enter the number of integers to add to vector v1:  ";
    std::cin >> num;
    for(int i = 0; i < num; i++) {
        std::cout << "Enter integer " << (i+1) << ": ";
        int value;
        std::cin >> value;
        v1.push_back(value);
    }
    std::cout << "Vector v1 contains: ";
    for(int i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";
    Vector<std::string> v2;
    std::cout << "\n ###################################################################### \n";
    std::cout << "Note that you cannot enter a string with spaces or line breaks!";
    std::cout << "\n ###################################################################### \n";
    std::cout << "Enter the number of strings to add to vector v2:  ";
    std::cin >> num;
    for(int i = 0; i < num; i++) {
        std::cout << "Enter string " << (i+1) << ": ";
        std::string value;
        std::cin >> value;
        v2.push_back(value);
    }
    std::cout << "Vector v2 contains: ";
    for(int i = 0; i < v2.size(); i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << "\n";
    int index;
    while (true) {
        std::cout << "Enter an index (0 to " << v1.size()-1 << ") to access v1: ";
        std::cin >> index;
        try {
            std::cout << "Element at index " << index << ": " << v1.at(index) << "\n";
            break;
        } catch (std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << ". Please enter a valid index.\n";
        }
    }
    while (true) {
        std::cout << "Enter an index (0 to " << v2.size()-1 << ") to access v2: ";
        std::cin >> index;
        try {
            std::cout << "Element at index " << index << ": " << v2.at(index) << "\n";
            break;
        } catch (std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << ". Please enter a valid index.\n";
        }
    }
    std::cout << "Is v1 empty? " << (v1.empty() ? "Yes" : "No") << "\n";
    std::cout << "Is v2 empty? " << (v2.empty() ? "Yes" : "No") << "\n";  
    std::cout << "Clearing v1 and v2...\n";
    v1.clear();
    v2.clear();
    std::cout << "Is v1 empty? " << (v1.empty() ? "Yes" : "No") << "\n";
    std::cout << "Is v2 empty? " << (v2.empty() ? "Yes" : "No") << "\n";
    // Hybrid test sample
    Vector<Student> v3;
    std::cout << "Enter the number of students to add to vector v3: ";
    std::cin >> num;
    for(int i = 0; i < num; i++) {
        std::string name;
        int score;
        std::cout << "Enter the name of student (String)" << (i+1) << ": ";
        std::cin >> name;
        std::cout << "Enter the score of student (Interge)" << (i+1) << ": ";
        std::cin >> score;
        v3.push_back(Student(name, score));
    }

    std::cout << "Vector v3 contains: ";
    for(int i = 0; i < v3.size(); i++) {
        std::cout << v3[i] << " ";
    }
    std::cout << "\n";
    while (true) {
        std::cout << "Enter an index (0 to " << v3.size()-1 << ") to access v3: ";
        std::cin >> index;
        try {
            std::cout << "Element at index " << index << ": " << v3.at(index) << "\n";
            break;
        } catch (std::out_of_range& e) {
            std::cout << "Caught exception: " << e.what() << ". Please enter a valid index.\n";
        }
    }
    return 0;
}