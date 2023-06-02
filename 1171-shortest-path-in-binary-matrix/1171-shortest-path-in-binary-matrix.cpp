class Solution {
    vector<vector<int>>directions{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        if(n == 0 or grid[0][0] == 1) return -1;
        
        auto isSafe = [&](int x, int y){
            return x >= 0 and x < n and y >= 0 and y < n;
        };
        
        queue<pair<int, int>>q;
    
        q.push({0, 0});
        grid[0][0] = 1;
        
        int level = 1;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                
                int x = curr.first;
                int y = curr.second;
                
                if(x == n-1 and y == n-1) return level;
                
                for(auto dir:directions){
                    int i = x + dir[0];
                    int j = y + dir[1];
                    
                    if(isSafe(i, j) and grid[i][j] == 0) {
                        q.push({i, j});
                        grid[i][j] = 1;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};