# 基本问题

1. 如果复杂程度类似， 面试中尽量优先使用BFS
2. BFS主要几种场景： 层级遍历，拓扑排序，图上搜索（包括二叉树，矩阵）
3. Queue的使用技巧，BFS的终止条件？
4. 什么时候使用分层？什么时候不需要？实现的时候的区别在哪里？
5. 拓扑排序的概念？如何判断是否存在拓扑排序？是否存在唯一的拓扑排序？找到所有拓扑排序？
6. 什么时候需要使用set记录访问过的节点？（为什么二叉树上的BFS往往不需要set？）什么时候需要map记录到达过的节点距离？
   1. 无向图或者有环的图会需要set来记录访问过的节点，二叉树不会返回到以前访问过的节点所以不需要set
7. 如何在矩阵中遍历下一步的所有节点？如果每次可能走不止一步怎么办（Maze II）？
8. 为什么BFS解决的基本都是简单图（边长为1）问题？如果边长不为1，该怎么办？
9. BFS的时空复杂度估算？
10. 如何使用双向BFS进行优化？



# 二叉树

## Serialize and Deserialize Binary Tree

Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

**Clarification:** The input/output format is the same as [how LeetCode serializes a binary tree](https://leetcode.com/faq/#binary-tree). You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/09/15/serdeser.jpg)

```java
Input: root = [1,2,3,null,null,4,5]
Output: [1,2,3,null,null,4,5]
```

**Example 2:**

```java
Input: root = []
Output: []
```

**Example 3:**

```java
Input: root = [1]
Output: [1]
```

**Example 4:**

```java
Input: root = [1,2]
Output: [1,2]
```

 **Constraints:**

- The number of nodes in the tree is in the range `[0, 104]`.
- `-1000 <= Node.val <= 1000`

**Solution**

1. 本质就是tree的traversal， bfs是level， dfs是inoder， preorder，postorder
2. 难点在实现，有很多string的处理

```java
// dfs
public class Codec {
    public String rserialize(TreeNode root, String str) {
    // Recursive serialization.
    if (root == null) {
      str += "null,";
    } else {
      str += str.valueOf(root.val) + ",";
      str = rserialize(root.left, str);
      str = rserialize(root.right, str);
    }
    return str;
  }

  // Encodes a tree to a single string.
  public String serialize(TreeNode root) {
    return rserialize(root, "");
  }
    
     public TreeNode rdeserialize(List<String> l) {
    // Recursive deserialization.
    if (l.get(0).equals("null")) {
      l.remove(0);
      return null;
    }

    TreeNode root = new TreeNode(Integer.valueOf(l.get(0)));
    l.remove(0);
    root.left = rdeserialize(l);
    root.right = rdeserialize(l);

    return root;
  }

  // Decodes your encoded data to tree.
  public TreeNode deserialize(String data) {
    String[] data_array = data.split(",");
    List<String> data_list = new LinkedList<String>(Arrays.asList(data_array));
    return rdeserialize(data_list);
  }
}
// bfs code
public class Codec {
    public static final String LEVEL_DELIMITER = "@";
    public static final String VAL_DELIMITER = ",";
    public static final String NULL_VALUE = "n";
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        List<String> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if(root != null) {
          queue.add(root);
        }
        while(queue.size() > 0) {
          int currentSize = queue.size();
          List<String> level = new ArrayList<>();
          for(int i = 0; i < currentSize; ++i) {
              TreeNode node = queue.poll();
              if(node == null) {
                level.add(NULL_VALUE);   
              } else {
                level.add(String.valueOf(node.val));
                queue.add(node.left);
                queue.add(node.right);
              }
          }
          result.add(String.join(VAL_DELIMITER, level));
        }
        return String.join(LEVEL_DELIMITER, result);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data == null || data.isEmpty()) {
            return null;
        }
        System.out.println(data);
        String[] levels = data.split(LEVEL_DELIMITER);
        Queue<TreeNode> queue = new LinkedList<>();
        TreeNode head = new TreeNode(Integer.parseInt(levels[0]));
        queue.add(head);
        for(int i = 1; i < levels.length; ++i) {
            String[] vals = levels[i].split(VAL_DELIMITER);
            for(int j = 0; j < vals.length;) {
                TreeNode currentNode = queue.poll();
                if(NULL_VALUE.equals(vals[j])) {
                    currentNode.left = null;
                } else {
                    currentNode.left = new TreeNode(Integer.parseInt(vals[j]));
                    queue.add(currentNode.left);
                }
                 if(NULL_VALUE.equals(vals[j + 1])) {
                    currentNode.right = null;
                } else {
                    currentNode.right = new TreeNode(Integer.parseInt(vals[j + 1]));
                    queue.add(currentNode.right);
                }
                j += 2;
            }
        }
        return head;
    }
}
```





## Binary Tree Level Order Traversal

Given the `root` of a binary tree, return *the level order traversal of its nodes' values*. (i.e., from left to right, level by level).

 **Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Solution**

非常标准的bfs解法

```java
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        List<TreeNode> currentLevel = new ArrayList<>();
        if(root == null) {
            return result;
        }
   			// 也可以使用queue
        currentLevel.add(root);
        while(currentLevel.size() > 0) {
            List<TreeNode> nextLevel = new ArrayList<>();
            List<Integer> levelValue = new ArrayList<>();
            for(TreeNode node : currentLevel) {
                levelValue.add(node.val);
                if(node.left != null) nextLevel.add(node.left);
                if(node.right != null) nextLevel.add(node.right);
            }
            currentLevel = nextLevel;
            result.add(levelValue);
        }
        return result;
    }

}
```



## Binary Tree Level Order Traversal II

Given the `root` of a binary tree, return *the bottom-up level order traversal of its nodes' values*. (i.e., from left to right, level by level from leaf to root).

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

 **Solution**

1. 只要最后对list进行一次reverse就好了，和level traversal 没有区别

```java
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        Queue<TreeNode> queue = new LinkedList<>();
        if(root != null) {
          queue.add(root);
        }
        while(queue.size() > 0) {
          int currentSize = queue.size();
          LinkedList<Integer> level = new LinkedList<>();
          for(int i = 0; i < currentSize; ++i) {
              TreeNode node = queue.poll();
              level.add(node.val);
              if(node.left != null) queue.add(node.left);
              if(node.right != null) queue.add(node.right);
          }
          result.add(level);
        }
      // reverse list 
        Collections.reverse(result);
        return result;
    }
}
```



## Find Bottom Left Tree Value

Given the `root` of a binary tree, return the leftmost value in the last row of the tree.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2020/12/14/tree1.jpg)

