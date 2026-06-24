class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>>&grid,int r,int c){
        int row=grid.size();
        int col = grid[0].size();
        if(r<0 || c<0 || r>=row || c>=col || grid[r][c]==0) return 0;
        int area=1;
        grid[r][c]=0;
        for(auto dir : directions){
            area+=dfs(grid,r+dir[0],c+dir[1]);
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        int ans=0;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]==1){
                    int area=dfs(grid,r,c);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
};