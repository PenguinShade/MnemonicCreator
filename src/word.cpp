#include "word.h"
#include <iostream>

MnemonicTable Word::mTable;

Word::Word(std::string word) {
    if(word != "") {
        this->word = word;
        makeMnemonic();
    }
}
Word::Word(const Word &word) {
    this->word = word.word;
    makeMnemonic();
}
Word::Word(const Word && word) {
    this->word = std::move(word.word);
    this->mnemonic = std::move(word.mnemonic);
}

void Word::makeMnemonic() {
    int num = -1;
    for(char c : word) {
        num = mTable.getNum(c);
        if(num != -1)
            mnemonic.push_back((char)(num + '0'));
    }
}
