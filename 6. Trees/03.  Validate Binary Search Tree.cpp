 //https://leetcode.com/problems/validate-binary-search-tree/

time O(n)  O(n)space
 void inorder(TreeNode* root, vector<int>&v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1])return false;
        }
        return true;
    }

  timeO(n)  spaceO(1)

  TreeNode* pre=NULL;
    bool isValid(TreeNode* root){
        if(!root)return true;
        if(!isValid(root->left))return false;
        if(pre!=NULL && pre->val>=root->val)return false;
        pre=root;
        return isValid(root->right);
    }
    bool isValidBST(TreeNode* root) {
        return isValid(root);
        
    }