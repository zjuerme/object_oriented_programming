#include "Diary.h"

int main(int argc, char* argv[]) {
    if (argc != 1 && argc != 3) {
        Diary::printUsage(argv[0]);
        return 1;
    }
    std::vector<Diary> diaryBook = Diary::loadDiaryFromFile();
    std::string beginDt, endDt;
    if (argc == 3) {
        beginDt = argv[1];
        endDt = argv[2];
    }
    for (const Diary& diary :diaryBook) { 
        if (argc == 1 || (diary.getDate() >= beginDt && diary.getDate() <= endDt)) { 
            std::cout << diary.getDate() << std::endl; std::cout << diary.getTextLine(0) << std::endl; 
        } 
    }
    return 0;
}