#include "deciTree.h"
#include <iostream>


/********************Private********************/
void DeciTree::deleteAllNodes(TreeNode * cur) {
    for(int i = 0; i < 10; ++i) {
        if(cur->nodes[i] != nullptr) {
            deleteAllNodes(cur->nodes[i]);
            delete cur->nodes[i];
        }
    }
}

/********************Public********************/
DeciTree::DeciTree() {
    root = new TreeNode();
}

DeciTree::~DeciTree() {
    deleteAllNodes(root);    
}

void DeciTree::add(Word const & word) {
    string const &key = word.getMnemonic();
    TreeNode * cur = root;
    for(int i = 0; i < key.size(); ++i) {
        if(cur->nodes[(int)(key[i] - '0')] == nullptr)
            cur->nodes[(int)(key[i] - '0')] = new TreeNode();
        cur = cur->nodes[(int)(key[i] - '0')]; 
    }
    if(cur != root)
        cur->wordList.push_back(word);
}

vector<Word> const & DeciTree::getWordList(string const &key) {
    TreeNode * cur = root;
    for(int i = 0; i < key.size(); ++i) {
        cur = cur->nodes[(int)(key[i] - '0')];
        if(cur == nullptr)
            return root->wordList; //If accesing invalid node return empty list
    }
    return cur->wordList;
}

bool DeciTree::contains(string const &key) {
    return !getWordList(key).empty();
}