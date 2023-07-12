802. Find Eventual Safe States
> Solution: using BFS & Topology Sort
>> 1. Create a reverse adjacency matrix of the graph.  
>> 2. Calculate each nodes' indegree for BFS & Topology Sort.  
>> 3. Find every terminal node and push it into bfs queue.  
>> 4. Do BFS method using the reverse adj. lists.
>> 5. When ever u want to push the adj. nodes into the queue, u should check if its indegree is 0.  
>> 6. If not then dont push it into the queue， because the node may not lead to the terminal node or exists a cycle.  
>> 7. After fingding all the safe node, sort them into ascending order and return.

> Timd comnplexity: O(V+E)
