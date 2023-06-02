class Solution {
    vector<vector<int>>g;
    int n;
    int dfs(vector<bool>&visited, int i){
        int count = 1;
        if(visited[i] == true) return 0;
        visited[i] = true;
        for(int j = 0; j < g[i].size(); j++){
            count += dfs(visited, g[i][j]);
        }
        return count;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();
        g = vector<vector<int>>(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i!=j){
                    unsigned long long x = abs(bombs[i][0]-bombs[j][0]), y = abs(bombs[i][1] - bombs[j][1]);
                    long long z = bombs[i][2];
                    if(x*x + y*y <= z*z) g[i].push_back(j);
                }
        int count = 0;
        for(int i = 0; i < n; i++){
            vector<bool>visited(n, false);
            count = max(count, dfs(visited, i));
        }
        return count;
    }
};