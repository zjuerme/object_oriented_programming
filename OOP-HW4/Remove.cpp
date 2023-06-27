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
        diaryBook.erase(it);
        Diary::saveDiaryToFile(diaryBook);
        std::cout << "1" << std::endl;
    } else {
        std::cout << "0" << std::endl;
    }
    return 0;
}