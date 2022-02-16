//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

unordered_map<int,int>mp;
    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int &rootIndex, int left, int right){
        if(left>right)return NULL;
        int pivot=mp[postorder[rootIndex]];
        
        rootIndex--;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->right = construct(inorder,postorder, rootIndex, pivot+1, right);
        newNode->left = construct(inorder,postorder, rootIndex, left, pivot-1);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
               mp[inorder[i]]=i;
        }
        int rootIndex=postorder.size()-1;
        return construct(inorder,postorder,rootIndex,0,inorder.size()-1);
    }