```java
Input: root = [2,1,3]
Output: 1
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2020/12/14/tree2.jpg)

```java
Input: root = [1,2,3,4,null,5,6,null,null,7]
Output: 7
```

**Solution**

本质就是level traversal

```java
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        if(root != null) {
          queue.add(root);
        }
        int result = 0;
        while(queue.size() > 0) {
          int currentSize = queue.size();
          result = queue.peek().val;
          for(int i = 0; i < currentSize; ++i) {
              TreeNode node = queue.poll();
              if(node.left != null) queue.add(node.left);
              if(node.right != null) queue.add(node.right);
          }
        }
        return result;
    }
}
```





## Binary Tree Zigzag Level Order Traversal

Given the `root` of a binary tree, return *the zigzag level order traversal of its nodes' values*. (i.e., from left to right, then right to left for the next level and alternate between).

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
```

**Example 2:**

```
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Solution**

和leval order 没有区别，只需要在每次记录value的时候按不同的顺序来就行

```java
class Solution {
  public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
      List<List<Integer>> result = new ArrayList<>();
      Queue<TreeNode> queue = new LinkedList<>();
      if(root != null) {
          queue.add(root);
      }
      boolean isOrderLeft = true;
      while(queue.size() > 0) {
          int currentSize = queue.size();
          LinkedList<Integer> level = new LinkedList<>();
          for(int i = 0; i < currentSize; ++i) {
              TreeNode node = queue.poll();
              if(isOrderLeft) {
                  level.addLast(node.val);
              } else {
                  level.addFirst(node.val);
              }
              if(node.left != null) queue.add(node.left);
              if(node.right != null) queue.add(node.right);
          }
          isOrderLeft = !isOrderLeft;
          result.add(level);
      }
      return result;
  }
}
```



# 拓扑排序

## Course Schedule

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

**Example 1:**

```java
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```java
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

**Constraints:**

- `1 <= numCourses <= 105`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- All the pairs prerequisites[i] are **unique**.

**Solution**

1. 本质是检查有向图是否有环， 可以用topological sort和dfs来做
2. topological sort solution
   1. build graph and indegree(number of nodes pointing to it)
   2. put all the nodes with 0 indegree in queue as the starter level
   3. for each node in the queue, poll it and minus one indegree for all the nodes it pointing to and put them in queue for as the next level
   4. Continue untill the queue is empty. If there is still nodes with indegree larger than 0, then there is a circle.

```java
// topological sort
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



