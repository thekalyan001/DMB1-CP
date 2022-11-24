//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

TreeNode* check(TreeNode* root, TreeNode* &p, TreeNode* &q)
    {
        if(!root)return root; //if no root
        if(root->val==p->val || root->val==q->val)//anyValue is same then it starts from curr node
            return root;
        
        
        //call left and right
        TreeNode* lef=check(root->left,p,q);
        TreeNode* rig=check(root->right,p,q);
        
        //if both return true means both node is child of current node
        if(lef!=NULL && rig!=NULL)
            return root;
        
        
        //if any call is not null means  below current element there are both the nodes
        if(lef!=NULL || rig!=NULL)
            return lef?lef:rig;
        
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return  check(root,p,q);
        
    }

lca is first node where both the childs will meet
