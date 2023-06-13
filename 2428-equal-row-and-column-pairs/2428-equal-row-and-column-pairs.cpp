class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int>m;
        for(int i = 0; i < n; i++){
            m[grid[i]]++;
        }
        int count = 0;
        for(int j = 0; j < n; j++){
            vector<int>v;
            for(int i = 0; i < n; i++){
                v.push_back(grid[i][j]);
            }
            count += m[v];
        }
        return count;
    }
};