/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*, Node*> &visited)
    {
        // if node is already visited then simply return the visited node
        if(visited.find(node) != visited.end())
        {
            return visited[node];
        }

        // only for single node then
        // create the clone for the current node
        Node* clone = new Node(node->val);
        visited[node] = clone;

        // now attach the neibhors to the clone
        // Recursively call the neighbhors and attach to the clone
        for(Node* neighbor : node->neighbors)
        {
            Node* clonedNeighbor = dfs(neighbor,visited);
            clone->neighbors.push_back(clonedNeighbor);
        }
        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<Node*, Node*> visited;
        
        return dfs(node,visited);
    }
};