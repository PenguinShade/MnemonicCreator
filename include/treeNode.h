#ifndef TREENODE_H
#define TREENODE_H

#include "word.h"
#include <vector>

using std::vector;

class TreeNode {
    friend class DeciTree;
    private:
        TreeNode *nodes[10];
        vector<Word> wordList;
    public:
        TreeNode();
};

#endif