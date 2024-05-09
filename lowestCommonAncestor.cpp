class Solution {
public:
    bool f(TreeNode* root,TreeNode* target, vector<TreeNode*>&ans){
        if(!root){
            return false;
        }
        ans.push_back(root);
        if(root==target){
            return true;
        }
        if(f(root->left,target,ans) || f(root->right,target,ans)) return true;
        ans.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>one;
        vector<TreeNode*>two;
        f(root,p,one);
        f(root,q,two);
        TreeNode* ans=NULL;
        for( int i =0;i<min(one.size(),two.size());i++){
            if(one[i]!=two[i]){
                return ans;
            }
            ans=one[i];
        }
        return ans;
    }
};
