class Solution {
    vector<int>visited;
    int n;
    void DFS(int i, vector<vector<int>>& isConnected){
        visited[i] = 1;
        for(int j = 0; j < n; j++){
            if(isConnected[i][j]==1 and visited[j]==-1) 
                DFS(j, isConnected);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        visited = vector<int>(n, -1);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(visited[i] == -1){
                count++;
                DFS(i, isConnected);
            }
        }
        return count;
    }
};