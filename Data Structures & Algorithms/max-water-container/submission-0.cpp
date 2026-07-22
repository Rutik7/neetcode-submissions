class Solution {
public:
    int maxArea(vector<int>& heights) {
        int answer = INT_MIN;

        int n = heights.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int currwater = (j-i) * min(heights[i],heights[j]);

                answer = max(currwater,answer);
            }
        }

        return answer;
    }
};
