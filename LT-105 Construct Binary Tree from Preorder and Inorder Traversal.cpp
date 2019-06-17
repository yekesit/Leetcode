//
// Created by Ke Ye on 2019-06-16.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * */
class Solution {
public:
    vector<int> pre;
    unordered_map<int, int> pre_index;

    TreeNode* build(int& index, int left, int right){
        if(left == right) return nullptr;
        TreeNode* root = new TreeNode(pre[index]);
        int pivot = pre_index[pre[index]];
        index++;
        root->left = build(index, left, pivot);
        root->right = build(index, pivot + 1, right);
        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        for(int i = 0; i < inorder.size(); i++){
            pre_index[inorder[i]] = i;
        }
        int index = 0;
        return build(index, 0, pre.size());
    }
};

int main() {

}