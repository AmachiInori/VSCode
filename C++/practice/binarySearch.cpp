#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value = 0, TreeNode* l = nullptr, TreeNode* r = nullptr) : data(value), left(l), right(r) {}
};

class BST {
private:
    TreeNode* root;

    void clear(TreeNode* r);
    TreeNode* _find (TreeNode* r, int target) const;
    TreeNode* _insert(TreeNode* r, int value);
public:
    BST() { this->clear(root); }
    TreeNode* find (int target) const { return this->_find(root, target); }
    void insert(int data) { this->_insert(root, data); }
};

void BST::clear(TreeNode* r) {
    if (r != nullptr) {
        clear(r->left);
        clear(r->right);
        delete r;
    }
}

TreeNode* BST::_find(TreeNode* r, int target) const {
    if (r == nullptr)
        return nullptr;
    if (r->data > target)
        return _find(r->left, target);
    else if (r->data < target)
        return _find(r->right, target);
    else
        return r;
}

TreeNode* BST::_insert(TreeNode* r, int value) {
    if (r == nullptr) {
        r = new TreeNode(value);
    }else {
        if (value < r->data) r->left = _insert(r->left, value);
        else if (value > r->data) r->right = _insert(r->right, value);
    }
    return r;
}