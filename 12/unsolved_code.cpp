class Solution {
public:
    unordered_map<int, int> count;
    
    bool findSafe_bfs(vector<vector<int>>& graph, int curn)
    {
        vector<int> travel;
        travel.push_back(curn);

        while(travel.size() != 0)
        {
            for(int i=0; i<graph[travel[0]].size(); i++)
            {
                travel.push_back(graph[travel[0]][i]);
                count[graph[travel[0]][i]]++;
                if(count[graph[travel[0]][i]] > 1 && graph[travel[0]].size()!= 0)
                    return false;
            }
            travel.erase(travel.begin());
        }

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ret;

        for(int i=0; i<graph.size(); i++)
        {
            count.clear();

            if(findSafe_bfs(graph, i) == true)
            {
                ret.push_back(i);
            }
        }

        sort(ret.begin(), ret.end());
        return ret;
    }
};