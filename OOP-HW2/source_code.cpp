//Based on the first assignment, I changed the code to a vector instead of an array to customize the lengthS
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;
#include <numeric> 
// const int RecordsNum = 10;
// const int CoursesNum = 3;
// int maxScore[CoursesNum]; 
// int minScore[CoursesNum]; 
vector<int> maxScore; //to store the max score for a particular subject
vector<int> minScore; //to store the min score for a particular 
void read();
void print_list();
struct StudentScore {
    string name;
    //int scores[CoursesNum];
    vector<int> scores; //using vector to store number of course scores
    float average = 0.0;  //average score for a student
};
vector<StudentScore> records;  //using vector to store number of student records

int main() {
    read();
    print_list();
    return 0;
}
void read() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    cin.ignore();
    while (true) {
        StudentScore record;
        cout << "Enter name and scores or Press Q to quit: ";
        string input;
        getline(cin, input);
        if (input == "q") break;
        istringstream iss(input);
        iss >> record.name;
        for (int j = 0; j < numCourses; j++) {
            string score_str;
            iss >> score_str;
            int score;
            if (score_str == "-") {
                score = 0;
            } else {
                score = stoi(score_str);
            }
            record.scores.push_back(score);
            if (records.empty()) {
                minScore.push_back(score); // Initializes the minimum score for each subject
                maxScore.push_back(score); // Initializes the maximum score for each subject
            } else {
                minScore[j] = min(minScore[j], score); // Update the minimum score for each subject
                maxScore[j] = max(maxScore[j], score); // Update the maximum score for each subject
            }
            record.average += score; // Sum the grade of a student
        }
        record.average /= numCourses; // Calculate the grade point average
        records.push_back(record); // Add student records
    }
}
void print_list() {
    int numCourses = records[0].scores.size();  // Get the number of subjects
    stringstream s;
    s << "No.\tName\t";
    for (int j = 0; j < numCourses; j++) {
        s << "Course " << j+1 << "\t";
    }
    s << "Average\n";
    for (int i = 0; i < records.size(); i++) {
        s << i + 1 << "\t" << setw(8) << left << records[i].name;
        for (int j = 0; j < numCourses; j++) {
            if (records[i].scores[j] == 0) {
                s << setw(8) << left << " " << "\t";
            } else {
                s << setw(8) << left << records[i].scores[j] << "\t";
            }
        }
        s << setw(8) << fixed << setprecision(5) << records[i].average << endl;
    }
    s << "\tAverage";
    for (int j = 0; j < numCourses; j++) {
        float sum = std::accumulate(records.begin(), records.end(), 0.0, [j](float s, const StudentScore& r){ return s + r.scores[j]; }); //An adder was used
        s << "\t" << setw(8) << fixed << setprecision(1) << sum / records.size();
    }
    s << "\n\tMin";
    for (int j = 0; j < numCourses; j++)
        s << "\t" << setw(8) << left << minScore[j];
    s << "\n\tMax";
    for (int j = 0; j < numCourses; j++)
        s << "\t" << setw(8) << left << maxScore[j];
    cout << s.str() << endl;
}