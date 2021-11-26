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



# A* Search

有空看一看



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
// dfs
class Solution {
    List<List<Integer>> levels = new ArrayList<List<Integer>>();

    public void helper(TreeNode node, int level) {
        // start the current level
        if (levels.size() == level)
            levels.add(new ArrayList<Integer>());

         // fulfil the current level
         levels.get(level).add(node.val);

         // process child nodes for the next level
         if (node.left != null)
            helper(node.left, level + 1);
         if (node.right != null)
            helper(node.right, level + 1);
    }
    
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) return levels;
        helper(root, 0);
        return levels;
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



------

## 199 Binary Tree Right Side View

Given the `root` of a binary tree, imagine yourself standing on the **right side** of it, return *the values of the nodes you can see ordered from top to bottom*.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/02/14/tree.jpg)

```
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
```

**Example 2:**

```
Input: root = [1,null,3]
Output: [1,3]
```

**Example 3:**

```
Input: root = []
Output: []
```

**Solution**

level traversal 然后把最右边的点放入result中就好了

```Java
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if(root == null) {
            return result;
        }
        
        Queue<TreeNode> level = new LinkedList<>();
        level.add(root);
        while(level.size() != 0) {
            int size = level.size();
            result.add(level.peek().val);
            for(int i = 0; i < size; ++i) {
                TreeNode cur = level.remove();
                if(cur.right != null) level.add(cur.right);
                if(cur.left != null) level.add(cur.left);
            }
        }
        return result;
    }
}
```



## 863 All Nodes Distance K in Binary Tree

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return *an array of the values of all nodes that have a distance* `k` *from the target node.*

You can return the answer in **any order**.

 

**Example 1:**

![img](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/06/28/sketch0.png)

```
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
```

**Example 2:**

```
Input: root = [1], target = 1, k = 3
Output: []
```

**Solution**

这题如果把二叉树当成无向图，那么就是一个简单的bfs，所以我们需要把node到parent这层关系给补上

```java
class Solution {
    Map<TreeNode, TreeNode> parent;
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        parent = new HashMap();
        dfs(root, null);

        Queue<TreeNode> queue = new LinkedList();
        queue.add(null);
        queue.add(target);

        Set<TreeNode> seen = new HashSet();
        seen.add(target);
        seen.add(null);

        int dist = 0;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == null) {
                if (dist == K) {
                    List<Integer> ans = new ArrayList();
                    for (TreeNode n: queue)
                        ans.add(n.val);
                    return ans;
                }
                queue.offer(null);
                dist++;
            } else {
                if (!seen.contains(node.left)) {
                    seen.add(node.left);
                    queue.offer(node.left);
                }
                if (!seen.contains(node.right)) {
                    seen.add(node.right);
                    queue.offer(node.right);
                }
                TreeNode par = parent.get(node);
                if (!seen.contains(par)) {
                    seen.add(par);
                    queue.offer(par);
                }
            }
        }

        return new ArrayList<Integer>();
    }

    public void dfs(TreeNode node, TreeNode par) {
        if (node != null) {
            parent.put(node, par);
            dfs(node.left, node);
            dfs(node.right, node);
        }
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

## 1743 Restore the Array From Adjacent Pairs

There is an integer array `nums` that consists of `n` **unique** elements, but you have forgotten it. However, you do remember every pair of adjacent elements in `nums`.

You are given a 2D integer array `adjacentPairs` of size `n - 1` where each `adjacentPairs[i] = [ui, vi]` indicates that the elements `ui` and `vi` are adjacent in `nums`.

It is guaranteed that every adjacent pair of elements `nums[i]` and `nums[i+1]` will exist in `adjacentPairs`, either as `[nums[i], nums[i+1]]` or `[nums[i+1], nums[i]]`. The pairs can appear **in any order**.

Return *the original array* `nums`*. If there are multiple solutions, return **any of them***.

**Example 1:**

```
Input: adjacentPairs = [[2,1],[3,4],[3,2]]
Output: [1,2,3,4]
Explanation: This array has all its adjacent pairs in adjacentPairs.
Notice that adjacentPairs[i] may not be in left-to-right order.
```

**Example 2:**

```
Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
Output: [-2,4,1,-3]
Explanation: There can be negative numbers.
Another solution is [-3,1,4,-2], which would also be accepted.
```

**Example 3:**

```
Input: adjacentPairs = [[100000,-100000]]
Output: [100000,-100000]
```

**Solution**

```java
class Solution {
    public int[] restoreArray(int[][] adjacentPairs) {
        
        //length of restoredArray would be input length+1
        int[] restoredArray = new int[adjacentPairs.length+1];
     
        Map<Integer, List<Integer>> graph = new HashMap<Integer, List<Integer>>();
        
        // 1. Build graph of number -> [adjacent numbers]
        for(int i= 0; i < adjacentPairs.length; i++){
             addToGraph(graph, adjacentPairs[i][0], adjacentPairs[i][1]);
             addToGraph(graph, adjacentPairs[i][1], adjacentPairs[i][0]);
         }
        
         // 2. Find first number with only one adjacent number i.e. in-degree = 1. That wil be our start.
		 // eg. get -3 or -2 as our start. 
        //There would always be two elements which satisfy this conditon & starting from either would suffice. 
         int start = 0;
         for(int key : graph.keySet()){
             if(graph.get(key).size()==1){
                 start = key;
                 break;
            }
         }
        Set<Integer> seenSet = new HashSet<Integer>();
        List<Integer> answerList = new ArrayList<Integer>();
        dfs(start,graph,answerList,seenSet);

        for(int i=0;i<answerList.size();i++){
            restoredArray[i] = answerList.get(i);
        }
        return restoredArray;
    }
    
