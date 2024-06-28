#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};
class Solution
{
public:
    unordered_map<int,int>mp;
    void f(Node* root,int level){
        if(!root->left && !root->right){
            return;
        }
        mp[level]=root->data;
        f(root->left,level-1);
        f(root->right,level+1);
    }
    vector<int> bottomView(Node *root)
    {
        f(root,0);
        for(auto &x:mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    while (t--)
    {
    }
}