#include "Diary.h"
Diary::Diary(const std::string& D) : date(D) {}
void Diary::addLine(const std::string& line) {
    text.push_back(line);
}
void Diary::reset() {
    text.clear();
}
std::string Diary::getDate() const {
    return date;
}
int Diary::getTextSize() const {
    return text.size();
}
std::string Diary::getTextLine(int lineIndex) const {
    return text[lineIndex];
}
std::vector<Diary> Diary::loadDiaryFromFile(const std::string& filePath) {
    std::cout << "Opening file: " << filePath << std::endl;
    std::ifstream fileIn(filePath);
    if (!fileIn) {
        std::cout << "File not found or cannot be opened. Creating a new diary book." << std::endl;
        return std::vector<Diary>();
    }
    std::string date, text;
    std::vector<Diary> diaryBook;
    while (!fileIn.eof()) {
        //std::cout << "Reading date from file..." << std::endl;
        std::getline(fileIn, date);
        if (date.empty()) continue;
        Diary diary(date);
        //std::cout << "Reading text from file..." << std::endl;
        std::getline(fileIn, text);
        while (text != ".") {
            diary.addLine(text);
            std::getline(fileIn, text);
        }
        diaryBook.push_back(diary);
    }
    fileIn.close();
    return diaryBook;
}
void Diary::saveDiaryToFile(const std::vector<Diary>& diaryBook, const std::string& filePath) {
    std::ofstream fileOut(filePath);
    for (const Diary& diary : diaryBook) {
        fileOut << diary.getDate() << std::endl;
        for (int j = 0; j < diary.getTextSize(); j++) {
            fileOut << diary.getTextLine(j) << std::endl;
        }
        fileOut << "." << std::endl;
    }
    fileOut.close();
}
void Diary::printUsage(const std::string& programName) {
    std::cerr << "Usage: " << programName << " <arguments>" << std::endl;
}