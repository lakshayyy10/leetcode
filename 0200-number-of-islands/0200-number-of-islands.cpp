class Solution {
public:
vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
void dfs(vector<vector<char>>&grid , int r , int c){
    int row = grid.size();
    int col = grid[0].size();
    if(r<0 || c<0 || r>=row || c>=col || grid[r][c]=='0') return;
    grid[r][c]='0';
    for(auto &dir : directions){
        dfs(grid, r+dir[0], c+dir[1]);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int result=0;
        int row = grid.size();
        int col = grid[0].size();
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(grid[r][c]=='1'){
                    result++;
                    dfs(grid,r,c);
                }
            }
        }
        return result;
    }
};