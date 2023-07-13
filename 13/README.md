# Leetcode-July-Challenge 7/13
# 207. Course Schedule
> Solution: BFS + Topology sort
>> 1. We can view the problem as making every course in a topology order.
>> 2. So we have to use topology sort to check if all the course can form a topology order or not.
> Approach: 
>> 1. Create a reverse adjacency lists of the course order graph.  
>> 2. Calculate each nodes' indegree for BFS & Topology Sort.  
>> 3. Find every terminal node and push it into bfs queue.  
>> 4. Do BFS method using the reverse adj. lists.
>> 5. When ever u want to push the adj. nodes into the queue, u should check if its indegree is 0.  
>> 6. If not then dont push it into the queue， because the node may not lead to the terminal node or exists a cycle.  
>> 7. After fingding all the possible node, check if {possible course} = {all courses} is true then return true, else return false.

> Time comnplexity: O(V+E)