## 基本问题：

（1）DFS中递归的基本要素
（2）终止条件的选择；回溯；剪枝
（3）什么时候需要排序？
（4）如何去除重复元素？一个元素允许使用多次的情况？
（6）在图上进行DFS如何避免回到重复节点
（5）识别一个隐式图，并使用DFS
（6）在某些情况下，利用记忆化搜索进行优化

dfs 的space complexity 是longest path



# Matrix

## Making A Large Island

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be `1`.

Return *the size of the largest **island** in* `grid` *after applying this operation*.

An **island** is a 4-directionally connected group of `1`s. 

**Example 1:**

```
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

**Example 2:**

```
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

**Example 3:**

```
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
```

 **Solution**

这题没有写代码，有空回来写一下

Naive dfs will run a dfs on every 0 after we change it to 1. However, we can calculate the size of each island. For each 0, we just need to add the size of the island in its four directions. One tricky part is that we may counter the same island, so we need to mark the island with a unique id.

```java
class Solution {
    public int N = 0;
    public int largestIsland(int[][] grid) {
        N = grid.length;
        //DFS every island and give it an index of island
        int index = 3, res = 0;
        HashMap<Integer, Integer> area = new HashMap<>();
        for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y)
            if (grid[x][y] == 1) {
                area.put(index, dfs(grid, x, y, index));
                res = Math.max(res, area.get(index++));
            }

        //traverse every 0 cell and count biggest island it can conntect
        for (int x = 0; x < N; ++x) for (int y = 0; y < N; ++y)
            if (grid[x][y] == 0) {
                HashSet<Integer> seen = new HashSet<>();
                int cur = 1;
                for (Pair<Integer, Integer> p : move(x, y)) {
                    index = grid[p.getKey()][p.getValue()];
                    if (index > 1 && !seen.contains(index)) {
                        seen.add(index);
                        cur += area.get(index);
                    }
                }
                res = Math.max(res, cur);
            }
        return res;
    }

    public List <Pair<Integer, Integer>> move(int x, int y) {
        ArrayList <Pair<Integer, Integer>> res = new ArrayList<>();
        if (valid(x, y + 1)) res.add(new Pair<Integer, Integer>(x, y + 1));
        if (valid(x, y - 1)) res.add(new Pair<Integer, Integer>(x, y - 1));
        if (valid(x + 1, y)) res.add(new Pair<Integer, Integer>(x + 1, y));
        if (valid(x - 1, y)) res.add(new Pair<Integer, Integer>(x - 1, y));
        return res;
    }

    public boolean valid(int x, int y) {
        return 0 <= x && x < N && 0 <= y && y < N;
    }

    public int dfs(int[][] grid, int x, int y, int index) {
        int area = 0;
        grid[x][y] = index;
        for (Pair<Integer, Integer> p : move(x, y))
            if (grid[p.getKey()][p.getValue()] == 1)
                area += dfs(grid, p.getKey(), p.getValue(), index);
        return area + 1;
    }
}
```







# **排列组合**：



## 46 Permutations

Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.

**Example 1:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**

```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

**Example 3:**

```
Input: nums = [1]
Output: [[1]]
```

**Solution**

```java
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> output = new LinkedList<>();
        if(nums == null || nums.length == 0) {
            return output;
        }
        List<Integer> nums_lst = new ArrayList<Integer>();
        for(int num : nums) {
            nums_lst.add(num);
        }
        permuteHelper(nums_lst, output, 0);
        return output;
    }
    
    public void permuteHelper(List<Integer> nums, List<List<Integer>> output, int first) {
        int len = nums.size();
        if(first == len) {
            output.add(new ArrayList<Integer>(nums));
        }
        for(int i = first; i < len; ++i) {
            Collections.swap(nums, first, i);
            permuteHelper(nums, output, first + 1);
            Collections.swap(nums, first, i);           
        }
    }
}
```



## 47 Permutations II

Given a collection of numbers, `nums`, that might contain **duplicates**, return *all possible unique permutations **in any order**.*

**Example 1:**

```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**Example 2:**

