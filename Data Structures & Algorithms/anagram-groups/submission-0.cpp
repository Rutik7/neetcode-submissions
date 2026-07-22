class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map <string,vector<string>> umap;

        //
        for (auto s : strs)
        {
            string key = s;
            sort(key.begin(),key.end());
            umap[key].push_back(s);
        }

        for (auto it : umap)
        {
            result.push_back(it.second);
        }
        return result;
    }
};