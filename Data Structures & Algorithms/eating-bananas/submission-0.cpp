class Solution {
public:
    bool helper(const vector<int>& piles, int h, int k)
    {
        int totalhours = 0;
        for(int i: piles)
        {
            totalhours += (i+k-1)/k;
        }

        return totalhours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans;
        int maxspeed = piles[0];
        int minspeed = 1;
        // If Koko eats at the size of the largest pile,
        // she can finish every pile in at most one hour.
        for(int i = 1;i<n;i++)
        {
            maxspeed = max(maxspeed,piles[i]);
        }


        // Binary search on the answer:
        // speed lies between 1 and maxspeed.
        while(minspeed <= maxspeed)
        {
            int mid = minspeed + (maxspeed-minspeed)/2;

            if(helper(piles,h,mid))
            {
                ans = mid;
                maxspeed = mid - 1;
                // check for minimum hours
            }
            else
            {
                minspeed = mid + 1;
                // increasing the speed by adding search space
            }
        }

        
        return ans;
    }
};
