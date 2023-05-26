#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;
const int RecordsNum = 10;
const int CoursesNum = 3;
struct StudentRecord {
    string name;
    int scores[CoursesNum];
    float average;
}records[RecordsNum];
int maxScore[CoursesNum]; //to store the max score for a particular subject
int minScore[CoursesNum]; //to store the min score for a particular subject
// read the data in terminal
void read(){
    for (int i = 0; i < RecordsNum; i++) {
        cin >> records[i].name;
        for (int j = 0; j < CoursesNum; j++) {
            cin >> records[i].scores[j];
            records[i].average += records[i].scores[j];
        }
        records[i].average /= CoursesNum;
    }
}
// read the data by .csv
void read_csv(){
    ifstream inFile("hw1.csv", ios::in);
    if (!inFile)
        exit(1);
    int i = 0;
    for(int k=0;k< CoursesNum;k++){
        maxScore[k]=0;
        minScore[k]=6;
    }
    string line;
    string linenow;
    while (getline(inFile, line)){
        double sum = 0;
        string linenow;
        istringstream sin(line);
        getline(sin, linenow, ','); 
        records[i].name = linenow.c_str();
        for (int j = 0; j < CoursesNum-1; j++) {
            getline(sin, linenow, ','); 
            records[i].scores[j] = atoi(linenow.c_str()); 
            if(records[i].scores[j] > maxScore[j])
                maxScore[j]=records[i].scores[j];
            if(records[i].scores[j] < minScore[j])
                minScore[j]=records[i].scores[j];            
            sum += records[i].scores[j];
            //cout << records[i].scores[j] <<"%%%%"<< maxScore[j]<<endl;
        }
        getline(sin, linenow);  
        records[i].scores[CoursesNum-1] = atoi(linenow.c_str()); 
        sum+=records[i].scores[CoursesNum-1];
        if(records[i].scores[CoursesNum-1] > maxScore[CoursesNum-1])
            maxScore[CoursesNum-1]=records[i].scores[CoursesNum-1];
        if(records[i].scores[CoursesNum-1] < minScore[CoursesNum-1])
            minScore[CoursesNum-1]=records[i].scores[CoursesNum-1];
        records[i].average = sum/CoursesNum;
        i++;
    }
    inFile.close();
}

void print_list() {
    cout << "no\tname\tscore1\tscore2\tscore3\taverage\n";
    for (int i = 0; i < RecordsNum; i++) {
        cout << i + 1 << "\t" << setw(6) << left << records[i].name << "\t";
        for (int j = 0; j < CoursesNum; j++) {
            cout << setw(6) << left << records[i].scores[j] << "\t";
        }
        if(records[i].average -(int)records[i].average==0)  //for interger
            cout << setw(6) << fixed << (int)records[i].average << endl; 
        else  //for float
            cout << setw(6) << fixed << setprecision(5) << records[i].average << endl;     
    }
    cout <<"\taverage";
    for (int j = 0; j < CoursesNum; j++) {
        float sum = 0;
        for (int i = 0; i < RecordsNum; i++) {
            sum += records[i].scores[j];
        }
        cout << "\t" << fixed << setprecision(1) << sum / RecordsNum;
    }
    cout  << "\n\tmin";
    for (int j = 0; j < CoursesNum; j++)
        cout << "\t" << minScore[j];
    cout << "\n\tmax";
    for (int j = 0; j < CoursesNum; j++)
        cout << "\t" << maxScore[j];
    cout << endl;
}
// For the sake of convenience in testing, I have changed the method of reading the file to be from Excel. 
//If you want to switch back to reading from the console, please use the 'read_excel()' function instead of 'read()'
int main() {
    //read();
    read_csv();
    print_list();
    return 0;
}