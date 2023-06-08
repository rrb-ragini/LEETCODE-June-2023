class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        int j = n-1;
            for(int i = 0; i < m; i++){
                while(j>= 0 and grid[i][j]<0){
                    count += m - i;
                    j--;
                }
        }
        return count;
    }
};