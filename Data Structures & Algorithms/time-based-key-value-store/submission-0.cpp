class TimeMap {
public:
    map< string , vector<pair <string , int> > > mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {

        // return empty string if key doesn't exist
        if(mp.find(key) == mp.end()) return "";

        string value;
        const vector<pair<string,int>>& loc_value = mp[key];

        // now binary search ....
        // our search space will be?
        // our target is timestamp
        int start = 0;
        int end = loc_value.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if (timestamp >= loc_value[mid].second)
            {
                value = loc_value[mid].first;
                // try to find a larger valid timestamp
                start = mid + 1;
            }
            else
            {
                end = mid - 1; 
                // timestamp is too large , go left
            }
        }

        return value;

    }
};
