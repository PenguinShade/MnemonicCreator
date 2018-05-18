#include "mnemonicTable.h"
#include <algorithm>
#include <fstream>
#include "macros.h"

/********************Private********************/
void MnemonicTable::loadDefaultTable() {
    loadInTable(MNEMONICTABLE_FILE);
}
void MnemonicTable::loadInTable(string filePath) {
    std::ifstream file(filePath);
    string line;
    for(int i = 0; i <= 9; ++i) {
        getline(file, line);
        for(int j = 2; line[j] != '\0'; ++j) {
            if(j%2 == 0)
                table[i].push_back(line[j]);
       } 
    }
}

/********************Public********************/
MnemonicTable::MnemonicTable() {
    loadDefaultTable();
}
//Num must be between 0-9
vector<char> const & MnemonicTable::getLettersFor(int num) {
    return table[num];
}
/*
Returns '\0' if no character is found
else returns a the numbers character
*/
int MnemonicTable::getNum(char letter) {
    for(int i = 0; i <= 9; ++i) {
        if(std::find(table[i].begin(), table[i].end(), letter) != table[i].end())
            return i;
    }
    return -1;
}