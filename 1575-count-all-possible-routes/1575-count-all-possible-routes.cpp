class Solution {
    int mod = 1e9+7;
    vector<int>location;
    int n;
    int dp[101][201];
    int solve(int start, int finish, int fuel){
        if(fuel < 0) return 0;
        if(dp[start][fuel]!=-1) return dp[start][fuel];
        int ans  = 0;
        if(start == finish) ans+= 1;
        
        for(int i = 0; i < n; i++){
            if(i !=start and fuel >= abs(location[i]-location[start])) ans=(ans + solve(i, finish, fuel-abs(location[i]-location[start]))%mod)%mod;
        }
        return dp[start][fuel] = ans;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        location = locations;
        n = locations.size();
        memset(dp, -1, sizeof(dp));
        int count = solve(start, finish, fuel);
        return count;
    }
};