## Course Schedule II

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return *the ordering of courses you should take to finish all courses*. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

 

**Example 1:**

```
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
```

**Example 2:**

```
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
```

**Example 3:**

```
Input: numCourses = 1, prerequisites = []
Output: [0]
```

 **Constraints:**

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- `ai != bi`
- All the pairs `[ai, bi]` are **distinct**.

**Solution**

1. 和course schedule 本质没有区别，只要返回一个sort 顺序

```java
class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
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
            int[] result = new int[numCourses];
            for(int i = 0; i < courseOrder.size(); ++i) {
                result[i] = courseOrder.get(i);
            }
            return result;
        } else {
            return new int[0];
        }
}
}
```

## Alien Dictionary

There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

You are given a list of strings `words` from the alien language's dictionary, where the strings in `words` are **sorted lexicographically** by the rules of this new language.

Return *a string of the unique letters in the new alien language sorted in **lexicographically increasing order** by the new language's rules. If there is no solution, return* `""`*. If there are multiple solutions, return **any of them***.

A string `s` is **lexicographically smaller** than a string `t` if at the first letter where they differ, the letter in `s` comes before the letter in `t` in the alien language. If the first `min(s.length, t.length)` letters are the same, then `s` is smaller if and only if `s.length < t.length`.

**Example 1:**

```java
Input: words = ["wrt","wrf","er","ett","rftt"]
Output: "wertf"
```

**Example 2:**

```java
Input: words = ["z","x"]
Output: "zx"
```

**Example 3:**

```java
Input: words = ["z","x","z"]
Output: ""
Explanation: The order is invalid, so return "".
```

**Constraints:**

- `1 <= words.length <= 100`
- `1 <= words[i].length <= 100`
- `words[i]` consists of only lowercase English letters.

**Solution**

1. 本质就是topological sort, 难点在构建graph

```java
class Solution {
    public String alienOrder(String[] words) {
       String result = "";
        if(words.length < 1) {
            return "";
        }
        // 1. Convert characters to a graph: Adjacency lists
        Map<Character, Set<Character>> graph = new HashMap<>();
        for(int i = 0; i < words.length; ++i) {
            for(char c : words[i].toCharArray()) {
                if(!graph.containsKey(c)) {
                    graph.put(c, new HashSet<>());
                }
            }
            if(i + 1 < words.length) {
                boolean isPrefixExist = true;
                for(int j = 0; j < Math.min(words[i].length(), words[i + 1].length()); ++j) {
                    char preChar = words[i].charAt(j);
                    char nextChar = words[i + 1].charAt(j);
                    if(preChar != nextChar) {
                        isPrefixExist = false;
                        graph.get(preChar).add(nextChar);
                        break;
                    }
                }
                // handle corner case ["abc","ab"]
                if(isPrefixExist && words[i].length() > words[i + 1].length()) {
                    return "";
                } 
            }
        }
        // 2. count indegree of each node
        Map<Character, Integer> indegree = new HashMap<>();
        LinkedList<Character> zeroDegreeNodes = new LinkedList<> ();
        for(char c : graph.keySet()) {
            indegree.put(c, indegree.getOrDefault(c, 0));
            for(char n : graph.get(c)) {
                indegree.put(n, indegree.getOrDefault( n, 0) + 1);
            }
        }
        for(char c : indegree.keySet()) {
            if(indegree.get(c) == 0) {
                zeroDegreeNodes.add(c);
            }
        }
        // 3. topoloogical sorting
        while(zeroDegreeNodes.size() != 0) {
            char current = zeroDegreeNodes.pollFirst();
            result = result + current;
            for(char n : graph.get(current)) {
                indegree.put(n, indegree.get(n) - 1);
                if(indegree.get(n) == 0) {
                    zeroDegreeNodes.add(n);
                }
            }
        }
         return result.length() == indegree.keySet().size() ? result : "";
    }
}
```

