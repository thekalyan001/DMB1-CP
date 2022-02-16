
//https://leetcode.com/discuss/general-discussion/1094690/views-and-traversal-of-binary-tree-important-topics-must-read


-----------------------------------=RightView=-----------------------------------------------------
Recursive

void rightview(TreeNode *root ,vector<int>&ans,int level,int &maxl){
  if(root==NULL)
    return ;
  if(maxl<level)
  {    
   ans.push_back(root->val);
   maxl=level;
 }
 rightview(root->right,ans,level+1,maxl);
 rightview(root->left,ans,level+1,maxl);
}
vector<int> rightSideView(TreeNode *root) {
  vector<int>ans;
  int maxl=0;
  rightview(root,ans,1,maxl);
  return ans;
}


Iterative

vector<int> rightSideView(TreeNode *root){
  vector<int>ans;
  if(!root)return ans;

  queue<pair<TreeNode*,int>>q; //bfs
  q.push({root,1});
  while(!q.empty()){

    TreeNode *curr=q.front().first;
    int level=q.front().second; 
    q.pop();

    if(ans.size()<level)
      ans.push_back(curr->data);

    if(curr->right)
      q.push({curr->right,level+1});
    if(curr->left)
      q.push({curr->left,level+1});
  }
  return ans;
}

-----------------------------------=LeftView=-----------------------------------------------------
Recursive


void leftview(TreeNode *root ,vector<int>&ans,int level,int &maxl){
  if(root==NULL)
    return ;
  if(maxl<level)
  {    
   ans.push_back(root->val);
   maxl=level;
 }
 lefttview(root->left,ans,level+1,maxl);
 leftview(root->right,ans,level+1,maxl);
}
vector<int> leftSideView(TreeNode *root) {
  vector<int>ans;
  int maxl=0;
  lefttview(root,ans,1,maxl);
  return ans;
}


Iterative

vector<int> LeftSideView(TreeNode *root){
  vector<int>ans;
  if(!root)return ans;

  queue<pair<TreeNode*,int>>q; //bfs
  q.push({root,1});
  while(!q.empty()){

    TreeNode *curr=q.front().first;
    int level=q.front().second; 
    q.pop();

    if(ans.size()<level)
      ans.push_back(curr->data);

    if(curr->left)
      q.push({curr->left,level+1});
    if(curr->right)
      q.push({curr->right,level+1});
  }
  return ans;
}

-----------------------------------=TopView=-----------------------------------------------------

vector<int> topView(Node *root)
{
  vector<int>ans;
  if(!root)return ans;

  queue<pair<Node*,int>>q;
  map<int,int>mp;
  q.push({root,0});


  int hd=0; 
  while(!q.empty()){
   hd=q.front().second;


          if(mp.count(hd)==0) //ek baar insert ho gya to nhi hoga same hd me nhi to duplicate aa jayega, comment this if to get bottom view
           mp[hd]=root->data;

         if(root->left) 
          q.push({root->left,hd-1});
        if(root->right)
          q.push({root->right, hd+1});

        q.pop();
        root=q.front().first;
        
      }


      for(auto i=mp.begin();i!=mp.end();i++) 
      { 
       ans.push_back(i->second); 
     } 
     return ans;
   }


  -------------------------------------------=BottomView=---------------------------------

vector <int> bottomView(Node *root) {
      vector<int>ans;
      if(!root)return ans;
       
       queue<pair<Node*,int>>q; //node distance
       map<int,int>mp;
       q.push({root,0});
       int hd=0; //horizontal dist
       
       while(!q.empty()){
           hd=q.front().second;
           
           mp[hd]=root->data; //override data last wala rahga after operation
           
           if(root->left) q.push({root->left,hd-1});
           if(root->right)q.push({root->right,hd+1});
           
           q.pop(); //khatam curr kaam
           root=q.front().first;
       }
       
       for(auto i=mp.begin();i!=mp.end();i++){
           ans.push_back(i->second);
       }
       return ans;
    }


  -------------------------------------------=VerticalOrder=---------------------------------

  same as bottom order map se horizontal dist lekr
 map<int, map<int, set<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first, y = p.second.second;
            nodes[x][y].insert(node -> val);
            if (node -> left) {
                todo.push({node -> left, {x - 1, y + 1}});
            }
            if (node -> right) {
                todo.push({node -> right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto p : nodes) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
    