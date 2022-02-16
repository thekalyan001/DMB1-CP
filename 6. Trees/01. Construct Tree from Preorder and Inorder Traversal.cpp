 //https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


  //store index so that we dont have to apply loop directly find the element index
    unordered_map<int,int>umap;  
    void findHashof(vector<int>&inorder){
        for(int i=0;i<inorder.size();i++){
            umap[inorder[i]]=i;
        }
        
    }
   
TreeNode* make_Tree(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int left, int right){
        if(left>right)return NULL;
    
    //using linear search 
      // int pivot = left;  // find the root from inorder
     // while(inorder[pivot] != preorder[rootIdx]) pivot++;
    
    //using map
     int pivot=umap[preorder[rootIdx]];

    
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = make_Tree(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = make_Tree(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndex=0;
        findHashof(inorder);
        return make_Tree(preorder,inorder,rootIndex,0,preorder.size()-1);
    }


    /* if only preorder given then take copy of pre and sort

    TreeNode* bstFromPreorder(vector<int>& pre) {
        vector<int>in(pre.begin(),pre.end());
        sort(in.begin(),in.end()); //inorder of any BST is sorted
        for(int i=0;i<in.size();i++){
            mp[in[i]]=i;
        }
        int rootIndex=0;
        return construct(pre,in,rootIndex,0,pre.size()-1);
    }

    */

