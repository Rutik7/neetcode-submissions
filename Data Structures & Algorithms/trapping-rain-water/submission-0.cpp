class Solution {
   public:
    int trap(vector<int>& height) {
        // I will store the height of taller building from left and right

        int ans = 0;
        int n = height.size();
        vector<int> leftTaller(n);
        vector<int> rightTaller(n);

        leftTaller[0] = height[0];
        rightTaller[n - 1] = height[n - 1];

        //fill the leftTaller and right taller
        for (int i = 1; i < n; i++) 
        {
            leftTaller[i] = max(leftTaller[i - 1], height[i]);
            rightTaller[n - i - 1] = max(rightTaller[n - i], height[n - i - 1]);
        }

        // now do the calculation

        for (int i=0;i<n;i++)
        {
            ans += min(leftTaller[i],rightTaller[i]) - height[i];
        }

        return ans;
    }
};
