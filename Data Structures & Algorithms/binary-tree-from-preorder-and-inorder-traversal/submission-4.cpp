/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* build(vector<int>& pre,int preL,int preR,int inL,int inR,unordered_map<int,int>&inIndex){
        if(preL>preR || inL>inR) return NULL;
        int rootVal=pre[preL];
        TreeNode* root=new TreeNode(rootVal);
        int inRootIndex=inIndex.at(root->val);
        int leftSize=inRootIndex-inL;
        root->left=build(pre,preL+1,preL+leftSize,inL,inRootIndex,inIndex);
        root->right=build(pre,preL+leftSize+1,preR,inRootIndex+1,inR,inIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        if(n==0) return 0;
        unordered_map<int,int>inIndex;
        inIndex.reserve(n*2);
        for(int i=0;i<n;i++){
            inIndex[inorder[i]]=i;
        }
        return build(preorder,0,n-1,0,n-1,inIndex);
    }
};
