#ifndef SENTENCEGENERATOR_H
#define SENTENCEGENERATOR_H

#include "dictionary.h"

class SentenceGenerator {
    private:
        Dictionary dict;
        //The mnemonic number value
        string key;
        //Best path found in generator
        vector<vector<string> > sentenceStructs;
        /********************Classes********************/ 
        class Path {
            public:
                vector<string> path;
                int fullKeyLength;
                int minPathWeight;
                //how many key numbers have been covered in the path
                int curLength;
                //Functions
                Path(int fullKeyLength, string subKey) : curLength(0), minPathWeight(1) {
                    this->fullKeyLength = fullKeyLength;
                    add(subKey);
                    // minPathWeight = (curLength == fullKeyLength ? 0 : 1);
                }
                void add(string const & subKey) {
                    path.push_back(subKey);
                    curLength += subKey.size();
                    updateMinPathWeight();
                }
                int getMinPathWeight() const {return minPathWeight;}
            private:
                void updateMinPathWeight() {
                    if(curLength == fullKeyLength)
                        return;
                    ++minPathWeight;
                }
        };
        class PathComparer {
            public:
            bool operator()(Path const & lhs, Path const & rhs) {
                return lhs.getMinPathWeight() > rhs.getMinPathWeight();
            }
        };
    public:
        SentenceGenerator(string key = ""); 
        inline void loadNewKey(string const & key);
        void generate();
        void printBestSentences();
};

#endif