# 矩阵

## Number of Islands

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

```
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**

```
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

**Solution**

经典题目，本质是找到图中有几个不联通的部分. 可以用bfs， dfs和union find， 

- Time complexity : O(M \times N)*O*(*M*×*N*) where M*M* is the number of rows and N*N* is the number of columns.

```java
// dfs
class Solution {
     boolean[][] visited;
    int rows;
    int cols;
  // 矩阵类型的题目的小trick，来表达上下左右四个方向
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
   public int numIslands(char[][] grid) {
       rows = grid.length;
       cols = grid[0].length;
       int result = 0;
       visited = new boolean[rows][cols];
       for(int i = 0; i < rows; ++i) {
           for(int j = 0; j < cols; ++j) {
               if(dfs(grid, i, j)) {
                   result += 1;
               }
           }
       }
       return result;
   }

   public boolean dfs(char[][] grid, int i, int j) {
       if(i >= rows || i < 0 || j >= cols || j < 0 || visited[i][j]) {
           return false;
       }
       visited[i][j] = true;
       if(grid[i][j] == '0') {
           return false;
       }
       for(int[] direction : directions) {
           dfs(grid, i + direction[0], j + direction[1]);
       }
       return true;
   }
}

// bfs
class Solution {
     boolean[][] visited;
    int rows;
    int cols;
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
   public int numIslands(char[][] grid) {
       rows = grid.length;
       cols = grid[0].length;
       int result = 0;
       visited = new boolean[rows][cols];
       for(int i = 0; i < rows; ++i) {
           for(int j = 0; j < cols; ++j) {
               if(bfs(grid, i, j)) {
                   result += 1;
               }
           }
       }
       return result;
   }

   public boolean bfs(char[][] grid, int i, int j) {
       if(i >= rows || i < 0 || j >= cols || j < 0 || visited[i][j] || grid[i][j] == '0') {
           return false;
       }
       Queue<int[]> queue = new LinkedList<>();
       queue.add(new int[]{i, j});
       while(queue.size() > 0) {
           int[] node = queue.poll();
           int row = node[0];
           int col = node[1];
           if(row < rows && row >= 0 && col < cols && col >= 0 && !visited[row][col] && grid[row][col] == '1') {
               
               for(int[] direction : directions) {
                   queue.add(new int[]{row + direction[0], col + direction[1]});
               }
               visited[row][col] = true;
           }   
           
       }
       return true;
   }
}
```





## The Maze

There is a ball in a `maze` with empty spaces (represented as `0`) and walls (represented as `1`). The ball can go through the empty spaces by rolling **up, down, left or right**, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the `m x n` `maze`, the ball's `start` position and the `destination`, where `start = [startrow, startcol]` and `destination = [destinationrow, destinationcol]`, return `true` if the ball can stop at the destination, otherwise return `false`.

You may assume that **the borders of the maze are all walls** (see examples).

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg)

