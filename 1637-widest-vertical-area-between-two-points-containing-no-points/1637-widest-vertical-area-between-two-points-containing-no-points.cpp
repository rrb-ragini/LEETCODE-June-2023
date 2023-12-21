class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        
        int wva = points[1][0] - points[0][0]; 
        
        for(int i = 2; i < points.size(); i++){
            wva = max(wva, points[i][0] - points[i-1][0]);
        }
        return wva;
    }
};