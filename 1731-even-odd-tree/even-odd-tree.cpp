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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool evenlevel = true;
        while (!q.empty()) {
            int size = q.size();
            int prev=evenlevel ? INT_MIN : INT_MAX;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                int nodeval = front->val;
                if(evenlevel && (nodeval%2==0 || prev>=nodeval)) return false;
                if(!evenlevel && (nodeval%2!=0 || prev <= nodeval)) return false;
                prev = nodeval;
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            evenlevel = !evenlevel;
        }
        return true;
    }
};