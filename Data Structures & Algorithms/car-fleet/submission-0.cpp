class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        
        // 1. Bundle position and speed together for each car
        vector<pair<int, int>> cars(n); // {position, speed}
        for (int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        // 2. Sort descending: car closest to target comes first (cars[0])
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        // 3. Stack stores arrival times of fleet leaders
        stack<double> st;

        
        for (int i = 0; i < n; i++) {
            // Time = Distance / Speed
            double currenttime = (double)(target - cars[i].first) / cars[i].second;

            // If stack is empty: 1st car is always a fleet leader
            // If currenttime > st.top(): too slow to catch up -> starts a new fleet
            if (st.empty() || currenttime > st.top()) {
                st.push(currenttime);
            }
            // Note: If currenttime <= st.top(), car catches up and merges (no action needed)
        }

        // 4. Total leaders in stack = Total fleets formed
        return st.size();
    }
};