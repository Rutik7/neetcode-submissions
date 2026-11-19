class Solution {
public:
    int bfs(queue<pair<string,int>>& q, unordered_set<string>& dict , const string& endWord)
    {
        while(!q.empty())
        {
            // fetch the front node (current word and length)
            auto [word,steps] = q.front();
            q.pop();
            

            for(int i = 0 ;i<word.size();i++)
            {
                char orignalchar = word[i];
                for (int j = 0 ;j<26; j++)
                {
                    //fromat a next word by changing only one character
                    word[i] = 'a' + j;

                    // check the word in dict 
                    if(dict.find(word) != dict.end())
                    {
                        // check will we reach the end word
                        if(word == endWord)
                        {
                            return steps +1;
                        }
                        q.push({word,steps+1});
                        //erase the word from dict as visited
                        dict.erase(word);
                    }
                }

                // restore the orignal char 
                word[i] = orignalchar;
            }
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //ealrly check 
        unordered_set<string> dict(wordList.begin(),wordList.end());

        if(dict.find(endWord) == dict.end())
        {
            return 0; // no valid transformation sequence;
        }

        queue<pair<string,int>> q;
        int steps = 0;
        q.push({beginWord,steps+1});
        steps = bfs(q,dict,endWord);

        return steps;
        // now BFS

    }
};