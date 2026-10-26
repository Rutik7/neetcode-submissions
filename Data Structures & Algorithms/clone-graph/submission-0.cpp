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
    void dfs(Node* clone,Node* node, unordered_map<Node*,Node*>& visited)
    {
        

        // now cloning the neibhors
        for(Node* neighbor: node->neighbors)
        {
            //1. if neighbor is already visited then connect the existing clone
            if(visited.find(neighbor)!= visited.end())
            {
                clone->neighbors.push_back(visited[neighbor]);
            }
            else
            {
                //2 . if neighbor is not visited then create it, record it in visited, 
                // connect it 
                Node * newNeighbor = new Node(neighbor->val);
                clone->neighbors.push_back(newNeighbor);
                visited[neighbor] = newNeighbor;


                // recurse to connect NewNeibhor's edges

                dfs(newNeighbor,neighbor,visited);
            }

        }
    }
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;
        unordered_map<Node*, Node*> visited;
        Node* clone = new Node(node->val);
        visited[node] = clone;

        dfs(clone,node,visited);

        return clone;
    }
};