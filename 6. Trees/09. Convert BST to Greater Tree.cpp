https://leetcode.com/problems/convert-bst-to-greater-tree/

convert bst such that  BST is changed to the original key plus the sum 
of all keys greater than the original key in BST.

TreeNode* convertBST(TreeNode* root) {
        if(root!=NULL){
            convertBST(root->right);
            sum+=root->val;
            root->val=sum;
            convertBST(root->left);
        }
        return root;
    }