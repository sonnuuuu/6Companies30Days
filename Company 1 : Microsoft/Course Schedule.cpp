class Solution {
public:
    bool canFinish(int nodes, vector<vector<int>>& edges) 
    {
        vector<int> adj[nodes];
        int E = edges.size();
        for(int i=0; i<E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1]; 
            // u--->v
            adj[u].push_back(v);
        }

        int inDegree[nodes];
        memset(inDegree, 0, sizeof inDegree);
        for(int i=0; i<nodes; i++)
        {
            for(auto neighbour: adj[i])
            {
                inDegree[neighbour]++;
            }
        }

        queue<int> q; //will contain nodes
        for(int i=0; i<nodes; i++)
        {
            if(inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto neighbour: adj[node])
            {
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        for(auto node: inDegree)
        { 
            if(node != 0) return false;
        }
        return true;
    }
};
