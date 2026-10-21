#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addedge(vector<vector<int>>& adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u); // For undirected graph
}   

void printGraph(const vector<vector<int>>& adj)
{
    for (int i = 1; i < adj.size(); i++)
    {
        cout << "Vertex " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void BFS(const vector<vector<int>>& adj, int startNode,int v)
{
    vector<bool> visited(v+1,false);
    
    queue<int> q;
    
    //1. Initialize BFS from startNode
    visited[startNode] = true;
    q.push(startNode);

    cout<<"BFS Traversal from starting node: ";
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        cout<<curr<< " ";
        //explore all neighbors
        
        for(int i: adj[curr])
        {
            if(!visited[i])
            {
                visited[i] = true; // mark visited immediately on push
                q.push(i);
            }
        }
    }
    cout<<endl;

}

int main()
{
    int v = 6; // Number of vertices
    vector<vector<int>> adj(v+1); // Adjacency list representation of the graph

    addedge(adj, 1, 2);
    addedge(adj, 1, 3);
    addedge(adj, 2, 4);
    addedge(adj, 2, 5);
    addedge(adj, 3, 5);
    addedge(adj, 4, 5);
    addedge(adj, 4, 6);
    addedge(adj, 5, 6);
    printGraph(adj);

    BFS(adj,1,v);
    cout << flush;
    return 0;
}