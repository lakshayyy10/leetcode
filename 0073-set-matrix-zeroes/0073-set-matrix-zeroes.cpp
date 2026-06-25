class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        unordered_set<int>rows;
        unordered_set<int>cols;
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(mat[r][c]==0){
                    rows.insert(r);
                    cols.insert(c);
                }
            }
        }
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(rows.count(r)||cols.count(c)){
                    mat[r][c]=0;
                }
            }
        }
    }
};