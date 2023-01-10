 https://practice.geeksforgeeks.org/problems/d7e0ce338b11f0be36877d9c35cc8dfad6636957/1

 int transform(Node* root) {
        if(root == NULL)
            return 0;
    
        int left = transform(root->left);
        int right = transform(root->right);
        
        int temp = left+right+root->data;
        root->data = left+right;
        
        return temp;
    }
    
    void toSumTree(Node *node)
    {
        if(node == NULL)
            return;
            
        transform(node);
    }