class Solution {
public:
    int maxScore(string s) {
        int sum0 = 0, maxi = 0;
        int n = s.size();
        int prefix[501] = {0};
        if(s[n-1] == '1') prefix[n-1] = 1;
        for(int i = n-2; i >=0; i--){
            if(s[i]=='1')
                prefix[i] = 1 + prefix[i+1];
            else 
                prefix[i] = prefix[i+1];
        }
        for(int i = 0; i < n-1; i++){
            if(s[i]=='0')
                ++sum0;
            maxi = max(maxi, sum0 + prefix[i+1]);
        }
        return maxi;
    }
};