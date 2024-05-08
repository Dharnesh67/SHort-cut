class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>>ans;
        while (!q.empty()) {
            int level = q.size();
            vector<int> v;
            while(level>0){
                auto x=q.front();
                q.pop();
                if(x->left) q.push(x->left);
                if(x->right) q.push(x->right);
                v.push_back(x->val);
                level--;
            }
            ans.push_back(v);
        }
        return ans;
    }
};
