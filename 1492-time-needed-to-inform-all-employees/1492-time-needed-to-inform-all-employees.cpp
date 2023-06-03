class Solution {
    vector<vector<int>>treeChild;
    vector<int>manager;
    vector<int>informTime;

    int DFS(int headID){
        int maxTime = 0;

        for(int i = 0; i < treeChild[headID].size(); i++){
            maxTime = max(maxTime, informTime[headID] + DFS(treeChild[headID][i]));
        }

        return maxTime;
    }

public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        treeChild = vector<vector<int>>(n);
        this->manager = manager;
        this->informTime = informTime;
        for(int i = 0; i < n; i++)
            if(manager[i]!=-1) treeChild[manager[i]].push_back(i);
        return DFS(headID);
    }
};