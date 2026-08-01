class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int minHeight = heights[i];
            for(int j = i;j<n;j++)
            {
                minHeight = min(minHeight, heights[j]);
                int width = j-i+1;

                ans = max(ans,minHeight*width);

            }
        }

        return ans;
    }
};
