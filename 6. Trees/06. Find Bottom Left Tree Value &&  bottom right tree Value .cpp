//https://leetcode.com/problems/find-bottom-left-tree-value/

//using dfs both approach
    //left order view me last wala element is the answer
    

  //using bfs level order  time O(n)  space O(logn)
    int findBottomLeftValue(TreeNode* root) {
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        
        while(!q.empty()){
            TreeNode* temp=q.front().first;
            int level=q.front().second;q.pop();
            
            if(ans.size()<level)
                ans.push_back(temp->val);
            
            if(temp->left)
                q.push({temp->left,level+1});
            if(temp->right)
                q.push({temp->right,level+1});
        }
        return ans[ans.size()-1];
    }
    
    
    //using dfs time O(n) space O(1)
     int findBottomLeftValue(TreeNode* root) {
       if(!root)return 0;
        queue<TreeNode*>q;
         q.push(root);
         
         while(!q.empty()){
             root=q.front();
             q.pop();
             
             if(root->right)q.push(root->right);
             if(root->left)q.push(root->left);
         }
         
         return root->val;
    }



------------------------------------------------------Bottom right tree value me--------------
//using dfs time O(n) space O(1)
int findBottomRightValue(TreeNode* root) {
       if(!root)return 0;
        queue<TreeNode*>q;
         q.push(root);
         
         while(!q.empty()){
             root=q.front();
             q.pop();
             
             if(root->left)q.push(root->left);
             if(root->right)q.push(root->right);
             
         }
         
         return root->val;
}