#include "treeNode.h"

TreeNode::TreeNode() {
    for(int i = 0; i < 10; ++i) {
        nodes[i] = nullptr;
    }
}