    /****** Template DFS Code *******/
    private void dfs(int start,Map<Integer, List<Integer>> graph,List<Integer> answerList,Set<Integer> seenSet){
        answerList.add(start);
        seenSet.add(start);
        List<Integer> neighbors = graph.get(start);
        //loop over adjacents like you do in BFS, here adjacents are fetched from the constructed graph.
        for(Integer curr : neighbors){
            if(!seenSet.contains(curr)){
                 dfs(curr,graph,answerList,seenSet);
            }
        } 
    }
	
    //Utility function which simply builds graph of [numbers] -> [list of adjacent numbers]
    	// eg. [[4,-2],[1,4],[-3,1]]
		// map will be  4 ->[-2,1], 1->[-3,4], -2->[4], -3->[1]
	  private void addToGraph(Map<Integer, List<Integer>> graph, int key, int value) {
		     if(graph.containsKey(key)){
                 graph.get(key).add(value);
             }else{
                 List<Integer> temp = new ArrayList<Integer>();
                 temp.add(value);
                 graph.put(key, temp);
             }  
	  }
    
    //One can use this BFS function instead of DFS function as well.
    
     /****** Template BFS Code *******/
    /**
    private void bfs(int start,Map<Integer, List<Integer>> graph,int[] restoredArray){
         Queue<Integer> bfsQueue = new LinkedList<Integer>();
         Set<Integer> seenSet = new HashSet<Integer>();
         bfsQueue.add(start);
         seenSet.add(start);   

         int index=0;

         while(!bfsQueue.isEmpty()){

             int restoredValue = bfsQueue.poll();
             List<Integer> neighbors = graph.get(restoredValue);
             restoredArray[index++] = restoredValue;
            
             //loop over adjacents like you do in BFS, here adjacenets are fetched from the constructed graph.
             for(Integer curr : neighbors){
                 if(!seenSet.contains(curr)){
                    bfsQueue.offer(curr);
                    seenSet.add(curr);
                 }
             }
         }
    }
    */
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







## 1263 Minimum Moves to Move a Box to Their Target Location

Storekeeper is a game in which the player pushes boxes around in a warehouse trying to get them to target locations.

The game is represented by a `grid` of size `m x n`, where each element is a wall, floor, or a box.

Your task is move the box `'B'` to the target position `'T'` under the following rules:

- Player is represented by character `'S'` and can move up, down, left, right in the `grid` if it is a floor (empy cell).
- Floor is represented by character `'.'` that means free cell to walk.
- Wall is represented by character `'#'` that means obstacle (impossible to walk there). 
- There is only one box `'B'` and one target cell `'T'` in the `grid`.
- The box can be moved to an adjacent free cell by standing next to the box and then moving in the direction of the box. This is a **push**.
- The player cannot walk through the box.

Return the minimum number of **pushes** to move the box to the target. If there is no way to reach the target, return `-1`.

**Example 1:**

**![img](https://assets.leetcode.com/uploads/2019/11/06/sample_1_1620.png)**

```
Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#",".","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 3
Explanation: We return only the number of times the box is pushed.
```

**Example 2:**

```
Input: grid = [["#","#","#","#","#","#"],
               ["#","T","#","#","#","#"],
               ["#",".",".","B",".","#"],
               ["#","#","#","#",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: -1
```

**Example 3:**

```
Input: grid = [["#","#","#","#","#","#"],
               ["#","T",".",".","#","#"],
               ["#",".","#","B",".","#"],
               ["#",".",".",".",".","#"],
               ["#",".",".",".","S","#"],
               ["#","#","#","#","#","#"]]
Output: 5
Explanation:  push the box down, left, left, up and up.
```

**Example 4:**

```
Input: grid = [["#","#","#","#","#","#","#"],
               ["#","S","#",".","B","T","#"],
               ["#","#","#","#","#","#","#"]]
Output: -1
```

**Solution**

we need 2 levels of bfs for this problem. If we dont have a player, it is just a simple bfs. We can push the box in the four directions. With a player in the game, we just need to check for each direction, is the player able to reach the position in order to push the box in that direction.

Time complexity : O(m^4 * n^4)

Space Complexity: O(m*n)

这道题的难点在代码量很大,有空写一遍练一下

```java
class Solution {
  
    char[][] grid;
    int m, n;
    int[][] dir = new int[][]{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up
    public int minPushBox(char[][] grid) {
        this.grid = grid;
        m = grid.length; 
        n = grid[0].length;
        int step = 0;
        boolean[][][] visited = new boolean[m][n][4]; // considering 4 directons
        
        Queue<int[]> boxQ = new LinkedList<>();
        Queue<int[]> playerQ = new LinkedList<>();
        int[] boxLoc=new int[2], targetLoc=new int[2] , playerLoc=new int[2];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'B') boxLoc = new int[]{i, j};
                if (grid[i][j] == 'T') targetLoc = new int[]{i, j};
                if (grid[i][j] == 'S') playerLoc = new int[]{i, j};
            }
        }
        boxQ.offer(new int[]{boxLoc[0], boxLoc[1]});
        playerQ.offer(new int[]{playerLoc[0], playerLoc[1]});
        
        while (!boxQ.isEmpty()) { 
            for (int i = 0, l = boxQ.size(); i < l; i++) { //as we care about all directions, it should be like this.--> it's related to calculating 'step'
                int[] currBoxLoc = boxQ.poll();
                int[] currPlayerLoc = playerQ.poll();
                if (currBoxLoc[0] == targetLoc[0] && currBoxLoc[1] == targetLoc[1]) return step; // If box arrives at the target, it returns 'step'
                for (int j = 0; j < dir.length; j++) { // Checking all directions
                    if (visited[currBoxLoc[0]][currBoxLoc[1]][j]) continue;
                    int[] d = dir[j];
                    int r0 = currBoxLoc[0] + d[0], c0 = currBoxLoc[1] + d[1];  // where player stands, need a space to push
                    if (r0 < 0 || r0 >= m || c0 < 0 || c0 >= n || grid[r0][c0] == '#') continue; //if no space, ignore(/continue)
                    int r = currBoxLoc[0] - d[0], c = currBoxLoc[1] - d[1];  // the box location after pushed
                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '#') continue; // if no space for box, ignore(/continue)
                    if (!reachable(r0, c0, currBoxLoc, currPlayerLoc)) continue; // Check if the player can reach (r0, c0). if not, continue
                    visited[currBoxLoc[0]][currBoxLoc[1]][j] = true; // After pushed, the player is at 'currBoxLoc'.
                    boxQ.offer(new int[]{r,c}); // update queues accordingly.
                    playerQ.offer(new int[]{currBoxLoc[0],currBoxLoc[1]}); 
                }
            }
            step++;
        }
        return -1;
    }
    
    private boolean reachable(int i, int j, int[] boxLoc, int[] playerLoc) {
        // (i,j) is a location where the play will push the box.
        Queue<int[]> q = new LinkedList<>();
        q.offer(playerLoc);
        boolean[][] visited = new boolean[m][n];
        visited[boxLoc[0]][boxLoc[1]] = true; //player cannot go through the spot where the box is located at.
        while (!q.isEmpty()) {
            int[] currPlLoc = q.poll();
            if (currPlLoc[0] == i && currPlLoc[1] == j) return true;
            for (int[] d : dir) {
                int r = currPlLoc[0] + d[0], c = currPlLoc[1] + d[1];   // player's location after moving
                if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c] || grid[r][c] == '#') continue; // check if player can move to (r,c)
                visited[r][c] = true; // if possible, check it visited.
                q.offer(new int[]{r, c});
            }
        }
        return false;
    }
}
```



## 317 Shortest Distance from All Buildings

You are given an `m x n` grid `grid` of values `0`, `1`, or `2`, where:

- each `0` marks **an empty land** that you can pass by freely,
- each `1` marks **a building** that you cannot pass through, and
- each `2` marks **an obstacle** that you cannot pass through.

You want to build a house on an empty land that reaches all buildings in the **shortest total travel** distance. You can only move up, down, left, and right.

Return *the **shortest travel distance** for such a house*. If it is not possible to build such a house according to the above rules, return `-1`.

The **total travel distance** is the sum of the distances between the houses of the friends and the meeting point.

The distance is calculated using [Manhattan Distance](http://en.wikipedia.org/wiki/Taxicab_geometry), where `distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|`.

 

**Example 1:**

![img](https://assets.leetcode.com/uploads/2021/03/14/buildings-grid.jpg)

```
Input: grid = [[1,0,2,0,1],[0,0,0,0,0],[0,0,1,0,0]]
Output: 7
Explanation: Given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2).
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal.
So return 7.
```

**Example 2:**

```
Input: grid = [[1,0]]
Output: 1
```

**Example 3:**

```
Input: grid = [[1]]
Output: -1
```



**Solution**

```java
// 对每个house做bfs，然后我们记录两个matrixs， canReac记录这个点有多少个house能来，dist记录所有的house到这里的距离，然后我们只要找到canReach 等于total house，dist最小的就行了
class Solution {
    private int[] rowDir = {1, -1, 0, 0};
    private int[] colDir = {0, 0, 1, -1};
    
    public int shortestDistance(int[][] grid) {
        if (grid == null || grid.length == 0) return -1;
        int rows = grid.length, cols = grid[0].length;
        int[][] canReach = new int[rows][cols];
        int[][] dist = new int[rows][cols];
        
        int totalBuildings = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    totalBuildings++;
                    if (!bfs(grid, i, j, dist, canReach)) return -1;
                }
            }
        }
        
        int minDis = Integer.MAX_VALUE;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (canReach[i][j] == totalBuildings &&
                   dist[i][j] < minDis) {
                    minDis = dist[i][j];
                }
            }
        }
        
        return minDis == Integer.MAX_VALUE ? -1 : minDis;
    }
    
    private boolean bfs(int[][] grid, int row, int col, int[][] dist, int[][] canReach) {
        int rows = grid.length, cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{row, col});
        visited[row][col] = true;
        
        int d = 0;
        while (!q.isEmpty()) {
            int size = q.size();
            d++;
            for (int i = 0; i < size; i++) {
                int[] cur = q.poll();
                int r = cur[0];
                int c = cur[1];
                for (int k = 0; k < 4; k++) {
                    int rr = rowDir[k] + r;
                    int cc = colDir[k] + c;
                    if (!isValid(grid, rr, cc, visited)) continue;                   
                    if (grid[rr][cc] == 0) {
                        dist[rr][cc] += d;
                        canReach[rr][cc]++;
                        q.offer(new int[]{rr, cc});                        
                    }
                    visited[rr][cc] = true;
                }
            }
        }
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    private boolean isValid(int[][] grid, int rr, int cc, boolean[][] visited) {
        if (rr > grid.length - 1 ||
           rr < 0 || cc < 0 || cc > grid[0].length - 1) return false;
        if (visited[rr][cc]) return false;
        if(grid[rr][cc] == 2) return false;
        
        return true;
    }
}
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



# 图

133. Clone Graph
     https://leetcode.com/problems/clone-graph/

     

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

## 815 Bus Routes

You are given an array `routes` representing bus routes where `routes[i]` is a bus route that the `ith` bus repeats forever.

- For example, if `routes[0] = [1, 5, 7]`, this means that the `0th` bus travels in the sequence `1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ...` forever.

You will start at the bus stop `source` (You are not on any bus initially), and you want to go to the bus stop `target`. You can travel between bus stops by buses only.

Return *the least number of buses you must take to travel from* `source` *to* `target`. Return `-1` if it is not possible.

 

**Example 1:**

```
Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
```

**Example 2:**

```
Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
```

**Solution**

The first part loop on routes and record stop to routes mapping in `to_route`.
The second part is general bfs. Take a stop from queue and find all connected route.
The hashset `seen` record all visited stops and we won't check a stop for twice.
We can also use a hashset to record all visited routes, or just clear a route after visit.

时间复杂度： 将bus当作这个里面的一个node，那么bfs就是O(N + N^2) = O(N^2)  edges最多有N^2条



```java
class Solution {
    public int numBusesToDestination(int[][] routes, int source, int target) {
        int n = routes.length;
        HashMap<Integer, HashSet<Integer>> to_routes = new HashMap<>();
        for(int i = 0; i < routes.length; ++i) {
            for(int j : routes[i]) {
                if(!to_routes.containsKey(j)) {
                    to_routes.put(j, new HashSet<Integer>());
                }
                to_routes.get(j).add(i);
            }
        }
        Queue<int[]> bfs = new ArrayDeque();
        bfs.offer(new int[]{source, 0});
        HashSet<Integer> seen = new HashSet<>();
        seen.add(source);
      // 这个是optimazation，如果这个routes所有的点都见过了，就不用在检查里面的点了
        boolean[] seen_routes = new boolean[n];
        while(!bfs.isEmpty()) {
            int stop = bfs.peek()[0], bus = bfs.peek()[1];
            bfs.poll();
            // source == stop?
            if(stop == target) return bus;
            for(int i : to_routes.get(stop)) {
                if(seen_routes[i]) {
                    continue;
                }
                for(int j : routes[i]) {
                    if(!seen.contains(j)) {
                        seen.add(j);
                        bfs.offer(new int[]{j, bus + 1});
                    } 
                }
                seen_routes[i] = true;
            }
        }
        return -1;
    }
}
```







## 127 Word Ladder

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *the **number of words** in the **shortest transformation sequence** from* `beginWord` *to* `endWord`*, or* `0` *if no such sequence exists.*

 

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

 **Solution**

这道题唯一的秘密就是如何build adjacent list， map的key 来放pattern

```
hot -> *ot, h*t, ho*
*ot -> hot, dot
```



Time Complexity: O*(*M2xN)

Space Complexity: O*(*M2×N) For every words, we need to store M times, the space for each word will be M2

```java
public class Solution {

public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    int L = beginWord.length();
    // build adjacent list
    Map<String, List<String> > allComboDict = new HashMap<>();
    for(String word : wordList) {
        for(int i = 0; i < L; i++) {
            String newWord = word.substring(0, i) + '*' + word.substring(i + 1);
            List<String> transformations = allComboDict.getOrDefault(newWord, new ArrayList<>());
            transformations.add(word);
            allComboDict.put(newWord, transformations);
        }
    }
    
    Queue<String> q = new LinkedList<>();
    q.add(beginWord);
    
    Set<String> visited = new HashSet<>();
    int level = 0;
    visited.add(beginWord);
    while(!q.isEmpty()) {
        int size = q.size();
        level++;
        for(int i = 0; i < size; ++i) {
            String cur = q.poll();
            for(int j = 0; j < L; ++j) {
                // word pattern
                String newWord = cur.substring(0, j) + '*' + cur.substring(j + 1, L);             
                for(String adjacentWord : allComboDict.getOrDefault(newWord, new ArrayList<>())) {
                    if (adjacentWord.equals(endWord)) {
                        return level + 1;
                     }
                    
                    if(!visited.contains(adjacentWord)) {
                        visited.add(adjacentWord);
                        q.add(adjacentWord);
                    }
                }
                
            }
        }
    }
    return 0;
    
}
}
```

## 126 Word Ladder II

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s1 -> s2 -> ... -> sk` such that:

- Every adjacent pair of words differs by a single letter.
- Every `si` for `1 <= i <= k` is in `wordList`. Note that `beginWord` does not need to be in `wordList`.
- `sk == endWord`

Given two words, `beginWord` and `endWord`, and a dictionary `wordList`, return *all the **shortest transformation sequences** from* `beginWord` *to* `endWord`*, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words* `[beginWord, s1, s2, ..., sk]`.

 

**Example 1:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

**Example 2:**

```
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

**Solution**

先用bfs来build 一个graph， graph只需要从beginword 到 endword的一个directed graph 就行了，其余的东西都可以省略掉，然后做一个dfs把所有的path都找出来就行了

晚上练一下写一下

```Java
class Solution {
public List<List<String>> findLadders(String start, String end, List<String> wordList) {
   HashSet<String> dict = new HashSet<String>(wordList);
   List<List<String>> res = new ArrayList<List<String>>();         
   HashMap<String, ArrayList<String>> nodeNeighbors = new HashMap<String, ArrayList<String>>();// Neighbors for every node
   HashMap<String, Integer> distance = new HashMap<String, Integer>();// Distance of every node from the start node
   ArrayList<String> solution = new ArrayList<String>();

   dict.add(start);          
   bfs(start, end, dict, nodeNeighbors, distance);                 
   dfs(start, end, dict, nodeNeighbors, distance, solution, res);   
   return res;
}

// BFS: Trace every node's distance from the start node (level by level).
private void bfs(String start, String end, Set<String> dict, HashMap<String, ArrayList<String>> nodeNeighbors, HashMap<String, Integer> distance) {
  for (String str : dict)
      nodeNeighbors.put(str, new ArrayList<String>());

  Queue<String> queue = new LinkedList<String>();
  queue.offer(start);
  distance.put(start, 0);

  while (!queue.isEmpty()) {
      int count = queue.size();
      boolean foundEnd = false;
      for (int i = 0; i < count; i++) {
          String cur = queue.poll();
          int curDistance = distance.get(cur);                
          ArrayList<String> neighbors = getNeighbors(cur, dict);

          for (String neighbor : neighbors) {
              nodeNeighbors.get(cur).add(neighbor);
              if (!distance.containsKey(neighbor)) {// Check if visited
                  distance.put(neighbor, curDistance + 1);
                  if (end.equals(neighbor))// Found the shortest path
                      foundEnd = true;
                  else
                      queue.offer(neighbor);
                  }
              }
          }

          if (foundEnd)
              break;
      }
  }

// Find all next level nodes.    
private ArrayList<String> getNeighbors(String node, Set<String> dict) {
  ArrayList<String> res = new ArrayList<String>();
  char chs[] = node.toCharArray();

  for (char ch ='a'; ch <= 'z'; ch++) {
      for (int i = 0; i < chs.length; i++) {
          if (chs[i] == ch) continue;
          char old_ch = chs[i];
          chs[i] = ch;
          if (dict.contains(String.valueOf(chs))) {
              res.add(String.valueOf(chs));
          }
          chs[i] = old_ch;
      }

  }
  return res;
}

// DFS: output all paths with the shortest distance.
private void dfs(String cur, String end, Set<String> dict, HashMap<String, ArrayList<String>> nodeNeighbors, HashMap<String, Integer> distance, ArrayList<String> solution, List<List<String>> res) {
    solution.add(cur);
    if (end.equals(cur)) {
       res.add(new ArrayList<String>(solution));
    } else {
       for (String next : nodeNeighbors.get(cur)) {            
            if (distance.get(next) == distance.get(cur) + 1) {
                 dfs(next, end, dict, nodeNeighbors, distance, solution, res);
            }
        }
    }           
   solution.remove(solution.size() - 1);
}
}
```

