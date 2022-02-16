 //https://leetcode.com/problems/count-good-nodes-in-binary-tree/

 int ans=0;
    void preOrder(TreeNode* root, int mx){
        if(!root)return;
        if(root->val>=mx)mx=root->val,ans++;
        preOrder(root->left,mx);
        preOrder(root->right,mx);
    }
    int goodNodes(TreeNode* root) {
         ios_base::sync_with_stdio(0);
         cin.tie(0);
        
        preOrder(root,INT_MIN);return ans;
    }