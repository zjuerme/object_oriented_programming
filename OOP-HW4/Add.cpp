#include "Diary.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        Diary::printUsage(argv[0]);
        return 1;
    }
    std::string fileName = argv[1];
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening the input file: " << fileName << std::endl;
        return 1;
    }
    std::string date;
    std::getline(inputFile, date);
    std::vector<Diary> diaryBook = Diary::loadDiaryFromFile();
    Diary diary(date);
    //std::cout << "Input your diary here:" << std::endl;
    std::string text;
    while (std::getline(inputFile, text) && text != ".") {
        diary.addLine(text);
    }
    inputFile.close();
    auto it = std::lower_bound(diaryBook.begin(), diaryBook.end(), diary,
        [](const Diary& a, const Diary& b) { return a.getDate() < b.getDate(); });

    if (it != diaryBook.end() && it->getDate() == diary.getDate()) {
        *it = diary;
    } else {
        diaryBook.insert(it, diary);
    }
    Diary::saveDiaryToFile(diaryBook);
    return 0;
}
