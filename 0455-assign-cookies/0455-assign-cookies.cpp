class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
                
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int n1 = g.size();
        int n2 = s.size();
        int count = 0;
        int i = 0, j = 0;
        for(; i < n1 and j < n2;){
            if(g[i] > s[j]) ++j;
            else if(g[i] <= s[j]) {++i; ++j; ++count;}
        }
        
        return count;
        
    }
};