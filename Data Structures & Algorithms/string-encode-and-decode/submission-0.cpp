class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for(const string &s : strs)
        {
            result += to_string(s.length()) + "#" + s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        while(i<s.length())
        {
            size_t pos = s.find('#',i);
            int len = stoi(s.substr(i,pos-i));
            i = pos+1;
            string word = s.substr(i,len);
            result.push_back(word);
            i+=len;
        }
        return result;
    }
};
