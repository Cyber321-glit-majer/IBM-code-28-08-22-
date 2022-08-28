#include<bits/stdc++.h>
using namespace std;


int largestRegion(vector<vector<int>>& grid) {
  int m=grid.size();
  int n=grid[0].size();
  queue<pair<int,int>> q;
  int area=0;
  int ans=0;
  for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
   {
    if(grid[i][j]==1)
    {
     ans=0;
     q.push(make_pair(i,j));
     grid[i][j]=-1;
     while(!q.empty())
     {
      
      pair<int,int> t=q.front();
      q.pop();
      ans++;
      int x=t.first;
      int y=t.second;
      if(x+1<m){
       if(grid[x+1][y]==1)
       {
        q.push(make_pair(x+1,y));
        grid[x+1][y]=-1;
       }
      }
      if(x-1>=0){
       if(grid[x-1][y]==1)
       {
        q.push(make_pair(x-1,y));
        grid[x-1][y]=-1;
       }
      }
      if(y+1<n){
       if(grid[x][y+1]==1)
       {
        q.push(make_pair(x,y+1));
        grid[x][y+1]=-1;    
       }
       
      }
      if(y-1>=0){
       if(grid[x][y-1]==1)
       {
        q.push(make_pair(x,y-1));
        grid[x][y-1]=-1;
        
       }
      }
      if(x+1<m && y+1<n){
       if(grid[x+1][y+1]==1)
       {
        q.push(make_pair(x+1,y+1));
        grid[x+1][y+1]=-1;
       }
      }
     if(x-1>=0 && y+1<n){
       if(grid[x-1][y+1]==1)
       {
        q.push(make_pair(x-1,y+1));
        grid[x-1][y+1]=-1;
       }
      }
     if(x-1>=0 && y-1>=0) {
       if(grid[x-1][y-1]==1)
       {
        q.push(make_pair(x-1,y-1));
        grid[x-1][y-1]=-1;
       }
      }
     if(x+1<m && y-1>=0) {
       if(grid[x+1][y-1]==1)
       {
        q.push(make_pair(x+1,y-1));
        grid[x+1][y-1]=-1;
       }
      }
     }
     
     area=max(ans,area);
     ans=0;
     
    }
   }
  }
  return area;
  
}
int main(){
    
    int n,m;
    
    cin>>n>>m;
    
    vector<vector<int>> M( n , vector<int> (m, 0)); 
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            M[i][j] = x;
            
        }
    }

cout << largestRegion(M);
return 0;
}
