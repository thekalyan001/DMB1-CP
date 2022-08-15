https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1
https://leetcode.com/problems/rotting-oranges/


int orangesRotting(vector<vector<int>>& grid) { //O(m*n)
    
        queue<pair<pair<int,int>, int>>q; //i, j, time
        int dx[4]={0, 0, -1, 1};
        int dy[4]={-1, 1, 0, 0};
        
        int r=grid.size(), c=grid[0].size();
        int vis[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vis[i][j]=0;
            }
        }
        
        //add indexes to the queue and mark as visited, as elements are already rotten
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2)
                {
                    q.push({{i, j}, 0}); vis[i][j]=1;
                }
            }
        }
        
        int timeU=0;
        while(!q.empty()){
            auto temp=q.front();
            int x=temp.first.first;
            int y=temp.first.second;
            int time=temp.second;
            
            for(int i=0;i<4;i++){ //check all 4 direction
                int xi=x+dx[i], yi=y+dy[i];
                
                if(xi>=0 && xi<r && yi>=0 && yi<c && vis[xi][yi]==0){ //if valid index &  not visited
                    if(grid[xi][yi]==1){ //if orange left
                        grid[xi][yi]=2;
                        timeU=time+1;
                        vis[xi][yi]=1;
                        q.push({{xi, yi}, time+1});
                    }
                    else
                     vis[xi][yi]=1;
                }
            }
            q.pop();
        }
        
      //if any orange left then -1
      bool flag=true;
      for(int i=0;i<r;i++){
          for(int j=0;j<c;j++){
              if(grid[i][j]==1){
                  return -1;
                  //cout<<"-1";flag=1;break;
              }
          }
      }
        if(flag)
        return timeU;
        
    }