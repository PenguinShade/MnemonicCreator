#ifndef DECITREE_H
#define DECITREE_H

#include "treeNode.h"

class DeciTree {
    private:
        //Memebers
        TreeNode * root;
        //Functions
        void deleteAllNodes(TreeNode * cur);
    public:
        DeciTree();
        ~DeciTree();
        void add(Word const & word);
        vector<Word> const & getWordList(string const &key);
        bool contains(string const &key);
};

#endif