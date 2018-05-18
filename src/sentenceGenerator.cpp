#include "sentenceGenerator.h"
#include "macros.h"
#include <queue>

SentenceGenerator::SentenceGenerator(string key) : dict(WORDS_FILE) {
    loadNewKey(key);
}

void SentenceGenerator::loadNewKey(string const & key) {
    this->key = key;
}

void SentenceGenerator::generate() {
    int keyLength = key.size();
    int structsGenerated = 0;
    std::priority_queue<Path, vector<Path>, PathComparer> pq;
    for(int i = 1; i <= keyLength; ++i) {
        string sub = key.substr(0, i);
        if (dict.contains(sub))
            pq.push(Path(keyLength, sub));
    }
    while(!pq.empty()) {
        Path temp = pq.top();
        pq.pop();
        if (temp.curLength == keyLength) { //Found path
            ++structsGenerated;
            sentenceStructs.push_back(temp.path);
            if(structsGenerated == NUM_OF_SENTENCE_STRUCTS_TO_GEN)
                return;
        } 
        else {
            for (int i = 1; i <= keyLength - temp.curLength; ++i) {
                string sub = key.substr(temp.curLength, i);
                if (dict.contains(sub)) {
                    Path temp2 = temp;
                    temp2.add(sub);
                    pq.push(std::move(temp2));
                }
            }
        }
    }
}

void SentenceGenerator::printBestSentences() {
    string word;
    int curStruct = 0;
    char input = 'y';
    while(input == 'y' && curStruct < sentenceStructs.size()) {
        std::cout << std::endl;
        vector<string> &path = sentenceStructs[curStruct];
        for(string s : path) {
            vector<Word> const & wordList = dict.getWordList(s);
            for(int i = 0; i < wordList.size(); ++i) {
                word = wordList.at(i).getWord();
                std::cout << word << "   ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl << "Would you like to gen a new struct? y/n: ";
        std::cin >> input;
        ++curStruct;
    }
}