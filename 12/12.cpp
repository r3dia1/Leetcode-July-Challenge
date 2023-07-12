class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int nodeNum = graph.size();
        vector<vector<int>> reverse_adj(nodeNUm);
        vector<int> indegree(nodeNum, 0);
        for(int i=0; i<nodeNum; i++)
        {
            //reverse from it -> i to i -> it
            //Create a reverse direction adjacency list
            for(auto it: graph[i])
            {
                reverse_adj[it].push_back(i);
                indegree[i]++;
            }
        }

        //Find the terminal nodes
        queue<int> q; //queue for bfs
        vector<int> safe_nodes; //vector stored with safe node
        for(int i=0; i<nodeNum; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        //BFS & topology sort
        while(!q.empty())
        {
            int node = q.front();
            safe_nodes.push_back(node);
            //Delete the front node
            q.pop();
            //Then push the adj. node of front node into the queue.
            for(auto it: reverse_adj[node])
            {
                indegree[it]--;
                //if the inderee of the node is not 1, then there may exists a cycle.
                //Cause it wont lead to the current terminal node.
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        //Sort the safe node array into ascending order.
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};