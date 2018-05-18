#ifndef MNEMONICTABLE_H
#define MNEMONICTABLE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class MnemonicTable {
    private:
        /*
        index jumps to the vector containing all of that nums letters associated
        Cannot contain duplicate letters
        */
        vector<char> table[10];

        //Functions
        void loadDefaultTable();
        void loadInTable(string filePath);

    public:
        MnemonicTable();
        vector<char> const & getLettersFor(int num);
        int getNum(char letter);
};

#endif