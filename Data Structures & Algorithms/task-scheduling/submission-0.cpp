class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> ump;
        for(const auto& ch: tasks)
        {
            ump[ch]++;
        }
        // now feed the max_heap

        priority_queue<pair<int,char>> max_heap;
        for(const auto& a: ump)
        {
            max_heap.push({a.second,a.first});
        }

        int time = 0;
        // now the simulation part
        // once I execute highest priority queue I need to push it into cooldown queue
        queue<pair<int,pair<int,char>>> cooldown;
        // storing {readyTime,{remaingcount,letter}}

        while(!max_heap.empty() || !cooldown.empty())
        {
            // release queue task if possible
            time++;
            if(!cooldown.empty())
            {
                auto front = cooldown.front();
                if(time == front.first)
                {
                    max_heap.push(front.second);
                    cooldown.pop();
                }
            }

            // now execute from the max_heap
            if(!max_heap.empty())
            {
                auto top = max_heap.top();
                max_heap.pop();

                top.first--;
                if(top.first > 0)
                {
                    // push into cooldown
                    cooldown.push({time+n+1,top});
                }
            }
        }

        return time;

    }
};