#include "Diary.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        Diary::printUsage(argv[0]);
        return 1;
    }
    std::vector<Diary> diaryBook = Diary::loadDiaryFromFile();
    std::string date = argv[1];
    auto it = std::find_if(diaryBook.begin(), diaryBook.end(),
        [&date](const Diary& d) { return d.getDate() == date; });

    if (it != diaryBook.end()) {
        for (int j = 0; j < it->getTextSize(); j++) {
            std::cout << it->getTextLine(j) << std::endl;
        }
    } else {
        std::cerr << "No entry found for the specified date." << std::endl;
    }
    return 0;
}