```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Solution**

Permutations 这个系列的题目放到一起看看

```java
class Solution {

    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();

        // count the occurrence of each number
        HashMap<Integer, Integer> counter = new HashMap<>();
        for (int num : nums) {
            if (!counter.containsKey(num))
                counter.put(num, 0);
            counter.put(num, counter.get(num) + 1);
        }

        LinkedList<Integer> comb = new LinkedList<>();
        this.backtrack(comb, nums.length, counter, results);
        return results;
    }

    protected void backtrack(
            LinkedList<Integer> comb,
            Integer N,
            HashMap<Integer, Integer> counter,
            List<List<Integer>> results) {

        if (comb.size() == N) {
            // make a deep copy of the resulting permutation,
            // since the permutation would be backtracked later.
            results.add(new ArrayList<Integer>(comb));
            return;
        }

        for (Map.Entry<Integer, Integer> entry : counter.entrySet()) {
            Integer num = entry.getKey();
            Integer count = entry.getValue();
            if (count == 0)
                continue;
            // add this number into the current combination
            comb.addLast(num);
            counter.put(num, count - 1);

            // continue the exploration
            backtrack(comb, N, counter, results);

            // revert the choice for the next exploration
            comb.removeLast();
            counter.put(num, count);
        }
    }
}
```



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



# Array

## Partition to K Equal Sum Subsets

Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.

**Example 1:**

```
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

**Example 2:**

```
Input: nums = [1,2,3,4], k = 3
Output: false
```

**Solution**

**backtracking** 做的坑坑巴巴的，这个要在看看

TimeComplexity : O(k * 2^n) upper bound

Space complexity: O(n)

```java
class Solution {
    public boolean canPartitionKSubsets(int[] nums, int k) {
        // calculate total sum
        int totalSum = IntStream.of(nums).sum();
        // handle edge cases
        if(k == 0 || totalSum % k != 0) {
            return false;
        }
        return dfs(0, k, new boolean [nums.length], totalSum / k, 0, nums);
        
    }
    
    public boolean dfs(int start, int k, boolean[] visited, int target, int cur, int[] nums) {
        
        if(k == 1) {
            // 把前面的buckets都fill 完了回后，剩下的自然就成立了 
            return true;
        }
        if(cur == target) {
            // 一轮bucket填完以后要重头开始
            return dfs(0, k - 1, visited, target, 0, nums);
        }
        for(int i = start; i < nums.length; ++i) {
            if(!visited[i] && cur + nums[i] <= target) {
                visited[i] = true;
                if(dfs(i + 1, k, visited, target, cur + nums[i], nums)) {
                    return true;
                }
                visited[i] = false;
            }
        }
        return false;
    }
}

```



## Factor Combinations

Numbers can be regarded as the product of their factors.

- For example, `8 = 2 x 2 x 2 = 2 x 4`.

Given an integer `n`, return *all possible combinations of its factors*. You may return the answer in **any order**.

**Note** that the factors should be in the range `[2, n - 1]`.

**Example 1:**

```
Input: n = 1
Output: []
```

**Example 2:**

```
Input: n = 12
Output: [[2,6],[3,4],[2,2,3]]
```

**Example 3:**

```
Input: n = 37
Output: []
```

**Example 4:**

```
Input: n = 32
Output: [[2,16],[4,8],[2,2,8],[2,4,4],[2,2,2,4],[2,2,2,2,2]]
```



**Solution**

```java
class Solution {
public List<List<Integer>> getFactors(int n) {
    List<List<Integer>> res = new LinkedList<>();
    backtrack(2, n, new LinkedList<>(), res);
    return res;
}

void backtrack(int start, int n, List<Integer> list, List<List<Integer>> res) {
  // [3, 4] [4, 3] 是重复的，所以不用去看 i > sqrt(n)的那部分
    for(int i = start; i * i <= n; i++) {
        if(n % i == 0) {
            list.add(i);
            list.add(n / i);
            res.add(new LinkedList<>(list));
            list.remove(list.size() - 1);
            backtrack(i, n / i, list, res);
            list.remove(list.size() - 1);
        }
    }
}
}
```



