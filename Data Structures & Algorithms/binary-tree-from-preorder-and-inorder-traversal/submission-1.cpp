class Solution {
public:

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int& preIdx, int left, int right,
                     unordered_map<int, int>& mp) {

        if (left > right)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = mp[preorder[preIdx]];
        preIdx++;

        root->left = helper(preorder, inorder, preIdx,
                            left, inIdx - 1, mp);

        root->right = helper(preorder, inorder, preIdx,
                             inIdx + 1, right, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        int preIdx = 0;

        return helper(preorder, inorder, preIdx,
                      0, inorder.size() - 1, mp);
    }
};