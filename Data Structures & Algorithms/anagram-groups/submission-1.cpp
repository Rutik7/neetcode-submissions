class Solution {
    struct ArrayHash
    {
        // now let make it callable
        size_t operator()(const array<int,26>& arr) const
        {
            size_t hash = 0;
            //suppose arr [1,0,0,2,....]
            for(int x: arr)
            {
                hash  = hash * 31 + x;
            }

            return hash;

        }
    };
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map <array<int,26>,vector<string> , ArrayHash> umap;

        //
        for (auto s : strs)
        {
            array<int,26> key{};
            for(char ch : s)
            {
                key[ch - 'a']++;
            }

            umap[key].push_back(s);
        }

        for (auto it : umap)
        {
            result.push_back(it.second);
        }
        return result;
    }
};