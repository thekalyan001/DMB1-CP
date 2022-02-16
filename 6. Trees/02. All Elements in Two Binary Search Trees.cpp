//https://leetcode.com/problems/all-elements-in-two-binary-search-trees
Naive m1-
inorder of both store in one array and sort
time O(n+m)+O(n+m)log(m+n) =>overall O(n+m)log(n+m)
space O(n+m)

void inorder(TreeNode *root,vector<int>&v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //M1 store and sort
        vector<int>v;
        inorder(root1,v);
        inorder(root2,v);
        sort(v.begin(),v.end());
        return v;
    }


M2-

Time- 2*O(n+m) inorder
space- 2*O(n+m)+o(logn); stack

store both traversal in two arrays and it will be converted to merge two sorted array

void inorder(TreeNode *root,vector<int>&v){
        if(!root)return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        //M1 store and sort
        vector<int>v1,v2;
        inorder(root1,v1);
        inorder(root2,v2);
        
        vector<int>v3;
       
        int n1=v1.size(),n2=v2.size(),i=0,j=0;
        while(i<n1 && j<n2){ //compare and push
           if(v1[i]<=v2[j]){
               v3.push_back(v1[i++]);
           }
            else if(v1[i]>v2[j])
                v3.push_back(v2[j++]);
        }
        while(i<n1) v3.push_back(v1[i++]); //if item left in first array
        while(j<n2) v3.push_back(v2[j++]); //item left in second array
        return v3;
    }


 time O(n+m)
 space O(n+m)
