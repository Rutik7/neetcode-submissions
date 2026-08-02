class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // binary search on 1st coloum
        int m = matrix.size();
        int n = matrix[0].size();
        int start = 0;
        int end = m - 1;

        while(start<=end)
        {
            int mid = start + (end - start)/2;
            
            if(matrix[mid][0] == target) return true;

            if(matrix[mid][0] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if(end < 0) return false;

        int row = end;
        start = 0;
        end = n - 1;

        while(start<=end)
        {
            int mid = start+ (end-start)/2;
            if(matrix[row][mid] == target) return true;

            if(matrix[row][mid] < target) 
            {
                start = mid + 1;
            }
            else
            {
                end = mid-1;
            }
        }

        return false;
    }
};