# 

## Nested List Weight Sum

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists.

The **depth** of an integer is the number of lists that it is inside of. For example, the nested list `[1,[2,2],[[3],2],1]` has each integer's value set to its **depth**.

Return *the sum of each integer in* `nestedList` *multiplied by its **depth***.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/01/14/nestedlistweightsumex1.png)

```
Input: nestedList = [[1,1],2,[1,1]]
Output: 10
Explanation: Four 1's at depth 2, one 2 at depth 1. 1*2 + 1*2 + 2*1 + 1*2 + 1*2 = 10.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/01/14/nestedlistweightsumex2.png)

```
Input: nestedList = [1,[4,[6]]]
Output: 27
Explanation: One 1 at depth 1, one 4 at depth 2, and one 6 at depth 3. 1*1 + 4*2 + 6*3 = 27.
```

**Example 3:**

```
Input: nestedList = [0]
Output: 0
```

**Solution**

Time complexity : O(N) N is the total nested elements in the input list 

`For example, the list `[ [[[[1]]]], 2 ]` contains 44 nested lists and 22 nested integers (11 and 22)`

Space complexity : O(N)

```java
class Solution {
    public int depthSum(List<NestedInteger> nestedList) {
       return dfs(nestedList, 1);
    }
    
    private int dfs(List<NestedInteger> list, int depth) {
        int total = 0;
        for(NestedInteger nested : list) {
            if(nested.isInteger()) {
                total += nested.getInteger() * depth;
            } else {
                total += dfs(nested.getList(), depth + 1);
            }
        }
        return total;
    }
}
```

## Nested List Weight Sum II

You are given a nested list of integers `nestedList`. Each element is either an integer or a list whose elements may also be integers or other lists.

The **depth** of an integer is the number of lists that it is inside of. For example, the nested list `[1,[2,2],[[3],2],1]` has each integer's value set to its **depth**. Let `maxDepth` be the **maximum depth** of any integer.

The **weight** of an integer is `maxDepth - (the depth of the integer) + 1`.

Return *the sum of each integer in* `nestedList` *multiplied by its **weight***.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/27/nestedlistweightsumiiex1.png)

```
Input: nestedList = [[1,1],2,[1,1]]
Output: 8
Explanation: Four 1's with a weight of 1, one 2 with a weight of 2.
1*1 + 1*1 + 2*2 + 1*1 + 1*1 = 8
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/27/nestedlistweightsumiiex2.png)

```
Input: nestedList = [1,[4,[6]]]
Output: 17
Explanation: One 1 at depth 3, one 4 at depth 2, and one 6 at depth 1.
1*3 + 4*2 + 6*1 = 17
```

Solution

Find the maxDepth during dfs and record the depth for each integer in the meantime. Calculate the sum with the map

```java
class Solution {
    int maxDepth;
    public int depthSumInverse(List<NestedInteger> nestedList) {
        Map<Integer, List<Integer> > depth = new HashMap<>();
        maxDepth = 0;
        for(NestedInteger i : nestedList) {
            dfs(i, depth, 1);
        }
        int result = 0;
        for(int d : depth.keySet()) {
            for(int i : depth.get(d)) {
                result += (maxDepth - d + 1) * i;
            }
        }
        return result;
    }
    
    public void dfs(NestedInteger nested, Map<Integer, List<Integer> > depth, int cur) {
        if(nested.isInteger()) {
            maxDepth = Math.max(maxDepth, cur);
            int i = nested.getInteger();
            if(!depth.containsKey(cur)) {
                depth.put(cur, new ArrayList<>());
            }
            depth.get(cur).add(i);
            return ;
        }
        for(NestedInteger n : nested.getList()) {
            dfs(n, depth, cur + 1);
        }
    }
}
```

