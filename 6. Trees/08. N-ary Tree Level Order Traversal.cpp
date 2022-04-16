https://leetcode.com/problems/n-ary-tree-level-order-traversal/

using BFS--

Time: O(N), where N <= 10^4
Extra Space (without counting output as space): O(N)

vector<vector<int>> levelOrder(Node* root) {
	if(root==NULL)return {};
	vector<vector<int>>ans;
	queue<Node*>q;
	q.push(root);

	while(q.empty()==false){
            ans.emplace_back(); //insert a new empty object(here array) using copy constructor
            
            for(int i=q.size();i>=1;i--){
            	Node* curr=q.front();
            	q.pop(); ans.back().push_back(curr->val);

            	for(Node* temp:curr->children){
            		q.push(temp);
            	}
            }
        }
        return ans;
        
    }




Using DFS--
time O(n)
space O(h)hight of tree, recursion stack, best case it is balanced tree logn height, worst case O(H) height as each level with 1 child

vector<vector<int>>ans;
    void dfs(Node* root,int level){
        if(root==NULL)return;
        if(level==ans.size()) //need one more level, insert empty array object using copy constructor
            ans.emplace_back();
        
        ans[level].push_back(root->val);

        for(Node* curr:root->children) //children is given in queestion, vector<Node*> children;
            dfs(curr, level+1);
        
    }
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root==NULL)return ans;
        dfs(root,0); //root,level
        return ans;
    }