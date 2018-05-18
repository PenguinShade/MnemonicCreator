#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include "deciTree.h"

class Dictionary : public DeciTree
{
    private:
    public:
        Dictionary(string filePath = "");
        void loadFile(const string &filePath);
};

#endif