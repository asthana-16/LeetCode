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
    map<int,int>mp;
    int preidx =0;
    TreeNode* build(vector<int>& postorder, int start,int end){
        if(start>end) return NULL;
        int rootval = postorder[preidx--];
        TreeNode* root = new TreeNode(rootval);
        int mid=mp[rootval];
        root->right = build(postorder, mid+1, end);
        root->left = build(postorder,start,mid-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(n==0) return NULL;
        preidx=n-1;
        for(int i= 0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(postorder,0,n-1);
    }
};