#ifndef WORD_H
#define WORD_H

#include <string>
#include "mnemonicTable.h"

using std::string;

class Word {
private:
    string word;
    string mnemonic;
    static MnemonicTable mTable;
public:
    Word(string word = "");
    Word(const Word &word);
    Word(const Word && word); //Slightly untested
    void makeMnemonic();
    string const & getWord() const {return word;}
    string const & getMnemonic() const {return mnemonic;}
};

#endif