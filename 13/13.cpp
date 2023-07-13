class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> rev_adj[numCourses];
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++)
        {
            rev_adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indegree[prerequisites[i][1]]++;
        }

        queue<int> q;
        vector<int> check;
        for(int i=0; i<numCourses; i++)
        {
            if(indegree[i] == 0)
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();

            check.push_back(node);
            q.pop();

            for(auto it: rev_adj[node])
            {
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        if(check.size() == numCourses)
            return true;
        else
            return false;
    }
};