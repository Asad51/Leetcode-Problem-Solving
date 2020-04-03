class Solution
{
    bool visited[100000];
    vector<int> adj[100000];

public:
    void dfs(int s)
    {
        visited[s] = true;
        for (int i = 0; i < adj[s].size(); ++i)
        {
            if (visited[adj[s][i]] == false)
                dfs(adj[s][i]);
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int connectedComponents = 0, cnt = 0;
        for (int i = 0; i < n; i++)
            visited[i] = false;

        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            cnt++;
        }

        if (cnt < n - 1)
            return -1;

        for (int i = 0; i < n; ++i)
        {
            if (visited[i] == false)
            {
                dfs(i);
                connectedComponents++;
            }
        }

        return connectedComponents - 1;
    }
};
