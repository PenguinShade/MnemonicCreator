#include "dictionary.h"

Dictionary::Dictionary(string filePath) {
    if(filePath != "")
        loadFile(filePath); 
}

void Dictionary::loadFile(const string &filePath) {
    std::ifstream file(filePath);
    string line;
    while(getline(file, line)) {
        add(line);
    }
}