```
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: true
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/31/maze1-2-grid.jpg)

```
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: false
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
```

**Example 3:**

```
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: false
```

**Solution**

1. 走迷宫的题目，唯一trick的地方就是不是一步一步走，而是走到头为止
2. Time complexity : O(mn)*O*(*m**n*). Complete traversal of maze will be done in the worst case. Here, m*m* and n*n* refers to the number of rows and coloumns of the maze.
3. Space complexity : O(mn)*O*(*m**n*). visited*v**i**s**i**t**e**d* array of size m*n*m*∗*n* is used and queue*q**u**e**u**e* size can grow upto m*n*m*∗*n* in worst case.

```java
class Solution {
    boolean[][] visited;
    int rows;
    int cols;
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        rows = maze.length;
        cols = maze[0].length;
        visited = new boolean[rows][cols];
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start);
        while(queue.size() > 0) {
            int[] pos = queue.poll();
            int row = pos[0];
            int col = pos[1];
            if(row == destination[0] && col == destination[1]) {
                return true;
            }
            if(!visited[row][col]) {
                for(int[] direction : directions) {
                    // rolling the ball
                    int nRow = row;
                    int nCol = col;
                    while(nRow + direction[0] < rows && nRow + direction[0] >= 0 && nCol + direction[1] < cols && nCol + direction[1] >= 0 
                            && maze[nRow + direction[0]][nCol + direction[1]] == 0) {
                        nRow += direction[0];
                        nCol += direction[1];
                    }
                    queue.add(new int[]{nRow, nCol});

                }
            }
            visited[row][col] = true;
        }
        return false;
    }
}
```



## The Maze II

There is a ball in a `maze` with empty spaces (represented as `0`) and walls (represented as `1`). The ball can go through the empty spaces by rolling **up, down, left or right**, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.

Given the `m x n` `maze`, the ball's `start` position and the `destination`, where `start = [startrow, startcol]` and `destination = [destinationrow, destinationcol]`, return *the shortest **distance** for the ball to stop at the destination*. If the ball cannot stop at `destination`, return `-1`.

The **distance** is the number of **empty spaces** traveled by the ball from the start position (excluded) to the destination (included).

You may assume that **the borders of the maze are all walls** (see examples).

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/31/maze1-1-grid.jpg)

```
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [4,4]
Output: 12
Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
The length of the path is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/03/31/maze1-2-grid.jpg)

```
Input: maze = [[0,0,1,0,0],[0,0,0,0,0],[0,0,0,1,0],[1,1,0,1,1],[0,0,0,0,0]], start = [0,4], destination = [3,2]
Output: -1
Explanation: There is no way for the ball to stop at the destination. Notice that you can pass through the destination but you cannot stop there.
```

**Example 3:**

```
Input: maze = [[0,0,0,0,0],[1,1,0,0,1],[0,0,0,0,0],[0,1,0,0,1],[0,1,0,0,0]], start = [4,3], destination = [0,1]
Output: -1
```

**Solution**

1. 不能用visited来判断是否要继续这个点，而是用一个distance array来查看是不是到这个点的最小距离， 如果这次来的距离更小就需要放进queue里继续检查

```java
class Solution {
    int rows;
    int cols;
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
    public int shortestDistance(int[][] maze, int[] start, int[] destination) {       
        rows = maze.length;
        cols = maze[0].length;
        int[][] distance = new int[rows][cols];
      // dont forget inizilation 
        for(int[] row : distance) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }
        distance[start[0]][start[1]] = 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(start);
        while(queue.size() > 0) {
            int[] pos = queue.poll();
            for(int[] dir : directions) {
                int nRow = pos[0];
                int nCol = pos[1];
                int count = 0;
                while(nRow + dir[0] < rows && nRow + dir[0] >= 0 && nCol + dir[1] < cols && nCol + dir[1] >= 0 
                            && maze[nRow + dir[0]][nCol + dir[1]] == 0) {
                        nRow += dir[0];
                        nCol += dir[1];
                        count += 1;
                    }
                if(distance[pos[0]][pos[1]] + count < distance[nRow][nCol]) {
                    distance[nRow][nCol] = distance[pos[0]][pos[1]] + count;
                    queue.add(new int[]{nRow, nCol});
                }
            }
        }
        return distance[destination[0]][destination[1]] == Integer.MAX_VALUE ? -1 : distance[destination[0]][destination[1]];
    }
}
```



## 01 Matrix

Given an `m x n` binary matrix `mat`, return *the distance of the nearest* `0` *for each cell*.

The distance between two adjacent cells is `1`.

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg)

```java
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
```

**Example 2:**

![img](https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg)

