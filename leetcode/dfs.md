## 基本问题：

（1）DFS中递归的基本要素
（2）终止条件的选择；回溯；剪枝
（3）什么时候需要排序？
（4）如何去除重复元素？一个元素允许使用多次的情况？
（6）在图上进行DFS如何避免回到重复节点
（5）识别一个隐式图，并使用DFS
（6）在某些情况下，利用记忆化搜索进行优化



## **排列组合**：

39. Combination Sum
https://leetcode.com/problems/combination-sum/

40. Combination Sum II
https://leetcode.com/problems/combination-sum-ii/

46. Permutations
https://leetcode.com/problems/permutations/

47. Permutations II
https://leetcode.com/problems/permutations-ii/

77. Combinations
https://leetcode.com/problems/combinations/

78. Subsets
https://leetcode.com/problems/subsets/

90. Subsets II
https://leetcode.com/problems/subsets-ii/

17. Letter Combinations of a Phone Number
https://leetcode.com/problems/le ... -of-a-phone-number/

22. Generate Parentheses
https://leetcode.com/problems/generate-parentheses/

51. N-Queens
https://leetcode.com/problems/n-queens/

254. Factor Combinations
https://leetcode.com/problems/factor-combinations/

301. Remove Invalid Parentheses
https://leetcode.com/problems/remove-invalid-parentheses/

491. Increasing Subsequences
https://leetcode.com/problems/increasing-subsequences/

37. Sudoku Solver
https://leetcode.com/problems/sudoku-solver/

52. N-Queens II
https://leetcode.com/problems/n-queens-ii/

93. Restore IP Addresses
https://leetcode.com/problems/restore-ip-addresses/

131. Palindrome Partitioning
https://leetcode.com/problems/palindrome-partitioning/

Lint-10. String Permutation II
https://www.lintcode.com/problem ... tion-ii/description

Lint-570. Find the Missing Number II
https://www.lintcode.com/problem ... mber-ii/description

Lint-680. Split String
https://www.lintcode.com/problem/split-string/description

## 二叉树：

113. Path Sum II
https://leetcode.com/problems/path-sum-ii/

257. Binary Tree Paths
https://leetcode.com/problems/binary-tree-paths/

Lint-246. Binary Tree Path Sum II
https://www.lintcode.com/problem/binary-tree-path-sum-ii/solution

Lint-376. Binary Tree Path Sum
https://www.lintcode.com/problem/binary-tree-path-sum/solution

Lint-472. Binary Tree Path Sum III
https://www.lintcode.com/problem ... sum-iii/description

## 图：

140. Word Break II
https://leetcode.com/problems/word-break-ii/
494. Target Sum
https://leetcode.com/problems/target-sum/
1192. Critical Connections in a Network
https://leetcode.com/problems/critical-connections-in-a-network/
126. Word Ladder II
https://leetcode.com/problems/word-ladder-ii/
290. Word Pattern
https://leetcode.com/problems/word-pattern/
291. Word Pattern II
https://leetcode.com/problems/word-pattern-ii/

#### Number of Connected Components in an Undirected Graph

![](../static/Screen Shot 2021-06-15 at 08.07.48.png)

**Follow up**

补上union find solution

**Solution**

1. 非常标准的dfs 和 union find

   

```java
// dfs
/*
Here EE = Number of edges, VV = Number of vertices.
Time complexity: O(E + V)

Building the adjacency list will take O(E) operations, as we iterate over the list of edges once, and insert each edge into two lists.

During the DFS traversal, each vertex will only be visited once. This is because we mark each vertex as visited as soon as we see it, and then we only visit vertices that are not marked as visited. In addition, when we iterate over the edge list of each vertex, we look at each edge once. This has a total cost of O(E + V)

Space complexity:  O(E + V)

Building the adjacency list will take O(E) space. To keep track of visited vertices, an array of size O(V) is required. Also, the run-time stack for DFS will use O(E + V) space.
*/
class Solution {
    public int countComponents(int n, int[][] edges) {
        Map<Integer, List<Integer>> graph = new HashMap<> ();
        for(int i = 0; i < n; ++i) {
            graph.put(i, new ArrayList<>());
        }
        for(int[] edge : edges) {
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        boolean[] visited = new boolean[n];
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(dfs(i, graph, visited)) {
                count++;
            }    
        }
        return count;
    }
    
    private boolean dfs(int i, Map<Integer, List<Integer>> graph, boolean[] visited) {
        if(visited[i]) {
            return false;
        }
        visited[i] = true;
        for(int j : graph.get(i)) {
            dfs(j, graph, visited);
        }
        return true;
    }
}

// union find

```

