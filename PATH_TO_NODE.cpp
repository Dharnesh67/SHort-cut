  bool f(TreeNode *root, vector<TreeNode*> &ans, TreeNode *target)
    {  /// get path to  node
        if(root==NULL){
            return false;
        }
        ans.push_back(root);
        if (root == target)
        {
            return true;
        }
        if ((root->left && f(root->left,ans,target) )||( root->right && f(root->right,ans,target) ))
        {
            return true;
        }
        ans.pop_back();
        return false;
    }

// make an vector ans and pass  into the function
