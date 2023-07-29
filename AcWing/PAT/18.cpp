/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Ã‚‘¥: leetcode Ω£÷∏offer

class Solution {
public:
    unordered_map<int,int> pre_in_mid,l_son,r_son;
    vector<int> pre,ino;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()) return NULL;
        pre = preorder;
        ino = inorder;
        for(int i=0;i<ino.size();i++){
            pre_in_mid[ino[i]] = i;
        }
        int root = pre[0];
        return build(0,pre.size()-1,0,pre.size()-1);
    }
    
    TreeNode* build(int pl,int pr,int il,int ir){
        int r = pre[pl];
        int k = pre_in_mid[r];
        TreeNode* root = new TreeNode(r);
        if(il<k){
            root->left = build(pl+1,pl+k-il,il,k-1);
            l_son[k] = root->left->val;
        }
        if(ir>k){
            root->right = build(pl+k-il+1,pr,k+1,ir);
            r_son[k] = root->right->val;
        }
        return root;
    }
};
