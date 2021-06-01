### topological sorting

#### [207Course Schedule](https://leetcode.com/problems/course-schedule/)

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

```java
// topological sorting
class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        //build graph and indegree
        ArrayList<Integer>[] graph = new ArrayList[numCourses];
        for(int i = 0; i < graph.length; ++i) {
            graph[i] = new ArrayList<Integer>();
        }
        int[] indegree = new int[numCourses];
        // pre[0] dependes on pre[1]
        for(int[] pre : prerequisites) {
            graph[pre[1]].add(pre[0]);
            indegree[pre[0]]++;
        }
        Queue<Integer> queue = new LinkedList<Integer>();
        for(int i = 0; i < numCourses; ++i) {
            if(indegree[i] == 0) {
                queue.add(i);
            }
        }
        List<Integer> courseOrder = new ArrayList<Integer>();
        while(queue.size() > 0) {
            int course = queue.poll();
            courseOrder.add(course);
            for(int nextCourse : graph[course]) {
                indegree[nextCourse]--;
                if(indegree[nextCourse] == 0) {
                    queue.add(nextCourse);
                }
            }
        }
        if(courseOrder.size() == numCourses) {  
            return true;
        } else {
            return false;
        }
    }
}
// dfs 
class Solution {
    ArrayList<Integer>[] graph;
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        //build graph and indegree
        graph = new ArrayList[numCourses];
        for(int i = 0; i < graph.length; ++i) {
            graph[i] = new ArrayList<Integer>();
        }
        // pre[0] dependes on pre[1]
        for(int[] pre : prerequisites) {
            graph[pre[1]].add(pre[0]);
        }
        int[] path = new int[numCourses];
        int[] visited = new int[numCourses];
        for(int i = 0; i < numCourses; ++i) {
            if(checkIfCircleExsit(i,path, visited)) {
                return false;
            }
        }
        return true;
    }
    
    public boolean checkIfCircleExsit(int course, int[] path, int[] visited) {
        if(visited[course] == 1) {
            return false;
        }
        // counter the same course
        if(path[course] == 1) {
            return true;
        }
        path[course] = 1;
        for(int nextCourse: graph[course]) {
            if(checkIfCircleExsit(nextCourse, path, visited)) {
                return true;
            }
        }
        path[course] = 0;
        visited[course] = 1;
        return false;
    }
}
```

##### note:

course 2 is acutlly the same question. The only difference will be returnning the topological order

We can also use DFS to solve this problem. The idea is to check whether it contains a circle or not.