```java
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

**Solution**

1. 这道题可以用bfs 和 dp 的方法来解决
2. dp
   1. 每个点其实只要找到上下左右四个方向的最短到0的距离
   2. 我们可以走两遍矩阵，第一遍检查left 和top， 第二遍检查botton 和right
3. bfs 
   1. 先初始化distance， 然后从0s开始做bfs
   2. 如果发现新的点的距离更小，才把这个点放进queue里

```java
// dp
class Solution {
  public int[][] updateMatrix(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;
        int[][] dis = new int[rows][cols];
        for(int[] row : dis) {
          // 这里需要减1，要不然后面会溢出
            Arrays.fill(row, Integer.MAX_VALUE - 1);
        }
        // top to bottom and left to right
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(mat[i][j] == 0) {
                    dis[i][j] = 0;
                } else {
                    if(i - 1 >= 0) {
                        dis[i][j] = Math.min(dis[i - 1][j] + 1, dis[i][j]);
                    }
                    if(j - 1 >= 0) {
                        dis[i][j] = Math.min(dis[i][j - 1] + 1, dis[i][j]);
                    }
                }
            }
        }

        // bottom to top and right to left
        for(int i = rows - 1; i >= 0; --i) {
            for(int j = cols - 1; j >= 0; --j) {
                if(i + 1 < rows) {
                    dis[i][j] = Math.min(dis[i + 1][j] + 1, dis[i][j]);
                }
                if(j + 1 < cols) {
                    dis[i][j] = Math.min(dis[i][j + 1] + 1, dis[i][j]);
                }
            }
        }
        return dis;
    }
}

// bfs
class Solution {
     public int[][] updateMatrix(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;
        int[][] dis = new int[rows][cols];
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Queue<int[]> queue = new LinkedList<>();
        for(int i = 0; i < rows; ++i) {
            for(int j = 0; j < cols; ++j) {
                if(mat[i][j] == 0) {
                    queue.add(new int[]{i, j});
                    dis[i][j] = 0;
                } else {
                    dis[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        while (!queue.isEmpty()) {
            int[] pos = queue.poll();
            for(int[] dir : dirs) {
                int nRow = pos[0] + dir[0];
                int nCol = pos[1] + dir[1];
                if(nRow >= 0 && nCol >=0 && nRow < rows && nCol < cols 
                        && dis[pos[0]][pos[1]] + 1 < dis[nRow][nCol]) {
                    queue.add(new int[]{nRow, nCol});
                    dis[nRow][nCol] = dis[pos[0]][pos[1]] + 1;
                }
            }
        }
        
        return dis;
    }
}
```



## Flood Fill

An image is represented by an `m x n` integer grid `image` where `image[i][j]` represents the pixel value of the image.

You are also given three integers `sr`, `sc`, and `newColor`. You should perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill**, consider the starting pixel, plus any pixels connected **4-directionally** to the starting pixel of the same color as the starting pixel, plus any pixels connected **4-directionally** to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with `newColor`.

Return *the modified image after performing the flood fill*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg)

```java
Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: From the center of the image with position (sr, sc) = (1, 1) (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected to the starting pixel.
```

**Example 2:**

```java
Input: image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, newColor = 2
Output: [[2,2,2],[2,2,2]]
```

**Solution**

```java
```























1. Rotting Oranges
   https://leetcode.com/problems/rotting-oranges/
2. Number of Islands II
   https://leetcode.com/problems/number-of-islands-ii/
3. Sliding Puzzle
   https://leetcode.com/problems/sliding-puzzle/

Lint-573. Build Post Office II
https://www.lintcode.com/problem/build-post-office-ii/description

Lint-598. Zombie in Matrix
https://www.lintcode.com/problem/zombie-in-matrix/description

Lint-611. Knight Shortest Path
https://www.lintcode.com/problem/knight-shortest-path/description

Lint-794. Sliding Puzzle II
https://www.lintcode.com/problem/sliding-puzzle-ii/description



图:

133. Clone Graph
https://leetcode.com/problems/clone-graph/

127. Word Ladder
https://leetcode.com/problems/word-ladder/

261. Graph Valid Tree
https://leetcode.com/problems/graph-valid-tree/

841. Keys and Rooms
https://leetcode.com/problems/keys-and-rooms/

323. Number of Connected Components in an Undirected Graph
https://leetcode.com/problems/nu ... n-undirected-graph/

1306. Jump Game III
https://leetcode.com/problems/jump-game-iii/

Lint-531. Six Degree
https://www.lintcode.com/problem/six-degrees/description

Lint-618. Search Graph Nodes
https://www.lintcode.com/problem/search-graph-nodes/description

Lint-624. Remove Substrings
https://www.lintcode.com/problem/remove-substrings/description