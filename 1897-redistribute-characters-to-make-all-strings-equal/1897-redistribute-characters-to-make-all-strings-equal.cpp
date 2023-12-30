class Solution {
public:
    bool makeEqual(vector<string>& words) {
        unordered_map<char, int>mp;
        int n = words.size();
        for(auto w:words){
            for(auto i:w){
                mp[i]++;
            }
        }
        
        for(auto i:mp){
            if(i.second%n != 0) return false;
        }
        
        return true;
        
    }
};