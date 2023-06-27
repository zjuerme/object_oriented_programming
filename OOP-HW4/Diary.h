#ifndef _DIARY_H_
#define _DIARY_H_

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

#define FILE_PATH "Diary.txt"

class Diary {
private:
    std::string date;
    std::vector<std::string> text;

public:
    Diary(const std::string& date);
    void reset();
    void addLine(const std::string& line);
    int getTextSize() const;
    std::string getTextLine(int lineIndex) const;
    std::string getDate() const;

    static std::vector<Diary> loadDiaryFromFile(const std::string& filePath = "Diary.txt");
    static void saveDiaryToFile(const std::vector<Diary>& diaryBook, const std::string& filePath = "Diary.txt");
    static void printUsage(const std::string& programName);
};

#endif